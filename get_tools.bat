setlocal
cd /d %~dp0

mklink /D ".\tools\arm_gnu_toolchain\" "c:\toolchain\arm_gnu_toolchain\arm-gnu-toolchain-12.2.mpacbti-rel1-mingw-w64-i686-arm-none-eabi\"
mklink /D ".\tools\c_naming_checker\" "c:\toolchain\c_naming_checker\v0.0.1"
mklink /D ".\tools\clang_format\" "c:\toolchain\clang_format\v16.0.0\"
mklink /D ".\tools\clang_tidy\" "c:\toolchain\clang_tidy\v18.1.1\"
mklink /D ".\tools\cmake_format\" "c:\toolchain\cmake_format\v0.6.13\"
mklink /D ".\tools\cmake\" "c:\toolchain\cmake\v3.26.1\"
mklink /D ".\tools\cppcheck\" "c:\toolchain\cppcheck\v2.14\"
mklink /D ".\tools\doxygen\" "c:\toolchain\doxygen\v1.9.8\"
mklink /D ".\tools\graphviz\" "c:\toolchain\graphviz\v10.0.1\"
mklink /D ".\tools\libclang\" "c:\toolchain\libclang\v18.1.1\"
mklink /D ".\tools\mingw\" "c:\toolchain\mingw\i686-13.1.0-release-win32-dwarf-ucrt-rt_v11-rev1\"
mklink /D ".\tools\ninja\" "c:\toolchain\ninja\v1.11.1\"
mklink /D ".\tools\python\" "c:\toolchain\python\v3.12.3-embed-amd64-cust1\"
