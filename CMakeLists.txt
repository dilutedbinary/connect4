cmake_minimum_required(VERSION 3.10)
project(connect4)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(connect4
        include/Game.h
        include/Connect4Engine.h
        include/Connect4Game.h
        src/Game.cc
        src/C4BoardPrinter.cc
        src/Connect4Engine.cc
        src/Connect4GameRunner.cc
        src/test.cc src/C4BoardState.cpp include/C4BoardState.h src/C4BoardCell.cpp include/C4BoardCell.h)
