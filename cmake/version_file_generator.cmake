# Decimal To BCD Helper Function ---------------------------------------------------------------------------------------

function(decimal_to_bcd decimal_value output_variable)
  math(EXPR bcd_high "${decimal_value} / 10")
  math(EXPR bcd_low "${decimal_value} % 10")
  set(${output_variable} "${bcd_high}${bcd_low}" PARENT_SCOPE)
endfunction()

# Software Version -----------------------------------------------------------------------------------------------------

decimal_to_bcd(${PROJECT_VERSION_MAJOR} PROJECT_VERSION_MAJOR_BCD)
decimal_to_bcd(${PROJECT_VERSION_MINOR} PROJECT_VERSION_MINOR_BCD)
decimal_to_bcd(${PROJECT_VERSION_PATCH} PROJECT_VERSION_PATCH_BCD)

# Build Timestamp ------------------------------------------------------------------------------------------------------

string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d%H%M%S")

string(SUBSTRING ${BUILD_TIMESTAMP} 0 4 BUILD_TIMESTAMP_YEAR)
string(SUBSTRING ${BUILD_TIMESTAMP} 4 2 BUILD_TIMESTAMP_MONTH)
string(SUBSTRING ${BUILD_TIMESTAMP} 6 2 BUILD_TIMESTAMP_DAY)
string(SUBSTRING ${BUILD_TIMESTAMP} 8 2 BUILD_TIMESTAMP_HOUR)
string(SUBSTRING ${BUILD_TIMESTAMP} 10 2 BUILD_TIMESTAMP_MINUTE)
string(SUBSTRING ${BUILD_TIMESTAMP} 12 2 BUILD_TIMESTAMP_SECOND)

math(EXPR BUILD_TIMESTAMP_YEAR_BASE_2000 "${BUILD_TIMESTAMP_YEAR} - 2000")
decimal_to_bcd(${BUILD_TIMESTAMP_YEAR_BASE_2000} BUILD_TIMESTAMP_YEAR_BCD)
decimal_to_bcd(${BUILD_TIMESTAMP_MONTH} BUILD_TIMESTAMP_MONTH_BCD)
decimal_to_bcd(${BUILD_TIMESTAMP_DAY} BUILD_TIMESTAMP_DAY_BCD)
decimal_to_bcd(${BUILD_TIMESTAMP_HOUR} BUILD_TIMESTAMP_HOUR_BCD)
decimal_to_bcd(${BUILD_TIMESTAMP_MINUTE} BUILD_TIMESTAMP_MINUTE_BCD)
decimal_to_bcd(${BUILD_TIMESTAMP_SECOND} BUILD_TIMESTAMP_SECOND_BCD)

# Build Type -----------------------------------------------------------------------------------------------------------

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(BUILD_TYPE "VERSION_BUILD_TYPE_DEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(BUILD_TYPE "VERSION_BUILD_TYPE_RELEASE")
else()
  set(BUILD_TYPE "VERSION_BUILD_TYPE_UNKNOWN")
endif()

# Optimization Level ---------------------------------------------------------------------------------------------------

get_target_property(MAIN_CFLAGS ${EXECUTABLE} COMPILE_OPTIONS)

string(REGEX MATCH "-O[0-9sg]" OPTIMIZATION_LEVEL_FLAG ${MAIN_CFLAGS})

if(OPTIMIZATION_LEVEL_FLAG)
  string(REGEX REPLACE "-O([0-9sg])" "\\1" OPTIMIZATION_LEVEL "VERSION_OPTIMIZATION_LEVEL_O${OPTIMIZATION_LEVEL_FLAG}")
else()
  string(REGEX MATCH "-Ofast" OPTIMIZATION_LEVEL_FLAG ${MAIN_CFLAGS})
  if(OPTIMIZATION_LEVEL_FLAG)
    set(OPTIMIZATION_LEVEL "VERSION_OPTIMIZATION_LEVEL_OFAST")
  else()
    set(OPTIMIZATION_LEVEL "VERSION_OPTIMIZATION_LEVEL_UNKNOWN")
  endif()
endif()

# Git SHA --------------------------------------------------------------------------------------------------------------

execute_process(
  COMMAND git rev-parse --short HEAD WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE GIT_SHORT_SHA
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Git Repo Dirty Flag --------------------------------------------------------------------------------------------------

execute_process(
  COMMAND git diff --quiet --exit-code WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} RESULT_VARIABLE GIT_DIRTY_STATUS
)

if(GIT_DIRTY_STATUS EQUAL 1)
  set(GIT_REPO_DIRTY_FLAG true)
else()
  set(GIT_REPO_DIRTY_FLAG false)
endif()

# Automatic File Generation --------------------------------------------------------------------------------------------
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/bsw/version/version_config.h.in version_config.h @ONLY)
# execute_process(COMMAND attrib +R ${CMAKE_CURRENT_BINARY_DIR}\\version_config.h)
