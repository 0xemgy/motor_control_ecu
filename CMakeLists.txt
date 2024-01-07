cmake_minimum_required(VERSION 3.26.1)

project(
  motor_control_ecu
  C
  ASM)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(test)

MESSAGE(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
