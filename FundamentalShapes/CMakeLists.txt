cmake_minimum_required(VERSION 3.0.0)
project(FundamentalShapes VERSION 0.1.0)


include(CTest)
enable_testing()

add_executable(FundamentalShapes main.cpp)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(FundamentalShapes glfw)
target_link_libraries(FundamentalShapes GLEW::GLEW)
target_link_libraries(FundamentalShapes OpenGL::GL)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
