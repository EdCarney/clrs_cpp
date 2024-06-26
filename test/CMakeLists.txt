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
    prime_numbers_tests.cpp
    simple_heaps_tests.cpp
    open_addressing_heaps_tests.cpp
    binary_trees_tests.cpp
    tries_tests.cpp
    red_black_trees_tests.cpp
    treaps_tests.cpp
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
    prime_numbers_lib
    binary_trees_lib
    tries_lib
    red_black_trees_lib
    treaps_lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
