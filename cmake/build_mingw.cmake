cmake_minimum_required(VERSION 3.26.1)

# CMake Files ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/build_options_common.cmake)

# Absolute Paths -------------------------------------------------------------------------------------------------------

# Get absolute paths to all source files for proper vscode PROBLEMS view file hyperlinks
foreach(c_source ${C_SOURCES})
  get_filename_component(abs_c_source ${c_source} ABSOLUTE)
  list(APPEND ABSOLUTE_C_SOURCES ${abs_c_source})
endforeach()

# Get absolute paths to all include folders for proper vscode PROBLEMS view file hyperlinks
foreach(include ${INCLUDES})
  get_filename_component(abs_include ${include} ABSOLUTE)
  list(APPEND ABSOLUTE_INCLUDES -I${abs_include}) # -I on each folder necessary for cppcheck to find each folder
endforeach()

# Executable Settings --------------------------------------------------------------------------------------------------

set(CMAKE_EXECUTABLE_SUFFIX_C ".exe")
add_executable(${TEST_EXECUTABLE} ${C_SOURCES})
target_include_directories(${TEST_EXECUTABLE} PRIVATE ${INCLUDES})

# Compiler Options -----------------------------------------------------------------------------------------------------

target_compile_options(
  ${TEST_EXECUTABLE}
  PRIVATE
  # cmake-format: off

  ${COMMON_COMPILE_OPTIONS}     # Options common to HW target and unit test build

  # Optimization
  -O0                           # Disable code optimization

  # Code coverage
  -fprofile-arcs                # Enable arc-based profiling
  -ftest-coverage               # Enable test coverage analysis

  # cmake-format: on
)

# Linker Options -------------------------------------------------------------------------------------------------------

target_link_options(
  ${TEST_EXECUTABLE}
  PRIVATE
  # cmake-format: off

  ${COMMON_LINK_OPTIONS}     # Options common to HW target and unit test build

  # Code coverage
  -fprofile-arcs                # Enable arc-based profiling
  -ftest-coverage               # Enable test coverage analysis

  # cmake-format: on
)

# Post Build Commands---------------------------------------------------------------------------------------------------

# Clean Command --------------------------------------------------------------------------------------------------------

# Clean coverage files and folders that are known apriori (unit test specific html files are not known a priori)
set_property(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES CMakeFiles
  PROPERTY ADDITIONAL_CLEAN_FILES cmake_install.cmake
  PROPERTY ADDITIONAL_CLEAN_FILES coverage.css
  PROPERTY ADDITIONAL_CLEAN_FILES coverage.html
  PROPERTY ADDITIONAL_CLEAN_FILES coverage.functions.html
  PROPERTY ADDITIONAL_CLEAN_FILES CTestTestfile.cmake
)
