cmake_minimum_required(VERSION 3.19)
project(lab2final)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(lab2final main.cpp tests/ClassName.h tests/test.cpp src/matrix.cpp src/matrix.h src/sequence.h src/vector.cpp src/vector.h src/arraysequence.cpp
        src/arraysequence.h src/dynamicarray.h src/dynamicarray.cpp)

target_link_libraries(lab2final gtest gtest_main)