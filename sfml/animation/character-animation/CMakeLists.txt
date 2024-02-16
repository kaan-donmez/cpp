add_library(CharacterAnimation STATIC src/CharacterAnimation.cpp)

target_include_directories(CharacterAnimation PUBLIC include)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(CharacterAnimation sfml-graphics sfml-audio)
