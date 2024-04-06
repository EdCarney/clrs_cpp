#include "../src/arrays.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <limits>

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

TEST(MaxSubarrayBruteForce, MultipleElementArray) {
	int arr[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int size = 16;

	int max, start, end;
	std::tie(max, start, end) = arrays::max_subarray_bruteforce(arr, size);
	
	EXPECT_EQ(max, 43);
	EXPECT_EQ(start, 7);
	EXPECT_EQ(end, 10);
}
