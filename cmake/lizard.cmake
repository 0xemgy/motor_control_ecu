add_custom_target(
  lizard ALL
  COMMAND "${CMAKE_SOURCE_DIR}/tools/lizard/lizard.exe"
          --working_threads 4
          --warnings_only
          --modified
          --CCN 15
          --length 200
          --arguments 5
          -Tnloc=1000
          -Ttoken_count=500
          ${ABSOLUTE_SOURCES}

  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running Lizard code complexity analysis"
)
