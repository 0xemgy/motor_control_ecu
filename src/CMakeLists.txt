cmake_minimum_required(VERSION 3.26.1)

# Microprocessor Type --------------------------------------------------------------------------------------------------

set(MICROPROCESSOR_TYPE cortex-m4)

# Source Files and Include Directories ---------------------------------------------------------------------------------

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
    bsw/version
)

set(SYSTEM_INCLUDES
    bsw/vendor/gcc
)

# CMake Files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/build_arm_gcc.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/analyze.cmake)
