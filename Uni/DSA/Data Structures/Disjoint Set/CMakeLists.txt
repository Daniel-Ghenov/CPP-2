cmake_minimum_required(VERSION 3.26)
project(Disjoint_Set)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Disjoint_Set
        DisjointSet.cpp
        DisjointSet.h
        main.cpp)
