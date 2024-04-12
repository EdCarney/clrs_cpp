#ifndef ARRAYS_HEADER_HPP
#define ARRAYS_HEADER_HPP

#include <tuple>

namespace arrays {

	namespace constants {
		const int INT_MIN = std::numeric_limits<int>::min();
	}

	typedef std::tuple<int, int, int> array_def;
	
	array_def max_subarray_bruteforce(int arr[], int size);
	
	array_def max_subarray_dnc(int arr[], int size);
	
	array_def max_subarray_singlepass(int arr[], int size);

}

#endif // ARRAYS_HEADER_HPP
