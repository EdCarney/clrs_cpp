#ifndef HEAPS_HPP_INCLUDED
#define HEAPS_HPP_INCLUDED

#include <vector>

namespace heaps {

    class HeapBase {
        public:
            int size;
            std::vector<int> &elements;

            int left_child(int i);
            int right_child(int i);
            int parent(int i);

            int& operator[](unsigned int i);
            const int& operator[](unsigned int i) const;

            HeapBase(std::vector<int> &vec) : elements(vec) {
                elements = vec;
                size = elements.size();
            }
    };

    void max_heapify(HeapBase &heap, int i);

    void build_max_heap(HeapBase &heap);

    void heap_sort(std::vector<int> &vec);

    class Heap : public HeapBase {
        public:
            Heap(std::vector<int> &vec) : HeapBase(vec) {
            }
    };

    class MaxPriorityQueue : public HeapBase {
        public:
            int max();
            int extract_max();
            void insert(int key);
            void increase_key(int i, int key_value);

            MaxPriorityQueue(std::vector<int> &vec) : HeapBase(vec) {
                build_max_heap(*this);
            }
    };
}

#endif // HEAPS_HPP_INCLUDED
