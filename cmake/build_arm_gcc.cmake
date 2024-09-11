cmake_minimum_required(VERSION 3.26.1)

# CMake Files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/build_options_common.cmake)

# Executable Settings --------------------------------------------------------------------------------------------------

set(EXECUTABLE "build")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")

add_executable(${EXECUTABLE} ${C_SOURCES} ${ASM_SOURCES})
target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDES})
target_include_directories(${EXECUTABLE} SYSTEM PRIVATE ${SYSTEM_INCLUDES})
set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

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
  -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map,--cref # Generates a map file with cross-reference information

  # Standard Library
  --specs=nano.specs                                              # Use Newlib Nano

  # cmake-format: on
)

# Post Build Commands---------------------------------------------------------------------------------------------------

# Print executable size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_SIZE_UTIL} ${PROJECT_NAME}.elf)

# Create bin file
add_custom_command(
  TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)

# Create hex file
add_custom_command(
  TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)

# Clean Command --------------------------------------------------------------------------------------------------------

# Clean bin, hex and map files (cmake deletes only the elf file by default)
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES ${PROJECT_NAME}.bin
  PROPERTY ADDITIONAL_CLEAN_FILES ${PROJECT_NAME}.hex
  PROPERTY ADDITIONAL_CLEAN_FILES ${PROJECT_NAME}.map
)

# Clean doxygen folder
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES doxygen
)
