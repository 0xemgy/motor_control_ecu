cmake_minimum_required(VERSION 3.26.1)

# Source files and Include Directories----------------------------------------------------------------------------------

set(SOURCES
    bsw/interrupt_vector_table.s
    bsw/main.c
    bsw/startup.s
    bsw/util/util_debouncer/util_debouncer.c
    bsw/util/util_mem/util_mem.c
    bsw/util/util_timeout/util_timeout.c
    bsw/util/util/util.c
    bsw/version/version.c
)

set(INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}
    bsw
    bsw/config
    bsw/util
    bsw/util/util
    bsw/util/util_debouncer
    bsw/util/util_estimator
    bsw/util/util_getter
    bsw/util/util_mem
    bsw/util/util_moving_averager
    bsw/util/util_scaler
    bsw/util/util_semver
    bsw/util/util_timeout
    bsw/util/util_timestamp
    bsw/vendor
    bsw/vendor/cmsis
    bsw/version
)

add_subdirectory(app)
add_subdirectory(bsw)

include(${CMAKE_SOURCE_DIR}/cmake/arm_gcc_build.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/cppcheck.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/lizard.cmake)
