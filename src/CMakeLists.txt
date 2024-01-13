cmake_minimum_required(VERSION 3.26.1)

# Source files and Include Directories----------------------------------------------------------------------------------

set(SOURCES
    ${CMAKE_CURRENT_BINARY_DIR/bsw/version/version.c}
    bsw/interrupt_vector_table.s
    bsw/main.c
    bsw/startup.s
    bsw/util/util.c
)

set(INCLUDES
    bsw
    bsw/vendor/
    bsw/vendor/cmsis
    bsw/version
    bsw/config
    bsw/util
)

add_subdirectory(app)
add_subdirectory(bsw)

include(${CMAKE_SOURCE_DIR}/cmake/arm_gcc_build.cmake)
