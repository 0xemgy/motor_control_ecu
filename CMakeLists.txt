cmake_minimum_required(VERSION 3.26.1)

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

project(motor_control_ecu_app VERSION 0.1.0 LANGUAGES C ASM)


if (NOT UNIT_TEST)
    add_subdirectory(src)
endif()

if (UNIT_TEST)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif()
