cmake_minimum_required(VERSION 4.4)
project(main)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp
        types.h
        machine.cpp
        machine.h
        generator.cpp
        generator.h)
