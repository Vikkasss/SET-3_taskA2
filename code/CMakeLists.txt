cmake_minimum_required(VERSION 3.28)
project(A2)

set(CMAKE_CXX_STANDARD 17)

add_executable(A2 main.cpp
        ArrayGenerator.h
        SortTester.h
        MergeSort.cpp
        InsertionSort.h
        HybridSort.h
        HybridSort.cpp
        InsertionSort.cpp
        SortTester.cpp
        ArrayGenerator.cpp)
