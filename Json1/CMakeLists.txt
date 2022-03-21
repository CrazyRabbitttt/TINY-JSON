cmake_minimum_required(VERSION 3.21)
project(Json1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Json1
        leptjson.c
        leptjson.h
        test.c)
