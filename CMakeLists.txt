cmake_minimum_required(VERSION 3.14)
project(knight-s-tour)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

include_directories(headers)
include_directories(sources)

add_executable(knight-s-tour
        sources/Board.hpp
        sources/BoardSize.hpp
        sources/Game.hpp
        sources/TextConstants.hpp
        sources/Board.cpp
        sources/BoardSize.cpp
        sources/Game.cpp
        sources/main.cpp)