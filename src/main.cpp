#include <iostream>
#include "sorting.hpp"

using namespace std;

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%i", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("\n");
}

int main() {
	int arr[] = {3, 2, 82, 1, 10, 16, -19, -22, 1, 2, 20, 9, -1, 0, 100, 2, 3, 99, 1, -15};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Initial Array:\n");
	print_array(arr, size);

	sorting::selection_sort(arr, size);

	printf("Sorted Array:\n");
	print_array(arr, size);
}
