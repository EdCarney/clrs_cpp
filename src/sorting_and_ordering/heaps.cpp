#include "heaps.hpp"
#include <vector>
#include <limits.h>

namespace heaps {

    int HeapBase::left_child(int i) {
        return i * 2 + 1;
    }

    int HeapBase::right_child(int i) {
        return (i + 1) * 2;
    }

    int HeapBase::parent(int i) {
        return (i - 1) / 2;
    }

    int& HeapBase::operator[](unsigned int i) {
        return elements[i];
    }

    const int& HeapBase::operator[](unsigned int i) const {
        return elements[i];
    }

    int MaxPriorityQueue::max() {
        return elements[0];
    }

    int MaxPriorityQueue::extract_max() {
        int max = this->max();
        elements[0] = elements[--size];
        max_heapify(*this, 0);
        return max;
    }

    void MaxPriorityQueue::insert(int key) {
        elements.push_back(INT_MIN);
        increase_key(size++, key);
    }

    void MaxPriorityQueue::increase_key(int i, int key) {
        elements[i] = key;
        while (parent(i) >= 0 && elements[parent(i)] < key) {
            int temp = elements[parent(i)];
            elements[parent(i)] = key;
            elements[i] = temp;
            i = parent(i);
        }
    }

    void max_heapify(HeapBase &heap, int i) {
        // assume children are proper max heaps
        int max_child_index = i;
        int l_child_index = heap.left_child(i);
        int r_child_index = heap.right_child(i);

        if (l_child_index < heap.size && heap[l_child_index] > heap[max_child_index]) {
            max_child_index = l_child_index;
        }
        if (r_child_index < heap.size && heap[r_child_index] > heap[max_child_index]) {
            max_child_index = r_child_index;
        }

        if (max_child_index != i) {
            int temp = heap[i];
            heap[i] = heap[max_child_index];
            heap[max_child_index] = temp;
            max_heapify(heap, max_child_index);
        }
    }

    void build_max_heap(HeapBase &heap) {
        int leaf_end = heap.size;

        while (leaf_end >= 0) {
            max_heapify(heap, leaf_end--);
        }
    }

    void heap_sort(std::vector<int> &vec) {
        Heap heap = Heap(vec);
        build_max_heap(heap);
        while (heap.size > 0) {
            int max_heap_index = --heap.size;
            int temp = heap[max_heap_index];
            heap[max_heap_index] = heap[0];
            heap[0] = temp;
            max_heapify(heap, 0);
        }
    }
}

