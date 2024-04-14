#include "intervals.hpp"

using std::vector;

void quick_sort_internal(vector<intervals::Interval> intervals, int start, int end);
int quick_sort_partition_right(vector<intervals::Interval> intervals, int low, int start, int end);
int quick_sort_partition_left(vector<intervals::Interval> intervals, int high, int start, int end);

namespace intervals {

    void quick_sort(vector<Interval> intervals) {
        quick_sort_internal(intervals, 0, intervals.size());
    }

    Interval find_intersection(vector<Interval> intervals, int start, int end) {
        // take a random pivot
        int pivot_rand_ind = rand() % intervals.size();

        // move the pivot to the end
        Interval temp = intervals[end];
        intervals[end] = intervals[pivot_rand_ind];
        intervals[pivot_rand_ind] = temp;

        // get current values for comparison
        auto [intersection_min, intersection_max] = intervals[pivot_rand_ind];

        // find largest intersection in intervals
        for (int i = start; i < end; i++) {
            auto [min, max] = intervals[i];
            if (min < intersection_max && max > intersection_min) {
                intersection_min = min > intersection_min ? min : intersection_min;
                intersection_max = max < intersection_max ? max : intersection_max;
            }
        }
        return std::make_tuple(intersection_min, intersection_max);
    }

}

void quick_sort_internal(vector<intervals::Interval> intervals, int start, int end) {

}

int quick_sort_partition_right(vector<intervals::Interval> intervals, int low, int start, int end) {
    return 0;
}

int quick_sort_partition_left(vector<intervals::Interval> intervals, int high, int start, int end) {
    return 0;
}
