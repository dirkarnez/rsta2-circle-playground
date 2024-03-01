#!/bin/sh
export PATH="/mingw64/bin:/usr/local/bin:/usr/bin:/bin:$USERPROFILE/Downloads"
export PATH="$PATH:$USERPROFILE/Downloads/xpack-aarch64-none-elf-gcc-13.2.1-1.1-win32-x64/xpack-aarch64-none-elf-gcc-13.2.1-1.1/bin"
# export PATH="$PATH:$USERPROFILE/Downloads/gcc-arm-none-eabi-10-2020-q4-major/bin"
export MAKE="$USERPROFILE/Downloads/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/mingw32-make.exe"

make="${MAKE:-make}"

cd src && \
$MAKE $1 $2 && \
read -p "done"
