cmake_minimum_required(VERSION 3.26.1)

project(motor_control_ecu_app VERSION 1.0.0 LANGUAGES C ASM)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(test)

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
