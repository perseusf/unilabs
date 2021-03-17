cmake_minimum_required(VERSION 3.17)
project(Studying__lab_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main main.c
        ${CMAKE_SOURCE_DIR}/libs/array.c ${CMAKE_SOURCE_DIR}/libs/array.h
        )
