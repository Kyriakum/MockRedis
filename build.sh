#!/bin/sh

set -e
(
cd "$(dirname "$0")"
cmake -B -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build ./build
)