cmake_minimum_required(VERSION 4.4)
project(main)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp
        types.h
        machine.cpp
        machine.h
        generator.cpp
        generator.h
        plus.cpp
        plus.h
        minus.cpp
        minus.h
        while.cpp
        while.h
        next_var.cpp
        next_var.h
        prev_var.cpp
        prev_var.h
        go_to.cpp
        go_to.h
        while_start.cpp
        while_start.h
        while_end.cpp
        while_end.h)
