# motor_control_ecu

- [motor\_control\_ecu](#motor_control_ecu)
  - [Notes](#notes)
    - [vscode](#vscode)
    - [Analyzers](#analyzers)
      - [Misc](#misc)
      - [c\_naming\_checker](#c_naming_checker)
      - [clang-format](#clang-format)
      - [clang-tidy](#clang-tidy)
      - [cmake-format](#cmake-format)
      - [codechecker](#codechecker)
      - [cppcheck](#cppcheck)
      - [doxygen](#doxygen)
      - [html report generator](#html-report-generator)
      - [iwyu](#iwyu)
      - [lizard](#lizard)
      - [memory\_usage\_analyzer](#memory_usage_analyzer)
    - [Unit Tests](#unit-tests)
      - [Unity and fff](#unity-and-fff)
      - [ctest](#ctest)
      - [gcovr](#gcovr)
      - [Debugging via vscode](#debugging-via-vscode)

## Notes

### vscode
- clang format and cmake format paths must be handwritten -> use python script or relative paths if vscode starts to
support it in the settings.json

### Analyzers

#### Misc
- a single analyze target is missing
- the ALL target should have a fixed execution order
  - build -> analyze -> test

#### c_naming_checker
- Add info and debug print using the logging package
- Parse an ignore file instead of ignoring a list of patterns
- add version
- Clean up AI generated code

#### clang-format
- nothing comes to mind

#### clang-tidy
- file prefix checking is not supported (no variable substitution)
  - pycparser script (problem: macros not supported, needs preprocessed source files)
  - libclang with python (not further investigated)
  - custom checks (clang-tidy feature)
    - is getting the file name supported
    - is adding a custom check easy (extensive documentation available)
  - modify clang-tidy code in llvm repo
  - false positive on some stdint/bool includes (not all, not related to nostdinc)

#### cmake-format
- settings need some tweaking
  - line breaks are sometimes good, often bad

#### codechecker
- not used, needs to be investigated

#### cppcheck
- uses python in PATH for misra.py checks, should use a local one in tools/python

#### doxygen
- generating graphs takes long, for analysis only minimal html is generated, and this only because it is needed for proper checking
- a doxygen generation for documentation should have a different doxyfile

#### html report generator
- add error handling
- check race conditions when analyze_all (xml dump files in lizard output)
- use xml lizard output, get max settings from somewhere
  - csv output does not contain totals/averages/per file state, only per function
  - no max allowed NLOC etc neither in csv nor in xml
- improve memory tables with expand/collapse + seciton/region sizes just like STM32CubeIDE

#### iwyu
- can't be built with clang 18 windows built because of assembly file to big, with clang 19 because of missing function
- maybe use an old version back when binaries where provided (very old, probably very buggy)

#### lizard
- the output statistics are interesting
  - right now only warnings are output
  - maybe when codechecker can be used stats can be show there

#### memory_usage_analyzer
- Clean up AI generated code
- add file and folder exist checks
- use logging instead of prints
- add version and verbose

### Unit Tests

#### Unity and fff
- build library and add to each test instead of building for each test

#### ctest
- vscode Test Explorer UI test file hyperlinks link to cmake files instead of test files (fix this if possible)
- put include(CTest) into test.cmake if Test Explorer UI can be configured to find it there (currently only works if include is in top CMakeLists.txt)
- sometime after clean:
```
[build] Test project C:/work/repos/motor_control_ecu/build/test
[build] No tests were found!!!
```

#### gcovr
- the coverage of a unit that has a dedicated unit test but is also used by other units, which are tested, probably consists of the merged data (not just the data of the dedicated unit test) -> this should be fixed if possible (and if assumption is even true)
- if test in run accidentally in debug preset, gcov fails in test preset because it finds debug gcov files too, so debug folder needs to be deleted -> fix this by only searching through test build

#### Debugging via vscode
