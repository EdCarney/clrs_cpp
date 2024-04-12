#include "../src/heaps.hpp"
#include "utilities.hpp"
#include <map>
#include <vector>

const int NUM_ARRAYS = 100;

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

TEST(HeapSortTests, ZeroElementArray) {
    std::vector<int> vec { };
    heaps::heap_sort(vec);
	expect_vector_fwd_sorted(vec);
}

TEST(HeapSortTests, SingleElementArray) {
    std::vector<int> vec { 1 };
    heaps::heap_sort(vec);
	expect_vector_fwd_sorted(vec);
}

TEST(HeapSortTests, MultipleElementArrays) {
	srand(time(NULL));
	std::unordered_map<int, int> vec_map_original;
	std::unordered_map<int, int> vec_map_sorted;
	for (int i = 0; i < NUM_ARRAYS; i++) {
        std::vector<int> vec = generate_random_vector();

		populate_vector_map(vec_map_original, vec);
        heaps::heap_sort(vec);
		populate_vector_map(vec_map_sorted, vec);

		expect_vector_fwd_sorted(vec);
		expect_maps_equal(vec_map_original, vec_map_sorted);
	}
}
