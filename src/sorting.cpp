#include "sorting.hpp"

// Sorts the provided array using insertion sort
void sorting::insertion_sort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = v;
	}
}

// Sorts the provided array using selection sort
void sorting::selection_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min_value = arr[i];
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < min_value) {
				min_value = arr[j];
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = min_value;
		arr[min_index] = temp;
	}
}
