#!/bin/sh

set -e
(
mkdir -p build

cd "$(dirname "$0")"

vcpkg install --x-install-root=build/vcpkg_installed

cmake -B build \
    -S . \
    -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build ./build
)