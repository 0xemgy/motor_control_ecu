
add_custom_target(
  test_all
  COMMAND ctest --output-on-failure
  # COMMAND python -m gcovr -r ${CMAKE_BINARY_DIR} --html --html-details -o coverage_report.html
  # DEPENDS ${ALL_TEST_EXECUTABLES}
)

# set(ALL_TEST_EXECUTABLES "")

enable_testing()

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

include(${CMAKE_SOURCE_DIR}/cmake/mingw_build.cmake)

add_test(
  ${TEST_EXECUTABLE}
  ${TEST_EXECUTABLE})

# set(ALL_TEST_EXECUTABLES ${ALL_TEST_EXECUTABLES} ${TEST_EXECUTABLE})

endfunction()
