add_custom_target(
  cppcheck ALL
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/cppcheck/cppcheck.exe --platform=win64
    # Check settings
    --addon=./../tools/cppcheck/misra.json --check-level=exhaustive --enable=all --std=c99
    # Suppressions to avoid false positives
    --suppress=missingIncludeSystem # Avoid false positives on <stdbool.h> and <stdint.h> includes
    # Suppressions
    --suppress=unusedFunction:*util* #
    --suppress=misra-c2012-19.2:*util* # The union keyword should not be used
    --suppress=misra-c2012-2.3:*util* # A project should not contain unused type declarations
    --suppress=misra-c2012-2.4:*util* # A project should not contain unused tag declarations
    --suppress=misra-c2012-2.5:*util* # A project should not contain unused macro declarations
    # Output format compatible to vscode PROBLEMS view
    --template=gcc
    # Inlude paths and source files (absolute paths needed for proper vscode PROBLEMS view file hyperlinks)
    ${ABSOLUTE_INCLUDES}
    ${ABSOLUTE_C_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running cppcheck static code analysis"
)
