cmake_minimum_required(VERSION 3.23)

set(This CLRS_CPP_TESTS)
set(CMAKE_CXX_STANDARD 17)
set(Sources
	sorting_tests.cpp
	arrays_tests.cpp
	matrices_tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	sorting_lib
	arrays_lib
	matrices_lib
)

add_test(
	NAME ${This}
	COMMAND ${This}
)
