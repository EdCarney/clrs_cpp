#include "selection.hpp"
#include <cstdlib>
#include <vector>

int randomized_select_internal(std::vector<int> vec, int start, int end, int i);
int split_select_internal(std::vector<int> &vec, int start, int end, int i);
int randomized_partition(std::vector<int> &vec, int start, int end);
int selected_element_partition(std::vector<int> &vec, int start, int end, int pivot_ind);

int get_lower_median(int len) {
    return len % 2 > 0 ? len / 2 : (len / 2) - 1;
}

namespace selection {

    // Finds the i-th largest element in the provided vector
    // The value of i should range between 0 and one less than the vector size.
    int randomized_select(std::vector<int> vec, int i) {
        return randomized_select_internal(vec, 0, vec.size() - 1, i);
    }

    int split_select(std::vector<int> vec, int i) {
        return split_select_internal(vec, 0, vec.size() - 1, i);
    }
}

// break array into smaller arrays of max size 5
// insertion sort each array
// get the median of each array
// get an array of these medians
// get the median of medians by a recursive call to this algo
// partition the array about the median of medians
// then recursive call on the left or right side depending median vs i
int split_select_internal(std::vector<int> &vec, int start, int end, int i) {
    // check for bottom-out
    int len = end - start + 1;
    if (len <= 1) {
        return start;
    }

    // initialize median map
    int num_whole_vecs = len / 5;
    int vecs_remainder = len % 5;
    int num_total_vecs = vecs_remainder > 0 ? num_whole_vecs + 1 : num_whole_vecs;
    std::vector<std::vector<int>> medians_vec(num_total_vecs);

    // initialize all median vectors
    // remainder vector is always last in median map
    for (int j = 0; j < num_whole_vecs; j++) {
        medians_vec[j] = std::vector<int>(5);
    }
    if (vecs_remainder > 0) {
        medians_vec[num_total_vecs - 1] = std::vector<int>(vecs_remainder);
    }

    // populate median map
    for (int j = 0; j < len; ++j) {
        medians_vec[j / 5][j % 5] = vec[start + j];
    }

    // intersion sort each median array
    // populate median elements array after sort
    std::vector<int> median_elements(num_total_vecs);
    for (int j = 0; j < num_total_vecs; j++) {
        std::vector<int> median_vec = medians_vec[j];
        for (int k = 1; k < median_vec.size(); k++) {
            int m = k - 1;
            while (m >= 0 && median_vec[m] > median_vec[m + 1]) {
                std::swap(median_vec[m], median_vec[m + 1]);
                --m;
            }
        }
        // want lower median if even, by convention
        median_elements[j] = median_vec[get_lower_median(median_vec.size())];
    }

    // get median of medians via recursive call
    int m_len = median_elements.size();
    int median_median_ind = split_select_internal(median_elements, 0, m_len - 1, get_lower_median(m_len));

    // partition about median_median
    // q is absolute, k is relative
    int q = selected_element_partition(vec, start, end, median_median_ind);
    int k = q - start;

    // recursively continue search
    if (i == k) {
        return vec.at(q);
    } else if (i < k) {
        return split_select_internal(vec, start, q - 1, i);
    } else {
        return split_select_internal(vec, q + 1, end, i - k);
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

int selected_element_partition(std::vector<int> &vec, int start, int end, int pivot_ind) {
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

int randomized_partition(std::vector<int> &vec, int start, int end) {
    int len = end - start + 1;
    int pivot_ind = start + std::rand() % len;
    return selected_element_partition(vec, start, end, pivot_ind);
}
