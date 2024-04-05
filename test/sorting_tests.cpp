#include "../src/sorting.hpp"
#include <gtest/gtest.h>
#include <cstdlib>
#include <tuple>
#include <map>

const int MAX_ARRAY_SIZE = 100;
const int NUM_ARRAYS = 100;
const int MIN_MAX_ARRAY_ELEMENT = 1000;

void expect_array_fwd_sorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		const bool expr = arr[i - 1] <= arr[i];
		EXPECT_TRUE(expr);
	}
}

void expect_maps_equal(std::unordered_map<int, int> arr_map_1, std::unordered_map<int, int> arr_map_2) {
	for (auto const& kvp: arr_map_1) {
	    int key = kvp.first;
	    int val = kvp.second;
	    EXPECT_TRUE(val == arr_map_2[key]);
	}
	for (auto const& kvp: arr_map_2) {
	    int key = kvp.first;
	    int val = kvp.second;
	    EXPECT_TRUE(val == arr_map_1[key]);
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

void populate_array_map(std::unordered_map<int, int> arr_map, int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int element = arr[i];
		if (arr_map.find(element) == arr_map.end()) {
			arr_map[element] = 0;
		}
		arr_map[element]++;
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

TEST(InsertionSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::insertion_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
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
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::selection_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}

TEST(BubbleSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::bubble_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(BubbleSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::bubble_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(BubbleSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::bubble_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
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
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::merge_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}
