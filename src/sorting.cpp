#include "sorting.hpp"
#include "debug_utilities.hpp"

void merge_sort_internal(int[], int, int);
void merge_combine(int[], int, int, int);
void quick_sort_internal(int arr[], int start, int end);
int quick_sort_partition(int arr[], int start, int end);
void counting_sort_internal(int arr[], int size, int min, int max);

namespace sorting {

	// Sorts the provided array using insertion sort
	void insertion_sort(int arr[], int size) {
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
	void selection_sort(int arr[], int size) {
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
	
	void bubble_sort(int arr[], int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = size - 1; j > i; j--) {
				if (arr[j - 1] > arr[j]) {
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}
			}
		}
	}
	
	// Sorts the provided array using merge sort
	void merge_sort(int arr[], int size) {
		merge_sort_internal(arr, 0, size - 1);
	}

    // Sorts the provided array using quick sort
    void quick_sort(int arr[], int size) {
        quick_sort_internal(arr, 0, size - 1);
    }

    void counting_sort(int arr[], int size) {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < size; i++) {
            min = min <= arr[i] ? min : arr[i];
            max = max >= arr[i] ? max : arr[i];
        }
        counting_sort_internal(arr, size, min, max);
    }
}

void quick_sort_internal(int arr[], int start, int end) {
    if (end <= start) {
        return;
    }
    int q = quick_sort_partition(arr, start, end);
    quick_sort_internal(arr, start, q - 1);
    quick_sort_internal(arr, q + 1, end);
}

int quick_sort_partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start, j = start, temp;
    while (j < end) {
        if (arr[j] < pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
    temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}

void merge_sort_internal(int arr[], int p, int q) {
	if (p >= q)
		return;

	int r = (p + q) / 2;
	merge_sort_internal(arr, p, r);
	merge_sort_internal(arr, r + 1, q);
	merge_combine(arr, p, r, q);
}

void merge_combine(int arr[], int p, int r, int q) {
	int size_L = r - p + 1;
	int size_R = q - r;
	int *L = new int[size_L]();
	int *R = new int[size_R]();
	for (int i = 0; i < size_L; i++) {
		L[i] = arr[p + i];
	}
	for (int i = 0; i < size_R; i++) {
		R[i] = arr[r + 1 + i];
	}
	int size = q - p + 1;
	int i = 0, j = 0, k = 0;
	while (k < size) {
		if (j >= size_R || (i < size_L && L[i] < R[j])) {
			arr[p + k++] = L[i++];
		} else {
			arr[p + k++] = R[j++];
		}
	}
	delete[] L;
	delete[] R;
}

// Sorts the provided array using counting sort
void counting_sort_internal(int arr[], int size, int min, int max) {
    int k = max - min + 1;
    int* B = new int[size]();
    int* C = new int[k]();
    // initialize counting array
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }
    // count the number of occurrences for each value
    for (int i = 0; i < size; i++) {
        C[arr[i] - min] += 1;
    }
    // accumulate all of the values
    for (int i = 1; i < k; i++) {
        C[i] += C[i - 1];
    }
    // populate the capture array
    for (int i = 0; i < size; i++) {
        B[C[arr[i] - min] - 1] = arr[i];
        C[arr[i] - min] -= 1;
    }
    // populate the original array
    for (int i = 0; i < size; i++) {
        arr[i] = B[i];
    }

    delete[] B;
    delete[] C;
}
