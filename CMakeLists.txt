cmake_minimum_required(VERSION 3.31)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(SnakeGame main.cpp WormPart.cpp Grid.cpp Worm.cpp)
