#include <vector>
#include <tuple>

namespace intervals {

    typedef std::tuple<int, int> Interval;

    void quick_sort(std::vector<Interval> intervals);

    Interval find_intersection(std::vector<Interval> intervals);

}
