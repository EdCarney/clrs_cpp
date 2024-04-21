#include "../src/sorting.hpp"
#include "utilities.hpp"

const int NUM_ARRAYS = 100;

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

TEST(QuickSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::merge_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(QuickSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::quick_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(QuickSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::quick_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}

TEST(CountingSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::counting_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(CountingSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::counting_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(CountingSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::counting_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}

TEST(RadixSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::radix_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(RadixSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::radix_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(RadixSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::radix_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}

TEST(BucketSortTests, ZeroElementArray) {
	int arr[] = { };
	int size = 0;
	sorting::bucket_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(BucketSortTests, SingleElementArray) {
	int arr[] = { 1 };
	int size = 1;
	sorting::bucket_sort(arr, size);
	expect_array_fwd_sorted(arr, size);
}

TEST(BucketSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> arr_map_original;
	std::unordered_map<int, int> arr_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
		auto [arr, size] = generate_random_array();

		populate_array_map(arr_map_original, arr, size);
		sorting::bucket_sort(arr, size);
		populate_array_map(arr_map_sorted, arr, size);

		expect_array_fwd_sorted(arr, size);
		expect_maps_equal(arr_map_original, arr_map_sorted);
		delete[] arr;
	}
}
