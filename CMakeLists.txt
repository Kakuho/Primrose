cmake_minimum_required(VERSION 3.1...3.29)

project(Primrose VERSION 1.0 
                    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

set(CXX_SRCS 
        include/static_array.hpp
        include/static_string.hpp
   )

# unit tests

find_package(Catch2 3 REQUIRED)

set(TEST_SRCS 
      tests/static_array.cpp
   )

add_executable(tests ${TEST_SRCS} ${CXX_SRCS})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_compile_options(tests PRIVATE -g -std=c++20)
