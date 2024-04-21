#include "selection.hpp"
#include <cstdlib>
#include <vector>

int randomized_select_internal(std::vector<int> vec, int start, int end, int i);
int randomized_partition(std::vector<int> vec, int start, int end);

namespace selection {

    int randomized_select(std::vector<int> vec, int i) {
        return randomized_select_internal(vec, 0, vec.size() - 1, i);
    }
}

int randomized_select_internal(std::vector<int> vec, int start, int end, int i) {
    int len = end - start + 1;

    // check for bottom-out
    if (len == 1) {
        return vec[start];
    }

    int q = randomized_partition(vec, start, end);

    if (i == q) {
        return vec[q];
    } else if (i < q) {
        return randomized_select_internal(vec, start, q - 1, i);
    }
    else {
        return randomized_select_internal(vec, start, q - 1, i);
    }
}

// consider the input vector from start to end indexes
// we are looking for the i-th element
// for the partition step, we will:
//// randomly select an index in our range
//// swap that element with the end
//// do our paritition step
//// at the end, the pivot is in the right location
//// we return the index of the pivot
int randomized_partition(std::vector<int> vec, int start, int end) {
    int len = end - start + 1;
    int pivot_ind = start + std::rand() % len;
    
    // move pivot to front
    std::swap(vec[pivot_ind], vec[end]);
    int pivot = vec[end];

    // one-pass over vector
    int i = start - 1, j = start;
    while (++i < end) {
        if (vec[i] < pivot) {
            std::swap(vec[i], vec[j++]);
        }
    }
    std::swap(vec[j], vec[end]);
    return j;
}
