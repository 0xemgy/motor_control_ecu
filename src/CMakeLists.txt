cmake_minimum_required(VERSION 3.26.1)

# Source files and Include Directories ---------------------------------------------------------------------------------

set(ASM_SOURCES
    bsw/interrupt_vector_table.s
    bsw/startup.s
)

set(C_SOURCES
    bsw/main.c
    bsw/util/util_debouncer/util_debouncer.c
    bsw/util/util_debouncer/util_debouncer.h
    bsw/util/util_memcpy/util_memcpy.c
    bsw/util/util_memcpy/util_memcpy.h
    bsw/util/util_memset/util_memset.c
    bsw/util/util_memset/util_memset.h
    bsw/util/util_timeout/util_timeout.c
    bsw/util/util_timeout/util_timeout.h
    bsw/util/util/util.c
    bsw/util/util/util.h
    bsw/version/version.c
    bsw/version/version.h
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
    bsw/util/util_memcpy
    bsw/util/util_memset
    bsw/util/util_averager
    bsw/util/util_scaler
    bsw/util/util_semver
    bsw/util/util_timeout
    bsw/util/util_timestamp
    bsw/vendor
    bsw/vendor/cmsis
    bsw/vendor/gcc
    bsw/version
)

# CMake files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/arm_gcc_build.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/analyze.cmake)
