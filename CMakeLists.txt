cmake_minimum_required(VERSION 3.23)
project(Algorithms VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(
	debug_utilities_lib
	src/debug_utilities.hpp
	src/debug_utilities.cpp
	)

add_library(
    selection_lib
    src/selection.hpp
    src/selection.cpp
    )

add_library(
	sorting_lib
	src/sorting.hpp
	src/sorting.cpp
	)

add_library(
	arrays_lib
	src/arrays.hpp
	src/arrays.cpp
	)

add_library(
	matrices_lib
	src/matrices.hpp
	src/matrices.cpp
	)

add_library(
	heaps_lib
	src/heaps.hpp
	src/heaps.cpp
	)

set(LIBRARIES
    sorting_lib
    arrays_lib
    matrices_lib
    heaps_lib
    )

target_link_libraries(sorting_lib PUBLIC debug_utilities_lib)

add_subdirectory(googletest)
add_subdirectory(test)
