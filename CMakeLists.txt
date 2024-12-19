cmake_minimum_required(VERSION 3.29)
project(latinsquare_solver_AS3 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(latinsquare_solver_AS3
    stack.h
        stack.c
        solver.h
        solver.c
        printArray.c
        fileHandler.h
        fileHandler.c
        Client.c)
