setlocal
cd /d %~dp0

mklink /D ".\tools\arm-gnu-toolchain\" "c:\toolchain\arm-gnu-toolchain\arm-gnu-toolchain-12.2.mpacbti-rel1-mingw-w64-i686-arm-none-eabi\"
mklink /D ".\tools\clang-format\" "c:\toolchain\clang-format\v16.0.0\"
mklink /D ".\tools\clang-tidy\" "c:\toolchain\clang-tidy\v16.0.0"
mklink /D ".\tools\cmake\" "c:\toolchain\cmake\v3.26.1\"
mklink /D ".\tools\cmake-format\" "c:\toolchain\cmake-format\v0.6.13\"
mklink /D ".\tools\cppcheck\" "c:\toolchain\cppcheck\v2.11\"
mklink /D ".\tools\doxygen\" "c:\toolchain\doxygen\v1.9.8"
mklink /D ".\tools\gcovr\" "c:\toolchain\gcovr\v6.0"
mklink /D ".\tools\lizard\" "c:\toolchain\lizard\v1.17.10"
mklink /D ".\tools\mingw\" "c:\toolchain\mingw\i686-13.1.0-release-win32-dwarf-ucrt-rt_v11-rev1"
mklink /D ".\tools\ninja\" "c:\toolchain\ninja\v1.11.1"
