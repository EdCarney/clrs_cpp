#include "utilities.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <map>

const int MAX_ARRAY_SIZE = 100;
const int MIN_MAX_ARRAY_ELEMENT = 1000;

void expect_array_fwd_sorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		const bool expr = arr[i - 1] <= arr[i];
		EXPECT_TRUE(expr);
	}
}

void expect_vector_fwd_sorted(std::vector<int> vec) {
	for (int i = 1; i < vec.size(); i++) {
		const bool expr = vec[i - 1] <= vec[i];
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

std::vector<int> generate_random_vector() {
	int size = rand() % MAX_ARRAY_SIZE + 1;
    std::vector<int> vec(size);
       	for (int i = 0; i < size; i++) {
		vec[i] = rand() % MIN_MAX_ARRAY_ELEMENT;

		// randomly negate some elements
		bool make_negative = rand() % 3;
		if (make_negative == 0)
		    vec[i] *= -1;
	}
	return vec;
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

void populate_vector_map(std::unordered_map<int, int> vec_map, std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		int element = vec[i];
		if (vec_map.find(element) == vec_map.end()) {
			vec_map[element] = 0;
		}
		vec_map[element]++;
	}
}
