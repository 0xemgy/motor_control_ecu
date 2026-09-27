add_library(unity STATIC
    unity.c
)

target_include_directories(unity
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(unity
    PRIVATE
    UNITY_OUTPUT_FOR_VSCODE
)
