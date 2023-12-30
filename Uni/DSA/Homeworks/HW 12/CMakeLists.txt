cmake_minimum_required(VERSION 3.26)
project(HW_12)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dependencies)

add_executable(HW_12
        Dependencies/DisjointSet.cpp
        Dependencies/DisjointSet.h
        "Road Building/solution.cpp"
        Streets/solution.cpp)
