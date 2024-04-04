#include "../src/sorting.hpp"
#include <gtest/gtest.h>

void expect_array_fwd_sorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		const bool expr = arr[i - 1] <= arr[i];
		EXPECT_TRUE(expr);
	}
}

TEST(InsertionSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::insertion_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(InsertionSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::insertion_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(SelectionSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::selection_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(SelectionSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::selection_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(MergeSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::merge_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(MergeSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::merge_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}
