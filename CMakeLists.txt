cmake_minimum_required(VERSION 2.8)

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-g -Wall -I../src -Wextra -Werror -std=c++14 -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(SRC
    src/main.cc
    src/rand.cc)

add_executable(2048-ai ${SRC})

add_custom_target(doc
                  COMMAND doxygen Doxyfile.in
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc)
add_dependencies(doc 2048-ai)

