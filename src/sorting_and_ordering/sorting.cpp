#include "sorting.hpp"
#include <tuple>
#include <cmath>
#include <limits.h>

void merge_sort_internal(int[], int, int);
void merge_combine(int[], int, int, int);
void quick_sort_internal(int arr[], int start, int end);
int quick_sort_partition(int arr[], int start, int end);
void counting_sort_internal(int arr[], int size, int min, int max);
void radix_counting_sort(int arr[], int size, int mod);
std::tuple<int, int> get_min_max(int arr[], int size);

struct node {
    int val;
    node* next;
};

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

    // Sorts the provided array using counting sort
    void counting_sort(int arr[], int size) {
        auto [min, max] = get_min_max(arr, size);
        counting_sort_internal(arr, size, min, max);
    }

    // Sorts the provided array using radix sort
    void radix_sort(int arr[], int size) {

        auto [min, max] = get_min_max(arr, size);

        // shift array left to ensure elements are zero-based
        // this also reduces the while loop iterations required
        for (int i = 0; i < size; i++) {
            arr[i] -= min;
        }
        max -= min;

        int mod_num = 10;
        while (mod_num < 10 * max) {
            radix_counting_sort(arr, size, mod_num);
            mod_num *= 10;
        }

        // undo previous modification
        for (int i = 0; i < size; i++) {
            arr[i] += min;
        }
    }

    void bucket_sort(int arr[], int size) {
        auto [min, max] = get_min_max(arr, size);
        
        // shift array left to ensure elements are zero-based
        for (int i = 0; i < size; i++) {
            arr[i] -= min;
        }

        node** B = new node*[size];
        for (int i = 0; i < size; i++) {
            B[i] = nullptr;
        }
        
        // populate linked list
        for (int i = 0; i < size; i++) {
            double ratio = (double)arr[i] / (double)(max - min);
            int ind = std::ceil(ratio * size) - 1;
            ind = ind < 0 ? 0 : ind; // handle case where value is zero
            
            if (B[ind] == nullptr) {
                B[ind] = new node { arr[i], nullptr };
            } else {
                node* curr_node = B[ind];
                while (curr_node->next != nullptr) {
                    curr_node = curr_node->next;
                }
                curr_node->next = new node { arr[i], nullptr };
            }
        }

        int arr_ptr = 0;
        for (int i = 0; i < size; i++) {
            node *curr_node;
            int list_size = 0;

            // get size of list
            list_size = 0;
            curr_node = B[i];
            while (curr_node != nullptr) {
                list_size++;
                curr_node = curr_node->next;
            }

            // read linked list into array
            int *sorted = new int[list_size];
            list_size = 0;
            curr_node = B[i];
            while (curr_node != nullptr) {
                sorted[list_size++] = curr_node->val;
                curr_node = curr_node->next;
            }
            
            // insertion sort
            for (int j = 1; j < list_size; j++) {
                for (int k = j - 1; k >= 0; k--) {
                    if (sorted[k] > sorted[k + 1]) {
                        int temp = sorted[k];
                        sorted[k] = sorted[k + 1];
                        sorted[k + 1] = temp;
                    }
                }
            }

            // populate given array w/ sorted values
            for (int j = 0; j < list_size; j++) {
                arr[arr_ptr++] = sorted[j];
            }
        }

        // undo previous modification
        for (int i = 0; i < size; i++) {
            arr[i] += min;
        }
    }
}

std::tuple<int, int> get_min_max(int arr[], int size) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < size; i++) {
        min = arr[i] < min ? arr[i] : min;
        max = arr[i] > max ? arr[i] : max;
    }
    return std::make_tuple(min, max);
}

void radix_counting_sort(int arr[], int size, int mod) {
    int k = 10;
    int* B = new int[size];
    int* C = new int[k];
    // initialize counting array
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }
    // populate counting array
    for (int i = 0; i < size; i++) {
        int arr_elm = arr[i];
        int digit = (arr_elm % mod - (arr_elm % (mod / 10))) / (mod / 10);
        C[digit] += 1;
    }
    // accumulate all of the values
    for (int i = 1; i < k; i++) {
        C[i] += C[i - 1];
    }
    // populate the capture array
    // need to do this opposite way to retain original sorting for radix
    int j = size - 1;
    while (j >= 0) {
        int arr_elm = arr[j];
        int digit = (arr_elm % mod - (arr_elm % (mod / 10))) / (mod / 10);
        B[C[digit] - 1] = arr_elm;
        C[digit] -= 1;
        --j;
    }
    // populate the original array
    for (int i = 0; i < size; i++) {
        arr[i] = B[i];
    }

    delete[] B;
    delete[] C;
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
