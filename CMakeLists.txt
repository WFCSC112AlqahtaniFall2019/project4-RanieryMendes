cmake_minimum_required(VERSION 3.14)
project(project4_RanieryMendes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project4_RanieryMendes
        CMakeLists.txt
        TicTacToe.cpp
        TicTacToe.h
        TTTGame.cpp)
