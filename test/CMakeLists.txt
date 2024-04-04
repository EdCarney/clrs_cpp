cmake_minimum_required(VERSION 3.23)

set(This CLRS_CPP_TESTS)

set(Sources
	sorting_tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	sorting_lib
)

add_test(
	NAME ${This}
	COMMAND ${This}
)
