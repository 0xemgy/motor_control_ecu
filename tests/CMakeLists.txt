cmake_minimum_required(VERSION 3.26.1)

# CMake Files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/test.cmake)

# Unit Tests -----------------------------------------------------------------------------------------------------------

add_unit_test(util_memset ${CMAKE_SOURCE_DIR}/src/bsw/util/util_memset)
add_unit_test(util_memcpy ${CMAKE_SOURCE_DIR}/src/bsw/util/util_memcpy)
