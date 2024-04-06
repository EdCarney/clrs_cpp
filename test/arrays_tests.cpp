#include "../src/arrays.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <limits>

//const int INT_MIN = std::numeric_limits<int>::min();

TEST(MaxSubarrayBruteForce, ZeroElementArray) {
	int arr[] = {};
	int size = 0;

	int max, start, end;
	std::tie(max, start, end) = arrays::max_subarray_bruteforce(arr, size);
	
	EXPECT_EQ(max, INT_MIN);
	EXPECT_EQ(start, -1);
	EXPECT_EQ(end, -1);
}

TEST(MaxSubarrayBruteForce, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;

	int max, start, end;
	std::tie(max, start, end) = arrays::max_subarray_bruteforce(arr, size);
	
	EXPECT_EQ(max, arr[0]);
	EXPECT_EQ(start, 0);
	EXPECT_EQ(end, 0);
}
