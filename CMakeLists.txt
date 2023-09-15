cmake_minimum_required(VERSION 3.26.1)

project(
  motor_control_ecu
  C
  ASM)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

set(SOURCES
    src/bsw/main.c
    src/bsw/startup.s
    src/bsw/isr_vector.s
    src/util/util.c
    src/util/util.h)

set(EXECUTABLE ${PROJECT_NAME})
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")

add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(
  ${EXECUTABLE}
  PRIVATE src
          src/bsw
          src/bsw/cmsis
          src/bsw/cfg
          src/util)

target_compile_options(
  ${EXECUTABLE}
  PRIVATE -std=c99
          -g3
          -mcpu=cortex-m4
          -mthumb
          -mfpu=fpv4-sp-d16
          -mfloat-abi=hard
          -fdata-sections
          -ffunction-sections
          -Wall
          -Wextra
          -pedantic
          -Wmissing-include-dirs
          -Wswitch-default
          -Wconversion
          # --specs=nano.specs --specs=nosys.specs
          $<$<CONFIG:Debug>:-O0>
          $<$<CONFIG:Release>:-O3>
          $<$<CONFIG:Release>:-DNDEBUG>)

target_link_options(
  ${EXECUTABLE}
  PRIVATE
  -T${CMAKE_SOURCE_DIR}/src/memory.ld
  -mcpu=cortex-m4
  -mthumb
  -mfpu=fpv4-sp-d16
  -mfloat-abi=hard
  -specs=nano.specs
  -specs=nosys.specs
  # -lc -lm
  -lnosys
  -nostartfiles
  -nodefaultlibs
  -nostdlib
  -ffreestanding
  -static
  -Wl,-Map=${PROJECT_NAME}.map,--cref
  -Wl,--gc-sections
  -Wl,--print-memory)

# Print executable size
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE}.elf)

# Create hex file
add_custom_command(
  TARGET ${EXECUTABLE}
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXECUTABLE}.elf ${PROJECT_NAME}.hex
  COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE}.elf ${PROJECT_NAME}.bin)

# Unit testing setup
enable_testing()
add_subdirectory(test)
