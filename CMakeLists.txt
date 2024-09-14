cmake_minimum_required(VERSION 3.1...3.29)

project(Primrose VERSION 1.0 
                    LANGUAGES CXX)

include_directories(include)

set(CXX_SRCS 
        include/StaticArray.hpp
        include/StaticString.hpp
   )

# unit tests

find_package(Catch2 3 REQUIRED)

set(TEST_SRCS 
      tests/StaticArray.cpp
   )

add_executable(tests ${TEST_SRCS} ${CXX_SRCS})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_compile_options(tests PRIVATE -g -std=c++20)
