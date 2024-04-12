#ifndef HEAPS_HEADER_HPP
#define HEAPS_HEADER_HPP

#include <vector>

namespace heaps {

    class Heap {

        public:
            int heap_size;
            int length;
            std::vector<int> &array;

            int left_child(int i);
            int right_child(int i);
            int parent(int i);

            int& operator[](unsigned int i);
            const int& operator[](unsigned int i) const;

            Heap(std::vector<int> &vec) : array(vec) {
                array = vec;
                heap_size = array.size();
                length = array.size();
            }
    };

    void max_heapify(Heap &heap, int i);

    void build_max_heap(Heap &heap);

    void heap_sort(std::vector<int> &vec);
}

#endif // HEAPS_HEADER_HPP
