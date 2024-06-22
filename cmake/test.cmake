cmake_minimum_required(VERSION 3.26.1)

# Tools Paths ----------------------------------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/tools.cmake)

# Build all tests target -----------------------------------------------------------------------------------------------

add_custom_target(
  test_build_all
)

# Run all tests target -------------------------------------------------------------------------------------------------

add_custom_target(
  test_run_all
  COMMAND
  ${CMAKE_CTEST_COMMAND} -T test --output-on-failure -R

  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_dependencies(test_run_all test_build_all)

# Coverage target ------------------------------------------------------------------------------------------------------

add_custom_target(
  test_coverage
  ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

  python -m gcovr
  --root .
  --gcov-executable ${CMAKE_GCOV}
  --html-details ${CMAKE_CURRENT_BINARY_DIR}/coverage.html
  -f src/*

  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_dependencies(test_coverage test_run_all)

# Add unit test function -----------------------------------------------------------------------------------------------

set(ADDITIONAL_C_SOURCES_NONE "")
set(ADDITIONAL_INCLUDES_NONE "")

function(add_unit_test UNIT_NAME UNIT_DIR ADDITIONAL_C_SOURCES ADDITIONAL_INCLUDES)

  set(TEST_EXECUTABLE test_${UNIT_NAME})

  set(C_SOURCES
    ${C_SOURCES}
    ${TEST_EXECUTABLE}/${TEST_EXECUTABLE}.c
    ${UNIT_DIR}/${UNIT_NAME}.c
    vendor/unity/unity.c
  )

  set(INCLUDES
    ${INCLUDES}
    ${UNIT_DIR}
    vendor/fff
    vendor/unity
  )

  include(${CMAKE_SOURCE_DIR}/cmake/build_mingw.cmake)

  add_test(
    ${TEST_EXECUTABLE}
    ${TEST_EXECUTABLE})

  add_dependencies(test_build_all ${TEST_EXECUTABLE})

endfunction()
