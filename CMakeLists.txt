cmake_minimum_required(VERSION 3.2)
project(modelling_and_simulation_of_systems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES
    main.cpp MWC.cpp MWC.h common_header.h FibonacciGenerator.cpp FibonacciGenerator.h AbstractRandomGenerator.h MixedGenerator.cpp MixedGenerator.h)

add_executable(modelling_and_simulation_of_systems ${SOURCE_FILES})