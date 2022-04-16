cmake_minimum_required(VERSION 3.23)
project(math)

set(CMAKE_CXX_STANDARD 20)

add_executable(math main.cpp modules/matrix.cpp modules/matrix.h)
