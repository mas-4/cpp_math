cmake_minimum_required(VERSION 3.23)
project(ms_math)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("math")
add_subdirectory("tests")

add_executable(ms_math main.cpp)
target_link_libraries(ms_math test_module)
target_include_directories(ms_math PUBLIC math)
