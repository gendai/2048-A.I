cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-g -Wall -I../src -Wextra -Werror -std=c++14 -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(SRC
    src/main.cc)

add_executable(2048-ai ${SRC})
