cmake_minimum_required(VERSION 3.17)
project(tag)

set(CMAKE_CXX_STANDARD 20)

add_executable(tag main.cpp library.h library.cpp)