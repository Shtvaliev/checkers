cmake_minimum_required(VERSION 3.22)
project(Test)

enable_testing()

set(CMAKE_CXX_STANDARD 23)

set(SFML_INCLUDE_DIR "/usr/local/Cellar/sfml/2.5.1_1/include")
set(SFML_LIBRARY_DIR "/usr/local/Cellar/sfml/2.5.1_1/lib")

add_executable(Test
        test.cpp
#        ../Doctest/doctest.cpp
        ../Objects/Window.cpp
        ../Objects/Checker.cpp
        ../Objects/Board.cpp
        ../Objects/Dot.cpp
        ../Objects/Checkers.cpp
        )

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Test
                    sfml-system
                    sfml-window
                    sfml-graphics
                    sfml-audio
                    sfml-network
#                    doctest
#                    default
                    )

#target_link_libraries(Test PUBLIC doctest default)
add_test(NAME Test COMMAND Test --force-colors -d -ldefault)


#add_library(doctest::doctest ALIAS doctest)