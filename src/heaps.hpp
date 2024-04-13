#ifndef HEAPS_HEADER_HPP
#define HEAPS_HEADER_HPP

#include <vector>

namespace heaps {

    class HeapBase {
        public:
            int size;
            int array_length;
            std::vector<int> &elements;

            int left_child(int i);
            int right_child(int i);
            int parent(int i);

            int& operator[](unsigned int i);
            const int& operator[](unsigned int i) const;

            HeapBase(std::vector<int> &vec) : elements(vec) {
                elements = vec;
                size = elements.size();
                array_length = elements.size();
            }
    };

    class Heap : public HeapBase {

        public:
            Heap(std::vector<int> &vec) : HeapBase(vec) {
            }
    };

    void max_heapify(Heap &heap, int i);

    void build_max_heap(Heap &heap);

    void heap_sort(std::vector<int> &vec);
}

#endif // HEAPS_HEADER_HPP
