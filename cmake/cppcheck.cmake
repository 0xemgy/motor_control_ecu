# Get absolute paths to all source files for proper vscode PROBLEMS view file hyperlinks
foreach(source ${SOURCES})
  get_filename_component(abs_source ${source} ABSOLUTE)
  list(APPEND ABSOLUTE_SOURCES ${abs_source})
endforeach()

# Get absolute paths to all include folders for proper vscode PROBLEMS view file hyperlinks
foreach(include ${INCLUDES})
  get_filename_component(abs_include ${include} ABSOLUTE)
  list(APPEND ABSOLUTE_INCLUDES -I${abs_include}) # -I on each folder necessary for cppcheck to find each folder
endforeach()

add_custom_target(
  cppcheck ALL
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/cppcheck/cppcheck.exe --platform=win64
    # Check settings
    --addon=./../tools/cppcheck/misra.json --check-level=exhaustive --enable=all --std=c99
    # Suppressions to avoid false positives
    --suppress=*:*/*.s # Ignore assembler files (they can not be checked by this tool)
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
    ${ABSOLUTE_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running cppcheck static code analysis"
)
