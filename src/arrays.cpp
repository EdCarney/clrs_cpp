#include "arrays.hpp"
#include <limits.h>

arrays::array_def max_subarray_dnc_internal(int[], int, int);
arrays::array_def max_subarray_dnc_maxcrossing(int[], int, int, int);

namespace arrays {
	// Calculates the max subarry in the specified array.
	// Uses an O(n^2) brute force approach.
	// Returns a tuple of (max, start_index, end_index)
	array_def max_subarray_bruteforce(int arr[], int size) {
		int max = INT_MIN;
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
		if (size == 0) {
			return std::make_tuple(INT_MIN, -1, -1);
		}
		return max_subarray_dnc_internal(arr, 0, size - 1);
	}
	
	// Calculates the max subarry in the specified array.
	// Uses an O(n) linear one-pass approach.
	// Returns a tuple of (max, start_index, end_index)
	array_def max_subarray_singlepass(int arr[], int size) {
		int max_sum = INT_MIN;
		int current_sum = 0;
		int high = -1, low = -1;
		int current_high = 0, current_low = 0;
		for (int i = 0; i < size; i++) {
			current_high = i;
			current_sum += arr[current_high];
			if (current_sum > max_sum) {
				max_sum = current_sum;
				high = current_high;
				low = current_low;
			}
			if (current_sum < 0) {
				current_sum = 0;
				current_low = current_high + 1;
			}
		}
		return std::make_tuple(max_sum, low, high);
	}
}

arrays::array_def max_subarray_dnc_internal(int arr[], int low, int high) {
	// check for bottom-out
	if (low == high) {
		return std::make_tuple(arr[low], low, high);
	}

	int mid = (low + high) / 2;

	int max_left, low_left, high_left;
	int max_right, low_right, high_right;
	int max_cross, low_cross, high_cross;

	std::tie(max_left, low_left, high_left) = max_subarray_dnc_internal(arr, low, mid);
	std::tie(max_right, low_right, high_right) = max_subarray_dnc_internal(arr, mid + 1, high);
	std::tie(max_cross, low_cross, high_cross) = max_subarray_dnc_maxcrossing(arr, low, mid, high);
	
	if (max_left > max_right && max_left > max_cross) {
		return std::make_tuple(max_left, low_left, high_left);
	} else if (max_right > max_left && max_right > max_cross) {
		return std::make_tuple(max_right, low_right, high_right);
	} else {
		return std::make_tuple(max_cross, low_cross, high_cross);
	}
}

arrays::array_def max_subarray_dnc_maxcrossing(int arr[], int low, int mid, int high) {
	int sum, max_L, max_R;

	int sum_L = INT_MIN;
	sum = 0;
	for (int i = mid; i >= low; i--) {
		sum += arr[i];
		if (sum > sum_L) {
			max_L = i;
			sum_L = sum;
		}
	}

	int sum_R = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (sum > sum_R) {
			max_R = i;
			sum_R = sum;
		}
	}
	return std::make_tuple(sum_L + sum_R, max_L, max_R);

}
