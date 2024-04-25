cmake_minimum_required(VERSION 3.23)

set(This CLRS_CPP_TESTS)
set(CMAKE_CXX_STANDARD 17)
set(Sources
	sorting_tests.cpp
	arrays_tests.cpp
	matrices_tests.cpp
    heaps_tests.cpp
    selection_tests.cpp
    queues_tests.cpp
    stacks_tests.cpp
    linked_lists_tests.cpp
    simple_heaps_tests.cpp
    utilities.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	sorting_lib
	arrays_lib
	matrices_lib
    heaps_lib
    selection_lib
    stacks_lib
    queues_lib
    linked_lists_lib
    simple_heaps_lib
)

add_test(
	NAME ${This}
	COMMAND ${This}
)
