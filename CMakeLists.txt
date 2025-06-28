cmake_minimum_required(VERSION 3.30)
project(myownredis)

set(CMAKE_CXX_STANDARD 23)

set(asio_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/x64-linux/share/asio")
set(spdlog_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/x64-linux/share/spdlog")
set(fmt_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/x64-linux/share/fmt")

file(GLOB_RECURSE SOURCE src/*.cpp)

find_package(asio CONFIG REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable(myownredis ${SOURCE})

target_link_libraries(myownredis PRIVATE asio::asio)
target_link_libraries(myownredis PRIVATE spdlog::spdlog fmt::fmt)

target_include_directories(myownredis PRIVATE src/)
target_include_directories(myownredis PRIVATE src/server/)
target_include_directories(myownredis PRIVATE src/resp/)
target_include_directories(myownredis PRIVATE src/resp/commands/)
