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
    src/sorting_and_ordering/selection.hpp
    src/sorting_and_ordering/selection.cpp
    )

add_library(
	sorting_lib
	src/sorting_and_ordering/sorting.hpp
	src/sorting_and_ordering/sorting.cpp
	)

add_library(
	arrays_lib
	src/sorting_and_ordering/arrays.hpp
	src/sorting_and_ordering/arrays.cpp
	)

add_library(
	matrices_lib
	src/sorting_and_ordering/matrices.hpp
	src/sorting_and_ordering/matrices.cpp
	)

add_library(
	heaps_lib
	src/sorting_and_ordering/heaps.hpp
	src/sorting_and_ordering/heaps.cpp
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
