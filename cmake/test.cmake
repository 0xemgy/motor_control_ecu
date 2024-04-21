cmake_minimum_required(VERSION 3.26.1)

# Build all tests target -----------------------------------------------------------------------------------------------
add_custom_target(
  check
)

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

  add_dependencies(check ${TEST_EXECUTABLE})

endfunction()
