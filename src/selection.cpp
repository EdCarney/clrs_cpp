#include "selection.hpp"
#include <cstdlib>
#include <vector>

int randomized_select_internal(std::vector<int> vec, int start, int end, int i);
int randomized_partition(std::vector<int> &vec, int start, int end);

namespace selection {

    // Finds the i-th largest element in the provided vector
    // The value of i should range between 0 and one less than the vector size.
    int randomized_select(std::vector<int> vec, int i) {
        return randomized_select_internal(vec, 0, vec.size() - 1, i);
    }
}

int randomized_select_internal(std::vector<int> vec, int start, int end, int i) {
    int len = end - start + 1;

    // check for bottom-out
    if (len <= 1) {
        return vec.at(start);
    }

    // q is absolute position, k is relative
    int q = randomized_partition(vec, start, end);
    int k = q - start;

    if (i == k) {
        return vec.at(q);
    } else if (i < k) {
        return randomized_select_internal(vec, start, q - 1, i);
    }
    else {
        return randomized_select_internal(vec, q + 1, end, i - k - 1);
    }
}

int randomized_partition(std::vector<int> &vec, int start, int end) {
    int len = end - start + 1;
    int pivot_ind = start + std::rand() % len;

    // move pivot to front
    std::swap(vec.at(pivot_ind), vec.at(end));
    int pivot = vec.at(end);

    // one-pass over vector
    int i = start - 1, j = start;
    while (++i < end) {
        if (vec.at(i) < pivot) {
            std::swap(vec.at(i), vec.at(j++));
        }
    }
    std::swap(vec.at(j), vec.at(end));
    return j;
}
