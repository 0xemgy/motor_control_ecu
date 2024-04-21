cmake_minimum_required(VERSION 3.26.1)

# Run All Analyzers ----------------------------------------------------------------------------------------------------

add_custom_target(
    analyze_all
    DEPENDS analyze_clang_format analyze_clang_tidy analyze_cppcheck analyze_doxygen analyze_lizard
    COMMENT "Running all analyzers"
)

# clang-format ---------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_clang_format
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/clang_format/clang-format.exe
      --dry-run
      --Werror
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running clang-format code formatting analysis"
)

# clang-tidy------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_clang_tidy
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/clang_tidy/clang-tidy.exe
      -p=${CMAKE_BINARY_DIR}
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running clang-tidy static code analysis"
)

# cppcheck -------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_cppcheck
  # ${CMAKE_COMMAND} -E env PATH=c:/toolchain/python/v3.12.3-embed-amd64-cust1/
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/cppcheck/cppcheck.exe
      -j 4
      --platform=win64

      # Check settings
      --addon=misra.json        # Run MISRA-C-2012 checks
      --check-level=exhaustive  # Set exhaustive check level
      --enable=all              # Enable all available checks
      --disable=unusedFunction  # The function 'function name' is never used
      --std=c99                 # Specify C99 standard
      --inline-suppr            # Enable inline suppressions
      --template=gcc            # Use GCC template for reporting

      # Suppressions for utility code
      --suppress=misra-c2012-19.2:*util*  # The union keyword should not be used
      --suppress=misra-c2012-2.3:*util*   # A project should not contain unused type declarations
      --suppress=misra-c2012-2.4:*util*   # A project should not contain unused tag declarations
      --suppress=misra-c2012-2.5:*util*   # A project should not contain unused macro declarations

      # Suppressions for entire code base
      --suppress=missingIncludeSystem     # Avoid false positives on <stdbool.h> and <stdint.h> includes
      --suppress=misra-c2012-8.9:*        # An object should be defined at block scope if its identifier only appears in a single function

      # Inlude paths and source files
      ${ABSOLUTE_INCLUDES}
      ${ABSOLUTE_SYSTEM_INCLUDES}
      ${ABSOLUTE_C_SOURCES}

  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running cppcheck static code analysis"
)

# doxygen --------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_doxygen
  COMMAND
    env PROJECT_NAME=${CMAKE_PROJECT_NAME}
    env DOT_PATH=${CMAKE_SOURCE_DIR}/tools/graphviz/bin
    env INPUT=${CMAKE_CURRENT_SOURCE_DIR}
    env EXCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/bsw/vendor/
    env OUTPUT_DIRECTORY=${CMAKE_CURRENT_BINARY_DIR}/doxygen
    ${CMAKE_SOURCE_DIR}/tools/doxygen/doxygen.exe
      ${CMAKE_SOURCE_DIR}/Doxyfile

  COMMENT "Running doxygen code commenting analysis"
)

# iwyu -----------------------------------------------------------------------------------------------------------------

# TODO add iwyu

# lizard ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_lizard
  COMMAND
    "${CMAKE_SOURCE_DIR}/tools/python/Scripts/lizard.exe"
      --working_threads 4
      --warnings_only
      --modified
      --CCN 15
      --length 200
      --arguments 5
      -Tnloc=1000
      -Ttoken_count=500
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running Lizard code complexity analysis"
)
