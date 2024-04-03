#include <iostream>
#include "sorting.hpp"

using namespace std;

int main() {
	int A[] = {3, 2, 9, 1, 0, 0, 2, 3};
	int len = sizeof(A) / sizeof(A[0]);

	for (int i = 0; i < len; i++) {
		printf("%i, ", A[i]);
	}
	printf("\n");

	sorting::insertion_sort(A, len);

	for (int i = 0; i < len; i++) {
		printf("%i, ", A[i]);
	}
	printf("\n");
}
