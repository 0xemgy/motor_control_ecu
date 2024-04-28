cmake_minimum_required(VERSION 3.26.1)

include(${CMAKE_SOURCE_DIR}/cmake/tools.cmake)

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
  ${TOOLS_CLANG_FORMAT}
      --dry-run
      --Werror
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running clang-format code formatting analysis"
)

# clang-tidy------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_clang_tidy
  COMMAND
    ${TOOLS_CLANG_TIDY}
      -p=${CMAKE_BINARY_DIR}
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running clang-tidy static code analysis"
)

# cppcheck -------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_cppcheck
  ${CMAKE_COMMAND}
    -E env
      --modify PATH=set:"${TOOLS_PYTHON_PATH}"
      --modify PYTHONPATH=set:"${TOOLS_CPPCHECK_PATH}/addons"

    ${TOOLS_CPPCHECK}
      --platform=win64

      # Check settings
      --addon=misra.json        # Run MISRA-C-2012 checks
      --check-level=exhaustive  # Set exhaustive check level
      --enable=all              # Enable all available checks
      --std=c99                 # Specify C99 standard
      --inline-suppr            # Enable inline suppressions
      --template=gcc            # Use GCC template for reporting

      --suppress=checkersReport # Active checkers: x/y (use --checkers-report=<filename> to see details)

      # Suppressions for utility code
      --suppress=misra-c2012-19.2:*util*    # The union keyword should not be used
      --suppress=misra-c2012-2.3:*util*     # A project should not contain unused type declarations
      --suppress=misra-c2012-2.4:*util*     # A project should not contain unused tag declarations
      --suppress=misra-c2012-2.5:*util*     # A project should not contain unused macro declarations
      --suppress=misra-c2012-8.7:*util*     # Functions and objects should not be defined with external linkage if they
                                            # are referenced in only one translation unit
      --suppress=unusedFunction:*util*      # The function 'function name' is never used
      --suppress=unusedStructMember:*util*  # struct member 'struct member name' is never used

       # Suppressions for version
       --suppress=unusedStructMember:*version*  # struct member 'struct member name' is never used
       --suppress=misra-c2012-8.4:*version*     # A compatible declaration shall be visible when an object or function
                                                # with external linkage is defined

      # Suppressions for entire code base
      --suppress=missingIncludeSystem     # Avoid false positives on <stdbool.h> and <stdint.h> includes
      --suppress=misra-c2012-8.9:*        # An object should be defined at block scope if its identifier only appears in
                                          # a single function

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
    ${TOOLS_DOXYGEN}
      ${CMAKE_SOURCE_DIR}/Doxyfile

  COMMENT "Running doxygen code commenting analysis"
)

# iwyu -----------------------------------------------------------------------------------------------------------------

# TODO add iwyu

# lizard ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_lizard
  ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python -m lizard
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
