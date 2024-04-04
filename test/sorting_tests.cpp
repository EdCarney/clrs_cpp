#include "../src/sorting.hpp"
#include <gtest/gtest.h>
#include <cstdlib>
#include <tuple>

const int MAX_ARRAY_SIZE = 100;
const int NUM_ARRAYS = 100;
const int MIN_MAX_ARRAY_ELEMENT = 1000;

void expect_array_fwd_sorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		const bool expr = arr[i - 1] <= arr[i];
		EXPECT_TRUE(expr);
	}
}

std::tuple<int*, int> generate_random_array() {
	int size = rand() % MAX_ARRAY_SIZE + 1;
	int *arr = new int[size]();
       	for (int i = 0; i < size; i++) {
		arr[i] = rand() % MIN_MAX_ARRAY_ELEMENT;

		// randomly negate some elements
		bool make_negative = rand() % 3;
		if (make_negative == 0)
			arr[i] *= -1;
	}
	return std::make_tuple(arr, size);
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

TEST(InsertionSortTests, MultipleElementArrays) {
	srand(time(NULL));
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();
		sorting::insertion_sort(arr, size);
		expect_array_fwd_sorted(arr, size);
		delete[] arr;
	}
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

TEST(SelectionSortTests, MultipleElementArrays) {
	srand(time(NULL));
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();
		sorting::selection_sort(arr, size);
		expect_array_fwd_sorted(arr, size);
		delete[] arr;
	}
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

TEST(MergeSortTests, MultipleElementArrays) {
	srand(time(NULL));
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();
		sorting::merge_sort(arr, size);
		expect_array_fwd_sorted(arr, size);
		delete[] arr;
	}
}
