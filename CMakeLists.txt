cmake_minimum_required(VERSION 3.21.1)
project(checkers)

set(CMAKE_CXX_STANDARD 23)

#set(SFML_INCLUDE_DIR "/usr/local/Cellar/sfml/2.5.1_1/include")
#set(SFML_LIBRARY_DIR "/usr/local/Cellar/sfml/2.5.1_1/lib")


add_executable(checkers
        main.cpp
        Objects/Board.cpp
        Objects/Checkers.cpp
        Objects/Dot.cpp
        Objects/Checker.cpp
        Objects/Window.cpp
        )

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(checkers sfml-system sfml-window
        sfml-graphics sfml-audio sfml-network
#        doctest
#        default
        )

enable_testing()

add_subdirectory(Test)
add_subdirectory(Doctest)
#add_test(NAME Test COMMAND test --force-colors -d -ldefault)
#документация и тесты