cmake_minimum_required(VERSION 3.20)
project(laba1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(laba1
        main.cpp
        InputReader.h
        InputReader.cpp
        WeightedRandomGenerator.h
        WeightedRandomGenerator.cpp
        StatRecord.h
        FrequencyAnalyzer.h
        FrequencyAnalyzer.cpp
)