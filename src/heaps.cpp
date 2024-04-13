#include "heaps.hpp"
#include <cstdio>
#include <vector>

namespace heaps {

    int Heap::left_child(int i) {
        return i * 2 + 1;
    }

    int Heap::right_child(int i) {
        return (i + 1) * 2;
    }

    int Heap::parent(int i) {
        return (i - 1) / 2;
    }

    int& Heap::operator[](unsigned int i) {
        return array[i];
    }

    const int& Heap::operator[](unsigned int i) const {
        return array[i];
    }

    void max_heapify(Heap &heap, int i) {
        // assume children are proper max heaps
        int max_child_index = i;
        int l_child_index = heap.left_child(i);
        int r_child_index = heap.right_child(i);

        if (l_child_index < heap.heap_size && heap[l_child_index] > heap[max_child_index]) {
            max_child_index = l_child_index;
        }
        if (r_child_index < heap.heap_size && heap[r_child_index] > heap[max_child_index]) {
            max_child_index = r_child_index;
        }

        if (max_child_index != i) {
            int temp = heap[i];
            heap[i] = heap[max_child_index];
            heap[max_child_index] = temp;
            max_heapify(heap, max_child_index);
        }
    }

    void build_max_heap(Heap &heap) {
        int leaf_end = heap.heap_size;

        while (leaf_end >= 0) {
            max_heapify(heap, leaf_end--);
        }
    }

    void heap_sort(std::vector<int> &vec) {
        Heap heap = Heap(vec);
        build_max_heap(heap);
        while (heap.heap_size > 0) {
            int max_heap_index = --heap.heap_size;
            int temp = heap[max_heap_index];
            heap[max_heap_index] = heap[0];
            heap[0] = temp;
            max_heapify(heap, 0);
        }
    }
}

