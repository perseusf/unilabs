cmake_minimum_required(VERSION 3.19)
project(lab2final)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(lab2final main.cpp tests/ClassName.h tests/test.cpp)

target_link_libraries(lab2final gtest gtest_main)