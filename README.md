# motor_control_ecu

- [motor\_control\_ecu](#motor_control_ecu)
  - [Notes](#notes)
    - [Analyzers](#analyzers)
      - [Misc](#misc)
      - [clang-format](#clang-format)
      - [clang-tidy](#clang-tidy)
      - [cmake-format](#cmake-format)
      - [codechecker](#codechecker)
      - [cppcheck](#cppcheck)
      - [doxygen](#doxygen)
      - [iwyu](#iwyu)
      - [lizard](#lizard)

## Notes

### Analyzers

#### Misc
- a single analyze target is missing
- the ALL target should have a fixed execution order
  - build -> analyze -> test

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

#### cmake-format
- settings need some tweaking
  - line breaks are sometimes good, often bad

#### codechecker
- not used, needs to be investigated

#### cppcheck
- uses python in PATH for misra.py checks, should use a local one in tools/python

#### doxygen
- vscode output gets mangled on every first error like this (on output panel and also terminal)
```
[build] Adding xrefitems...
[build] SortingC:/work/repos/motor_control_ecu/src/bsw/main.c:22: error: Member MAGIC_NUMBER_1 (macro definition) of file main.c is not documented.
```
- causes erroneous problems view hyperlink
- generating graphs takes long, for analysis only minimal html is generated, and that only because it is needed for proper checking
- a doxygen generation for documentation should have a different doxyfile

#### iwyu
- can't be built with clang 18 windows built because of hard Visual Studio dependency
- maybe use an old version back when binaries where provided (very old, probably very buggy)

#### lizard
- the output statistics are interesting
  - right now only warnings are output
  - maybe when codechecker can be used stats can be show there
