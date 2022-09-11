cmake_minimum_required(VERSION 3.21)
project(spiralPrimes)

set(CMAKE_CXX_STANDARD 14)

add_executable(spiralPrimes main.cpp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
