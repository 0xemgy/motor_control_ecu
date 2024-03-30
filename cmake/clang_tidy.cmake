add_custom_target(
    clang_tidy ALL
    COMMAND
        ${CMAKE_SOURCE_DIR}/tools/clang_tidy/clang-tidy.exe
        -p=${CMAKE_BINARY_DIR}
        ${ABSOLUTE_C_SOURCES}
    COMMENT "Running Clang-Tidy"
)
