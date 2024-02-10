add_custom_target(
    lizard ALL
    COMMAND ${CMAKE_SOURCE_DIR}/tools/lizard/lizard.exe ${SOURCES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running Lizard code complexity analysis"
)
