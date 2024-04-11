#include "heaps.hpp"
#include <vector>

namespace heaps {

    Heap::Heap(std::vector<int> vec) {
        heap_size = array.size();
        length = array.size();
        array = std::vector(vec);
    }

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

    void max_heapify(Heap heap, int i) {
        // assume children are proper max heaps
        int max_child_index = i;
        int left_child_index = heap.left_child(i);
        int right_child_index = heap.right_child(i);

        if (left_child_index < heap.heap_size && heap[left_child_index] > heap[max_child_index]) {
            max_child_index = left_child_index;
        }
        if (right_child_index < heap.heap_size && heap[right_child_index] > heap[max_child_index]) {
            max_child_index = right_child_index;
        }

        if (max_child_index != i) {
            int temp = heap[i];
            heap[i] = heap[max_child_index];
            heap[max_child_index] = temp;
            max_heapify(heap, max_child_index);
        }
    }

    void build_max_heap(Heap heap) {
        int leaf_end = heap.length / 2;

        while (leaf_end >= 0) {
            max_heapify(heap, leaf_end--);
        }
    }

    void heap_sort(std::vector<int> vec) {
        Heap heap = Heap(vec);
        build_max_heap(heap);
        while (heap.heap_size > 1) {
            int max_heap_index = heap.heap_size - 1;
            int temp = heap[max_heap_index];
            heap[max_heap_index] = heap[0];
            heap[0] = heap[max_heap_index];
            max_heapify(heap, 0);
            --heap.heap_size;
        }
    }
}

