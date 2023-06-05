cmake_minimum_required(VERSION 3.0.0)
project(XCad VERSION 0.1.0)


include(CTest)
enable_testing()

add_subdirectory(Assets)

add_executable(XCad main.cpp)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(XCad glfw)
target_link_libraries(XCad GLEW::GLEW)
target_link_libraries(XCad OpenGL::GL)

#User defined libraries
target_link_libraries(XCad Asset)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
