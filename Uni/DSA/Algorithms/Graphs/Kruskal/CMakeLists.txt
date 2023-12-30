cmake_minimum_required(VERSION 3.26)
project(Kruskal)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dependencies)

add_executable(Kruskal
        Dependencies/DisjointSet.cpp
        Dependencies/DisjointSet.h
        Dependencies/Edge.cpp
        Dependencies/Edge.h
        algorithm.cpp)
