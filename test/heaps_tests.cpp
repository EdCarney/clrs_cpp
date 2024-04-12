#include "../src/heaps.hpp"
#include <gtest/gtest.h>
#include <cstdio>
#include <vector>
#include <tuple>
#include <limits>

TEST(HeapsBase, InitHeapZeroElementVector) {
    std::vector<int> vec { };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.heap_size, 0);
	EXPECT_EQ(heap.length, 0);
}

TEST(HeapsBase, InitHeapSingleElementVector) {
    std::vector<int> vec { 1 };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.heap_size, 1);
	EXPECT_EQ(heap.length, 1);
}

TEST(HeapsBase, InitHeapMultiElementVector) {
    std::vector<int> vec { 1, 2, 3, 4 };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, MaxHeapifyZeroElementHeap) {
    std::vector<int> vec { };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::max_heapify(heap, 0);

	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, MaxHeapifySingleElementHeap) {
    std::vector<int> vec { 1 };
    heaps::Heap heap = heaps::Heap(vec);

    heaps::max_heapify(heap, 0);

	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, MaxHeapifyMultiElementHeap) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::max_heapify(heap, 0);

	EXPECT_EQ(3, heap[0]);
	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, BuildMaxHeapZeroElementHeap) {

    std::vector<int> vec { };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::build_max_heap(heap);

	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, BuildMaxHeapSingleElementHeap) {
    std::vector<int> vec { 1 };
    heaps::Heap heap = heaps::Heap(vec);

    heaps::build_max_heap(heap);

	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

TEST(HeapsBase, BuildMaxHeapMultiElementHeap) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::build_max_heap(heap);

	EXPECT_EQ(4, heap[0]);
	EXPECT_EQ(heap.heap_size, vec.size());
	EXPECT_EQ(heap.length, vec.size());
}

