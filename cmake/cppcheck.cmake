add_custom_target(
    cppcheck COMMAND
    ${CMAKE_SOURCE_DIR}/tools/cppcheck/cppcheck.exe
        --platform=win64
        --enable=all
        --addon=./../misra.json
        # –template=gcc
        --suppressions-list=./../cppcheck-suppressions.txt
        # --check-level=exhaustive
        -I${INCLUDES}
        ${SOURCES}

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running cppcheck static code analysis"
)
