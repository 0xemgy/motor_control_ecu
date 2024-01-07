cmake_minimum_required(VERSION 3.26.1)

# Source files and Include Directories----------------------------------------------------------------------------------

set(SOURCES
    bsw/main.c
    bsw/startup.s
    bsw/interrupt_vector_table.s
    bsw/util/util.c
    bsw/util/util.h)

set(INCLUDES
          bsw
          bsw/cmsis
          bsw/config
          bsw/util)

# Executable Settings --------------------------------------------------------------------------------------------------

set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(EXECUTABLE "app")
add_executable(${EXECUTABLE} ${SOURCES})
set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Include Directories --------------------------------------------------------------------------------------------------

target_include_directories(
  ${EXECUTABLE}
  PRIVATE ${INCLUDES})

# Compiler Options -----------------------------------------------------------------------------------------------------

target_compile_options(
  ${EXECUTABLE}
  PRIVATE # Target Configuration
          -mcpu=cortex-m4           # Specify the target CPU
          -mfloat-abi=hard          # Use hardware floating-point unit
          -mfpu=fpv4-sp-d16         # Specify the floating-point unit type
          -mthumb                   # Generate Thumb-2 instructions

          # Language Standard
          -std=c99                  # Specify the C language standard (C99 in this case)

          # Optimization
          -O3                       # Enable aggressive code optimization

          # Debugging Information
          -g3                       # Include maximum debugging information

          # Freestanding Environment
          -ffreestanding            # Indicate a freestanding environment (no standard library)
          -nostdlib                 # Do not use the standard system library
          -nostartfiles             # Do not use the standard system startup files

          # Warnings
          -fno-common               # Treats multiple definitions of global variables as an error
          # -fno-strict-aliasing      # Disable strict aliasing optimization
          -pedantic                 # Warn about non-standard constructs
          -Wall                     # Enable common warning messages
          -Wcast-qual               # Warns about inappropriate type qualifiers in pointer casts
          -Wconversion              # Warn about implicit conversions that may change the value
          -Wdouble-promotion        # Warn about implicit double to float promotion
          -Werror                   # Treat warnings as errors
          -Wextra                   # Enable additional warning messages
          -Wfloat-equal             # Warn about floating-point equality comparisons
          -Wformat                  # Enables warnings about format string issues
          # -Winit-self               # Warn about uninitialized variables initialized with themselves
          -Wmissing-declarations    # Warns if a global function is used without being declared
          -Wmissing-prototypes      # Warns about missing function prototypes
          -Wparentheses             # Warn about questionable use of parentheses
          -Wredundant-decls         # Warn about redundant declarations
          -Wreturn-type             # Warn about missing return types
          -Wshadow                  # Warn when a local variable shadows another variable
          # -Wstrict-aliasing=2       # Enable strict aliasing warnings at level 2
          -Wstrict-overflow         # Warns about assumptions made by the compiler related to overflow
          -Wswitch-default          # Warn about missing default cases in switch statements
          -Wuninitialized           # Warn about the use of uninitialized variables
          -Wunused                  # Warn about unused variables, functions, or parameters

          # Linker Flags
          -fdata-sections           # Place each data item in its own section
          -ffunction-sections       # Place each function in its own section
          # -specs=nano.specs         # Use Newlib Nano
          # -Wl,--gc-sections         # Remove unused sections during linking
          # -Wl,-Map=output.map       # Generate a map file for memory usage analysis

          # Build Configuration Specific Symbols
          $<$<CONFIG:Release>:-DNDEBUG>
          )

# Linker Options -------------------------------------------------------------------------------------------------------

target_link_options(
  ${EXECUTABLE}
  PRIVATE
  # Target Configuration
  -mcpu=cortex-m4           # Specify the target CPU
  -mfloat-abi=hard          # Use hardware floating-point unit
  -mfpu=fpv4-sp-d16         # Specify the floating-point unit type
  -mthumb                   # Generate Thumb-2 instructions

  -specs=nano.specs                                               # Use Newlib Nano
  -static                                                         # Requests static linking of libraries
  -T${CMAKE_CURRENT_SOURCE_DIR}/memory.ld                         # Specifies the linker script for memory layout
  -Wl,--gc-sections                                               # Enables garbage collection of unused sections
  -Wl,--print-memory-usage                                        # Prints memory usage information after linking
  -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map,--cref # Generates a map file with cross-reference information
  )

# Post Build Commands---------------------------------------------------------------------------------------------------

# Print executable size
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_SIZE_UTIL} ${PROJECT_NAME}.elf)

# Create hex file
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
  COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)

# Clean Command --------------------------------------------------------------------------------------------------------

# Clean bin, hex and map files (cmake deletes only the elf file by default)
set_target_properties(
  ${EXECUTABLE}
  PROPERTIES ADDITIONAL_CLEAN_FILES
             "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin;${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex;${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map")
