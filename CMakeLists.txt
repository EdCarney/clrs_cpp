cmake_minimum_required(VERSION 3.23)
project(Algorithms VERSION 1.0.0)

add_library(
	sorting_lib
	src/sorting.hpp
	src/sorting.cpp
	)

add_executable(algo_test src/main.cpp)

target_link_libraries(algo_test PRIVATE sorting_lib)
