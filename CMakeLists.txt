cmake_minimum_required(VERSION 3.15)
project(sapper)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra)
add_executable(sapper main.cpp MinesweeperBoard.cpp MinesweeperBoard.h)
