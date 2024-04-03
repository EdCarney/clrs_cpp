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
