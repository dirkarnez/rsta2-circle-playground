#!/bin/sh
export PATH="/mingw64/bin:/usr/local/bin:/usr/bin:/bin:$USERPROFILE/Downloads"
export PATH="$PATH:$USERPROFILE/Downloads/arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf/bin"
# export PATH="$PATH:$USERPROFILE/Downloads/gcc-arm-none-eabi-10-2020-q4-major/bin"
export MAKE="$USERPROFILE/Downloads/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/mingw32-make.exe"

make="${MAKE:-make}"

cd $USERPROFILE/Downloads/circle && \
./configure --raspberrypi 4 --realtime --prefix aarch64-none-elf- --multicore --c++17  && \
./makeall clean && \
./makeall && \
read -p "done"
