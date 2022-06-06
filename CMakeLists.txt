cmake_minimum_required(VERSION 3.21.1)
project(checkers)

set(CMAKE_CXX_STANDARD 23)

set(SFML_INCLUDE_DIR "/usr/local/Cellar/sfml/2.5.1_1/include")
set(SFML_LIBRARY_DIR "/usr/local/Cellar/sfml/2.5.1_1/lib")

add_executable(checkers main.cpp Objects/Board.cpp Objects/Board.h Objects/Checkers.cpp Objects/Checkers.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(checkers sfml-system sfml-window sfml-graphics sfml-audio sfml-network)