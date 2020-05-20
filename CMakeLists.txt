cmake_minimum_required(VERSION 3.15)
project(sum)

set(CMAKE_CXX_STANDARD 14)

add_executable(sum
        main.cpp
        IGraph.cpp
        IGraph.hpp
        ListGraph.cpp
        ListGraph.hpp
        MatrixGraph.cpp
        MatrixGraph.hpp
        SetGraph.cpp
        SetGraph.hpp
        ArcGraph.cpp
        ArcGraph.hpp)
