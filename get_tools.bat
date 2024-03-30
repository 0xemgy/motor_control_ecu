setlocal
cd /d %~dp0

mklink /D ".\tools\arm_gnu_toolchain\" "c:\toolchain\arm_gnu_toolchain\arm-gnu-toolchain-12.2.mpacbti-rel1-mingw-w64-i686-arm-none-eabi\"
mklink /D ".\tools\clang_format\" "c:\toolchain\clang_format\v16.0.0\"
mklink /D ".\tools\clang_tidy\" "c:\toolchain\clang_tidy\v18.1.1\"
mklink /D ".\tools\cmake\" "c:\toolchain\cmake\v3.26.1\"
mklink /D ".\tools\cmake_format\" "c:\toolchain\cmake_format\v0.6.13\"
mklink /D ".\tools\codechecker\" "c:\toolchain\codechecker\v6.23.1\"
mklink /D ".\tools\cppcheck\" "c:\toolchain\cppcheck\v2.11\"
mklink /D ".\tools\doxygen\" "c:\toolchain\doxygen\v1.9.8\"
mklink /D ".\tools\gcovr\" "c:\toolchain\gcovr\v6.0\"
mklink /D ".\tools\graphviz\" "c:\toolchain\graphviz\v10.0.1\"
mklink /D ".\tools\lizard\" "c:\toolchain\lizard\v1.17.10\"
mklink /D ".\tools\mingw\" "c:\toolchain\mingw\i686-13.1.0-release-win32-dwarf-ucrt-rt_v11-rev1\"
mklink /D ".\tools\ninja\" "c:\toolchain\ninja\v1.11.1\"
