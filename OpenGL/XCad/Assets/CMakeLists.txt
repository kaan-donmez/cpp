add_library(Asset source/IconOfApplication.cpp)

target_include_directories(Asset PUBLIC include)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Asset glfw)
target_link_libraries(Asset GLEW::GLEW)
target_link_libraries(Asset OpenGL::GL)