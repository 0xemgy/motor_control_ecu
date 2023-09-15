include(CTest)

set(CMAKE_EXECUTABLE_SUFFIX_C ".exe")

add_library(
  unity
  STATIC
  ./lib/unity/unity.c)
target_include_directories(unity PUBLIC ./lib/unity)

add_executable(test_util ./src/util/test_util.c ../src/util/util.c ./lib/unity/unity.c)
target_include_directories(test_util PRIVATE ./lib/unity ../src/util)
add_test(
  test_util
  test_util)
