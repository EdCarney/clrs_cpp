#include "arrays.hpp"
#include <limits>

namespace arrays {
	// Calculates the max subarry in the specified array.
	// Uses an O(n^2) brute force approach.
	// Returns a tuple of (max, start_index, end_index)
	array_def max_subarray_bruteforce(int arr[], int size) {
		int max = constants::INT_MIN;
		int ind_L = -1;
		int ind_R = -1;
		for (int i = 0; i < size; i++) {
			int max_temp = 0;
			for (int j = i; j < size; j++) {
				max_temp += arr[j];
				if (max_temp > max) {
					max = max_temp;
					ind_L = i;
					ind_R = j;
				}
			}
		}
		return std::make_tuple(max, ind_L, ind_R);
	}
	
	// Calculates the max subarry in the specified array.
	// Uses an O(n*lgn) divide-and-conquer approach.
	// Returns a tuple of (max, start_index, end_index)
	array_def max_subarray_dnc(int arr[], int size) {
		return std::make_tuple(0, 0, 0);
	}
	
	// Calculates the max subarry in the specified array.
	// Uses an O(n) linear one-pass approach.
	// Returns a tuple of (max, start_index, end_index)
	array_def max_subarray_singlepass(int arr[], int size) {
		return std::make_tuple(0, 0, 0);
	}
}
