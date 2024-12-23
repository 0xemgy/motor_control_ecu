cmake_minimum_required(VERSION 3.26.1)

# Compiler Options -----------------------------------------------------------------------------------------------------

set(COMMON_COMPILE_OPTIONS
  # Language Standard
  -std=c99                      # Specify the C language standard (C99 in this case)

  # Debugging Information
  -g3                           # Include maximum debugging information
  -gdwarf-2                     # Use DWARF version 2 for debugging information format

  # Warnings
  -fno-common                   # Treats multiple definitions of global variables as an error
  -pedantic                     # Warn about non-standard constructs
  -Wall                         # Enable common warning messages
  -Wcast-qual                   # Warn about inappropriate type qualifiers in pointer casts
  -Wconversion                  # Warn about implicit conversions that may change the value
  -Wdouble-promotion            # Warn about implicit double to float promotion
  # -Werror                       # Treat warnings as errors # TODO reenable when going to into development phase
  -Wextra                       # Enable additional warning messages
  # -Wfloat-equal                 # Warn about floating-point equality comparisons
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

  # Preprocessor
  $<$<CONFIG:release>:-DNDEBUG> # Define symbol NDEBUG for release build

  # cmake-format: on
)

# Linker Options -------------------------------------------------------------------------------------------------------

set(COMMON_LINK_OPTIONS
  # cmake-format: off

  # cmake-format: on
)
