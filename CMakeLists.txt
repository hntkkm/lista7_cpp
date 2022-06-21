cmake_minimum_required(VERSION 3.22)
project(BST_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BST_cpp
        main.cpp
        Tree.cpp
        Tree.h)
