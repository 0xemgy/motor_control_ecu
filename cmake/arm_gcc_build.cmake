# Executable Settings --------------------------------------------------------------------------------------------------

set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(EXECUTABLE "app")
add_executable(${EXECUTABLE} ${SOURCES})
target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDES})
set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Compiler Options -----------------------------------------------------------------------------------------------------

target_compile_options(
  ${EXECUTABLE}
  PRIVATE
  # cmake-format: off

  # Target Configuration
  -mcpu=cortex-m4               # Specify the target CPU
  -mfloat-abi=hard              # Use hardware floating-point unit
  -mfpu=fpv4-sp-d16             # Specify the floating-point unit type
  -mthumb                       # Generate Thumb-2 instructions

  # Language Standard
  -std=c99                      # Specify the C language standard (C99 in this case)

  # Optimization
  -O3                           # Enable aggressive code optimization
  -fdata-sections               # Place each data item in its own section
  -ffunction-sections           # Place each function in its own section

  # Debugging Information
  -g3                           # Include maximum debugging information

  # Freestanding Environment
  -ffreestanding                # Indicate a freestanding environment (no standard library)
  -nostdlib                     # Do not use the standard system library
  -nostartfiles                 # Do not use the standard system startup files

  # Warnings
  -fno-common                   # Treats multiple definitions of global variables as an error
  -pedantic                     # Warn about non-standard constructs
  -Wall                         # Enable common warning messages
  -Wcast-qual                   # Warn about inappropriate type qualifiers in pointer casts
  -Wconversion                  # Warn about implicit conversions that may change the value
  -Wdouble-promotion            # Warn about implicit double to float promotion
  -Werror                       # Treat warnings as errors
  -Wextra                       # Enable additional warning messages
  -Wfloat-equal                 # Warn about floating-point equality comparisons
  -Wformat                      # Enables warnings about format string issues
  -Wmissing-declarations        # Warn if a global function is used without being declared
  -Wmissing-include-dirs        # Warn if user supplied include directory does not exist
  -Wmissing-prototypes          # Warn about missing function prototypes
  -Wparentheses                 # Warn about questionable use of parentheses
  -Wredundant-decls             # Warn about redundant declarations
  -Wreturn-type                 # Warn about missing return types
  -Wshadow                      # Warn when a local variable shadows another variable
  -Wstrict-overflow             # Warn about assumptions made by the compiler related to overflow
  -Wswitch-default              # Warn about missing default cases in switch statements
  -Wuninitialized               # Warn about the use of uninitialized variables
  -Wunused                      # Warn about unused variables, functions, or parameters

  # Standard Library
  --specs=nano.specs             # Use Newlib Nano

  # Preprocessor
  $<$<CONFIG:Release>:-DNDEBUG> # Define symbol NDEBUG for release build

  # cmake-format: on
)

# Linker Options -------------------------------------------------------------------------------------------------------

target_link_options(
  ${EXECUTABLE}
  PRIVATE
  # cmake-format: off

  # Target Configuration
  -mcpu=cortex-m4                                                 # Specify the target CPU
  -mfloat-abi=hard                                                # Use hardware floating-point unit
  -mfpu=fpv4-sp-d16                                               # Specify the floating-point unit type
  -mthumb                                                         # Generate Thumb-2 instructions

  # General
  -static                                                         # Requests static linking of libraries
  -T${CMAKE_CURRENT_SOURCE_DIR}/memory.ld                         # Specifies the linker script for memory layout
  -Wl,--gc-sections                                               # Enables garbage collection of unused sections
  -Wl,--print-memory-usage                                        # Prints memory usage information after linking
  -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map,--cref # Generates a map file with cross-reference information

  # Standard Library
  --specs=nano.specs                                               # Use Newlib Nano

  # cmake-format: on
)

# Version File Generation ----------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/version_file_generator.cmake)

# Post Build Commands---------------------------------------------------------------------------------------------------

# Print executable size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_SIZE_UTIL} ${PROJECT_NAME}.elf)

# Create bin and hex files
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
  COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)

# Clean Command --------------------------------------------------------------------------------------------------------

# Clean bin, hex and map files (cmake deletes only the elf file by default)
set_target_properties(
  ${EXECUTABLE}
  PROPERTIES
    ADDITIONAL_CLEAN_FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin;${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex;${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
)
