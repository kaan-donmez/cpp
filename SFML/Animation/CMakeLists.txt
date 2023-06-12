cmake_minimum_required(VERSION 3.0.0)
project(Animation VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Animation main.cpp)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Animation sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
