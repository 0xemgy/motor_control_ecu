add_custom_target(
    doxygen ALL
    COMMAND
        env PROJECT_NAME=${CMAKE_PROJECT_NAME}
        env INPUT=${CMAKE_CURRENT_SOURCE_DIR}
        env EXCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/bsw/vendor/cmsis/
        env OUTPUT_DIRECTORY=${CMAKE_CURRENT_BINARY_DIR}/doxygen
        ${CMAKE_SOURCE_DIR}/tools/doxygen/doxygen.exe
        ${CMAKE_SOURCE_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running doxygen"
)
