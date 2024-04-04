#include "sorting.hpp"

void merge_sort_internal(int[], int, int);
void merge_combine(int[], int, int, int);

void merge_sort_internal(int arr[], int p, int q) {
	if (p >= q)
		return;

	int r = (p + q) / 2;
	merge_sort_internal(arr, p, r);
	merge_sort_internal(arr, r + 1, q);
	merge_combine(arr, p, r, q);
}

// [9, 1, 4, 6, 2, 6, 7, 8, 9, 1, 3, 6, 7, 8, 3, 1, 6, 2]
//           p                 r                       q 
//           3                 9                       17
void merge_combine(int arr[], int p, int r, int q) {
	int size_L = r - p + 1;
	int size_R = q - r;
	int *L = new int[size_L + 1]();
	int *R = new int[size_R + 1]();
	for (int i = 0; i < size_L; i++) {
		L[i] = arr[p + i];
	}
	for (int i = 0; i < size_R; i++) {
		R[i] = arr[r + 1 + i];
	}
	L[size_L] = 99999;
	R[size_R] = 99999;
	int size = q - p + 1;
	int i = 0, j = 0, k = 0;
	while (k < size) {
		if (L[i] < R[j]) {
			arr[p + k++] = L[i++];
		} else {
			arr[p + k++] = R[j++];
		}
	}
}

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

// Sorts the provided array using merge sort
void sorting::merge_sort(int arr[], int size) {
	merge_sort_internal(arr, 0, size - 1);
}

