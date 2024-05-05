#ifndef ARRAYS_HPP_INCLUDED
#define ARRAYS_HPP_INCLUDED

#include <tuple>

namespace arrays {

	typedef std::tuple<int, int, int> array_def;
	
	array_def max_subarray_bruteforce(int arr[], int size);
	
	array_def max_subarray_dnc(int arr[], int size);
	
	array_def max_subarray_singlepass(int arr[], int size);

}

#endif // ARRAYS_HPP_INCLUDED
