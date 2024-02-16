cmake_minimum_required(VERSION 3.10)

project(vcpkg)

find_package(fmt CONFIG REQUIRED)

add_executable(vcpkg main.cpp)

target_link_libraries(vcpkg PRIVATE fmt::fmt)