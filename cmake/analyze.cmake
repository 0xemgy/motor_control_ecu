cmake_minimum_required(VERSION 3.26.1)

# Analyze all ----------------------------------------------------------------------------------------------------------

add_custom_target(
    analyze ALL
    DEPENDS analyze_clang_format analyze_clang_tidy analyze_cppcheck analyze_doxygen analyze_lizard
)

# clang-format ---------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_clang_format
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/clang_format/clang-format.exe
    --dry-run
    --Werror
    ${ABSOLUTE_C_SOURCES}
  COMMENT "Running clang-format check"
)

# clang-tidy------------------------------------------------------------------------------------------------------------

add_custom_target(
    analyze_clang_tidy
    COMMAND
        ${CMAKE_SOURCE_DIR}/tools/clang_tidy/clang-tidy.exe
        -p=${CMAKE_BINARY_DIR}
        ${ABSOLUTE_C_SOURCES}
    COMMENT "Running Clang-Tidy"
)

# cppcheck -------------------------------------------------------------------------------------------------------------

add_custom_target(
    analyze_cppcheck
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/cppcheck/cppcheck.exe --platform=win64
    # Check settings
    --addon=./../tools/cppcheck/misra.json --check-level=exhaustive --enable --std=c99
    # Suppressions to avoid false positives
    --suppress=missingIncludeSystem # Avoid false positives on <stdbool.h> and <stdint.h> includes
    # Suppressions for utility code
    --suppress=unusedFunction:*util* #
    --suppress=misra-c2012-19.2:*util* # The union keyword should not be used
    --suppress=misra-c2012-2.3:*util* # A project should not contain unused type declarations
    --suppress=misra-c2012-2.4:*util* # A project should not contain unused tag declarations
    --suppress=misra-c2012-2.5:*util* # A project should not contain unused macro declarations
    # Suppression for code
    --suppress=misra-c2012-8.9:* # An object should be defined at block scope if its identifier only appears in a single function
    # Output format compatible to vscode PROBLEMS view
    --template=gcc
    # Inlude paths and source files (absolute paths needed for proper vscode PROBLEMS view file hyperlinks)
    ${ABSOLUTE_INCLUDES}
    ${ABSOLUTE_C_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running cppcheck static code analysis"
)

# doxygen --------------------------------------------------------------------------------------------------------------

add_custom_target(
    analyze_doxygen
    COMMAND
        env PROJECT_NAME=${CMAKE_PROJECT_NAME}
        env INPUT=${CMAKE_CURRENT_SOURCE_DIR}
        env EXCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/bsw/vendor/
        env OUTPUT_DIRECTORY=${CMAKE_CURRENT_BINARY_DIR}/doxygen
        ${CMAKE_SOURCE_DIR}/tools/doxygen/doxygen.exe
        ${CMAKE_SOURCE_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running doxygen"
)

# lizard ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_lizard
  COMMAND "${CMAKE_SOURCE_DIR}/tools/lizard/lizard.exe"
          --working_threads 4
          --warnings_only
          --modified
          --CCN 15
          --length 200
          --arguments 5
          -Tnloc=1000
          -Ttoken_count=500
          ${ABSOLUTE_C_SOURCES}

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running Lizard code complexity analysis"
)
