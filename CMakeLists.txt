cmake_minimum_required(VERSION 3.30)
project(myownredis)

set(CMAKE_CXX_STANDARD 23)

set(asio_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/x64-linux/share/asio")

file(GLOB_RECURSE SOURCE src/*.cpp)

find_package(asio CONFIG REQUIRED)
add_executable(myownredis ${SOURCE})

target_link_libraries(myownredis PRIVATE asio asio::asio)

target_include_directories(myownredis PRIVATE src/)
target_include_directories(myownredis PRIVATE src/server/)
