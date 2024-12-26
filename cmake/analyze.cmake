cmake_minimum_required(VERSION 3.26.1)

include(${CMAKE_SOURCE_DIR}/cmake/tools.cmake)

# Absolute Paths -------------------------------------------------------------------------------------------------------

# Get absolute paths to all source files
foreach(c_source ${C_SOURCES})
  get_filename_component(abs_c_source ${c_source} ABSOLUTE)
  list(APPEND ABSOLUTE_C_SOURCES ${abs_c_source})
endforeach()

# Get absolute paths to all include folders
foreach(include ${INCLUDES})
  get_filename_component(abs_include ${include} ABSOLUTE)
  list(APPEND ABSOLUTE_INCLUDES -I${abs_include})
endforeach()

# Get absolute paths to all system include folders
foreach(system_include ${SYSTEM_INCLUDES})
  get_filename_component(abs_system_include ${system_include} ABSOLUTE)
  list(APPEND ABSOLUTE_SYSTEM_INCLUDES -isystem ${abs_system_include})
endforeach()

# Run All Analyzers ----------------------------------------------------------------------------------------------------

add_custom_target(
    analyze_all
    DEPENDS analyze_naming analyze_formatting analyze_comments analyze_static_code analyze_static_code_2 analyze_metrics analyze_memory analyze_loc analyze_generate_report

    COMMENT "Running all analyzers"
)

# comments --------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_comments
  ${CMAKE_COMMAND}
    -E env
    --modify PROJECT_NAME=set:"${CMAKE_PROJECT_NAME}"
    --modify DOT_PATH=set:"${TOOLS_GRAPHVIZ_PATH}"
    --modify INPUT=set:"${CMAKE_CURRENT_SOURCE_DIR}"
    --modify EXCLUDE=set:"${CMAKE_CURRENT_SOURCE_DIR}/bsw/vendor/"
    --modify OUTPUT_DIRECTORY=set:"${CMAKE_CURRENT_BINARY_DIR}/doxygen"
    ${TOOLS_DOXYGEN}
      ${CMAKE_SOURCE_DIR}/Doxyfile
  COMMENT "Running comments analysis"
)

# formatting -----------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_formatting
  COMMAND
  ${TOOLS_CLANG_FORMAT}
      --dry-run
      --Werror
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running formatting analysis"
)

# loc ------------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_loc
  COMMAND
  ${TOOLS_CLOC}
    ${CMAKE_CURRENT_SOURCE_DIR}
    --exclude-dir=vendor
    --by-file-by-lang
    --json
    --out=${CMAKE_CURRENT_BINARY_DIR}/loc_report.json
    --quiet

  COMMENT "Running loc analysis"
)

# iwyu -----------------------------------------------------------------------------------------------------------------

# TODO add iwyu

# memory ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_memory

  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python ${TOOLS_MEMORY_USAGE_ANALYZER}
      --map_file_path ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map
      --elf_file_path ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.elf
      --su_file_dir ${CMAKE_CURRENT_BINARY_DIR}
      --json_report_path ${CMAKE_CURRENT_BINARY_DIR}/memory_report.json

  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running memory analysis"
)

# metrics --------------------------------------------------------------------------------------------------------------

set(LIZARD_COMMON_ARGS
    --working_threads 4
    --modified
    --length 200
    --arguments 5
    -Tnloc=1000
    -Ttoken_count=500
    ${ABSOLUTE_C_SOURCES}
)

add_custom_target(
  analyze_metrics

  # Silent execution to xml output for html report
  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python -m lizard
      ${LIZARD_COMMON_ARGS}
      -o ${CMAKE_CURRENT_BINARY_DIR}/metrics_report.csv

  # Warnings only execution for console output
  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python -m lizard
      ${LIZARD_COMMON_ARGS}
      --warnings_only

  COMMENT "Running metrics analysis"
)

# naming ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_naming

  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python ${TOOLS_C_NAMING_CHECKER}
      --files ${ABSOLUTE_C_SOURCES}
      --ignore */main.c
      --libclang ${TOOLS_LIBCLANG}
      --out ${CMAKE_CURRENT_BINARY_DIR}/naming_report.json

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running naming analysis"
)

# report ---------------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_generate_report

  COMMAND ${CMAKE_COMMAND}
  -E env
    --modify PATH=set:"${TOOLS_PYTHON_PATH}"

    python ${TOOLS_HTML_REPORT_GENERATOR}
      --report_dir ${CMAKE_CURRENT_BINARY_DIR}

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running analysis report generation"
)

# static_code ----------------------------------------------------------------------------------------------------------

add_custom_target(
  analyze_static_code
  COMMAND
    ${TOOLS_CLANG_TIDY}
      -p=${CMAKE_CURRENT_BINARY_DIR}
      ${ABSOLUTE_C_SOURCES}

  COMMENT "Running static code analysis"
)

# static_code_2 --------------------------------------------------------------------------------------------------------

set(CPPCHECK_BUILD_PATH ${CMAKE_CURRENT_BINARY_DIR}/cppcheck)

add_custom_target(
  analyze_static_code_2
  COMMAND ${CMAKE_COMMAND}
    -E make_directory ${CPPCHECK_BUILD_PATH}

  COMMAND ${CMAKE_COMMAND}
    -E env
      --modify PATH=set:"${TOOLS_PYTHON_PATH}"
      --modify PYTHONPATH=set:"${TOOLS_CPPCHECK_PATH}/addons"

    ${TOOLS_CPPCHECK}
      --platform=win64

      # Check settings
      --addon=misra.json        # Run MISRA-C-2012 checks
      --check-level=exhaustive  # Set exhaustive check level
      --enable=all              # Enable all available checks
      --std=c99                 # Specify C99 standard
      --inline-suppr            # Enable inline suppressions
      --template=gcc            # Use GCC template for reporting
      --error-exitcode=1        # Fail if any issues are found

      --cppcheck-build-dir=${CPPCHECK_BUILD_PATH} # Build folder to save analyzer information (speeds up analysis)

      --suppress=checkersReport # Active checkers: x/y (use --checkers-report=<filename> to see details)

      # Suppressions for utility code
      --suppress=misra-c2012-19.2:*util*    # The union keyword should not be used

      # Suppressions for entire code base
      --suppress=missingIncludeSystem     # Avoid false positives on <stdbool.h> and <stdint.h> includes
      --suppress=toomanyconfigs           # Too many #ifdef configurations
      --suppress=unmatchedSuppression:*   #  Unmatched suppression
      --suppress=unusedFunction:*         # The function 'function name' is never used
      --suppress=unusedStructMember:*     # struct member 'struct member name' is never used
      --suppress=misra-c2012-2.3:*        # A project should not contain unused type declarations
      --suppress=misra-c2012-2.4:*        # A project should not contain unused tag declarations
      --suppress=misra-c2012-2.5:*        # A project should not contain unused macro declarations
      --suppress=misra-c2012-8.7:*        # Functions and objects should not be defined with external linkage if they are referenced in only one translation unit
      --suppress=misra-c2012-8.9:*        # An object should be defined at block scope if its identifier only appears in a single function
      --suppress=misra-c2012-11.4:*       # A conversion should not be performed between a pointer to object and an integer type
      --suppress=misra-c2012-11.5:*       # A conversion should not be performed from pointer to void into pointer to object

      # Suppressions for vendor code
      --suppress=*:*/vendor/cmsis/*

      # Include paths and source files
      ${ABSOLUTE_INCLUDES}
      ${ABSOLUTE_SYSTEM_INCLUDES}
      ${ABSOLUTE_C_SOURCES}

  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running static code 2 analysis"
)
