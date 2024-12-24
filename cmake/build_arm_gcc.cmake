cmake_minimum_required(VERSION 3.26.1)

# CMake Files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/build_options_common.cmake)

# Executable Settings --------------------------------------------------------------------------------------------------

set(EXECUTABLE "build")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(OUTPUT_NAME_UNSIGNED ${PROJECT_NAME}_unsigned)
set(OUTPUT_NAME_SIGNED ${PROJECT_NAME})
set(OUTPUT_NAME_DETAILED ${PROJECT_NAME}_v${PROJECT_VERSION}_${CMAKE_BUILD_TYPE})

add_executable(${EXECUTABLE} ${C_SOURCES} ${ASM_SOURCES})
target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDES})
target_include_directories(${EXECUTABLE} SYSTEM PRIVATE ${SYSTEM_INCLUDES})
set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${OUTPUT_NAME_UNSIGNED})

# Compiler Options -----------------------------------------------------------------------------------------------------

target_compile_options(
  ${EXECUTABLE}
  PRIVATE
  # cmake-format: off

  ${COMMON_COMPILE_OPTIONS}     # Options common to HW target and unit test build

  # Target Configuration
  -mcpu=cortex-m4               # Specify the target CPU
  -mfloat-abi=soft              # Do not use hardware floating-point unit
  -mfpu=fpv4-sp-d16             # Specify the floating-point unit type
  -mthumb                       # Generate Thumb-2 instructions

  # Optimization
  -O3                           # Enable aggressive code optimization
  -fdata-sections               # Place each data item in its own section
  -ffunction-sections           # Place each function in its own section

  # Freestanding Environment
  -ffreestanding                # Indicate a freestanding environment (no standard library) -> memcpy etc. is not used implicitly by the compiler
  -nostdlib                     # Do not use the standard system library
  -nostartfiles                 # Do not use the standard system startup files
  -nostdinc                     # Do not search through system include path

  # Standard Library
  --specs=nano.specs            # Use Newlib Nano

  # Stack Usage Output
  -fstack-usage

  # cmake-format: on
)

# Linker Options -------------------------------------------------------------------------------------------------------

target_link_options(
  ${EXECUTABLE}
  PRIVATE
  # cmake-format: off

  ${COMMON_LINK_OPTIONS}     # Options common to HW target and unit test build

  # Target Configuration
  -mcpu=${MICROPROCESSOR_TYPE}                                    # Specify the target CPU

  -mfloat-abi=soft                                                # Do not use hardware floating-point unit
  -mfpu=fpv4-sp-d16                                               # Specify the floating-point unit type
  -mthumb                                                         # Generate Thumb-2 instructions

  # General
  -static                                                         # Requests static linking of libraries
  -T${CMAKE_CURRENT_SOURCE_DIR}/memory.ld                         # Specifies the linker script for memory layout
  -Wl,--gc-sections                                               # Enables garbage collection of unused sections
  -Wl,--print-memory-usage                                        # Prints memory usage information after linking
  -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME_SIGNED}.map,--cref # Generates a map file with cross-reference information

  # Standard Library
  --specs=nano.specs                                              # Use Newlib Nano

  # cmake-format: on
)

# Post Build Commands---------------------------------------------------------------------------------------------------

# Create signed elf file
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"
    --modify GIT_PYTHON_GIT_EXECUTABLE=set:"${TOOLS_GIT}"

    python ${TOOLS_CODE_SIGNER}
      --elf_path ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME_UNSIGNED}.elf
      --project_name ${PROJECT_NAME}
      --sw_version ${PROJECT_VERSION}
      --build_type ${CMAKE_BUILD_TYPE}

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Print executable size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_SIZE_UTIL} ${OUTPUT_NAME_SIGNED}.elf)

# Create elf with details in name
add_custom_command(
  TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${OUTPUT_NAME_SIGNED}.elf ${OUTPUT_NAME_DETAILED}.elf
)

# Create hex file
add_custom_command(
  TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O ihex ${OUTPUT_NAME_SIGNED}.elf ${OUTPUT_NAME_SIGNED}.hex
)

# Create hex with details in name
add_custom_command(
  TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${OUTPUT_NAME_SIGNED}.hex ${OUTPUT_NAME_DETAILED}.hex
)

# Clean Command --------------------------------------------------------------------------------------------------------

# Clean signed elf, hex and map files (cmake deletes only the output elf file by default)
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_UNSIGNED}.elf
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_SIGNED}.elf
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_DETAILED}.elf
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_SIGNED}.hex
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_DETAILED}.hex
  PROPERTY ADDITIONAL_CLEAN_FILES ${OUTPUT_NAME_SIGNED}.map
)

# Clean doxygen folder
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES doxygen
)

# Clean report files
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES analysis_report.html
  PROPERTY ADDITIONAL_CLEAN_FILES loc_report.json
  PROPERTY ADDITIONAL_CLEAN_FILES memory_report.json
  PROPERTY ADDITIONAL_CLEAN_FILES metrics_report.csv
  PROPERTY ADDITIONAL_CLEAN_FILES naming_report.json
)
