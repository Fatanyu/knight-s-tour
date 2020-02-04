cmake_minimum_required(VERSION 3.14)
project(knight-s-tour)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")

include_directories(headers)
include_directories(sources)

add_executable(knight-s-tour
        sources/chessboards/Chessboard.hpp
        sources/chessboards/BoardSize.hpp
        sources/game/Game.hpp
        sources/constants/TextConstants.hpp
        sources/chessboards/Chessboard.cpp
        sources/chessboards/BoardSize.cpp
        sources/game/Game.cpp
        sources/main.cpp sources/chessboards/IChessboard.hpp)