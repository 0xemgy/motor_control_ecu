add_custom_target(
  clang_format ALL
  COMMAND
    ${CMAKE_SOURCE_DIR}/tools/clang_format/clang-format.exe
    --dry-run
    --Werror
    ${ABSOLUTE_C_SOURCES}
  COMMENT "Running clang-format check"
)
