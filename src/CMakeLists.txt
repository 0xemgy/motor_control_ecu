cmake_minimum_required(VERSION 3.26.1)

# Source files and Include Directories----------------------------------------------------------------------------------

set(SOURCES
    bsw/interrupt_vector_table.s
    bsw/main.c
    bsw/startup.s
    bsw/debouncer/debouncer.c
    bsw/timeout/timeout.c
    bsw/util/util.c
    bsw/util/util_mem.c
    bsw/version/version.c
)

set(INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}
    bsw
    bsw/config
    bsw/debouncer
    bsw/timeout
    bsw/util
    bsw/vendor
    bsw/vendor/cmsis
    bsw/version
)

add_subdirectory(app)
add_subdirectory(bsw)

include(${CMAKE_SOURCE_DIR}/cmake/arm_gcc_build.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/cppcheck.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/lizard.cmake)
