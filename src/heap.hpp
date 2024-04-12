#ifndef HEAPS_HEADER_HPP
#define HEAPS_HEADER_HPP

#include <vector>

namespace heaps {

    class Heap {

        public:
            int heap_size;
            int length;
            vector<int> &array;

            int left_child(int i);
            int right_child(int i);
            int parent(int i);

            int& operator[](unsigned int i) { }
            const int& operator[](unsigned int i) const { }

        Heap(vector<int> &vec);
    }

    void max_heapify(Heap &heap, int i);

    void build_max_heap(Heap &heap);

    void heap_sort(std::vector<int> &vec);
}

#endif // HEAPS_HEADER_HPP
