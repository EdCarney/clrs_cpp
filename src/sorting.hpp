#ifndef SORTING_HEADER_HPP
#define SORTING_HEADER_HPP

namespace sorting {

	void insertion_sort(int arr[], int size);
	
	void selection_sort(int arr[], int size);
	
	void bubble_sort(int arr[], int size);
	
	void merge_sort(int arr[], int size);

    void quick_sort(int arr[], int size);

    void counting_sort(int arr[], int size, int max_number);
}

#endif // SORTING_HEADER_HPP
