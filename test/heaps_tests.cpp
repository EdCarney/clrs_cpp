#include "../src/heaps.hpp"
#include "utilities.hpp"
#include <map>
#include <vector>

const int NUM_ARRAYS = 100;

TEST(HeapBase, InitHeapZeroElementVector) {
    std::vector<int> vec { };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.size, 0);
}

TEST(HeapBase, InitHeapSingleElementVector) {
    std::vector<int> vec { 1 };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.size, 1);
}

TEST(HeapBase, InitHeapMultiElementVector) {
    std::vector<int> vec { 1, 2, 3, 4 };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, MaxHeapifyZeroElementHeap) {
    std::vector<int> vec { };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::max_heapify(heap, 0);

	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, MaxHeapifySingleElementHeap) {
    std::vector<int> vec { 1 };
    heaps::Heap heap = heaps::Heap(vec);

    heaps::max_heapify(heap, 0);

	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, MaxHeapifyMultiElementHeap) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::max_heapify(heap, 0);

	EXPECT_EQ(3, heap[0]);
	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, BuildMaxHeapZeroElementHeap) {

    std::vector<int> vec { };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::build_max_heap(heap);

	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, BuildMaxHeapSingleElementHeap) {
    std::vector<int> vec { 1 };
    heaps::Heap heap = heaps::Heap(vec);

    heaps::build_max_heap(heap);

	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapBase, BuildMaxHeapMultiElementHeap) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::Heap heap = heaps::Heap(vec);
	
    heaps::build_max_heap(heap);

	EXPECT_EQ(4, heap[0]);
	EXPECT_EQ(heap.size, vec.size());
}

TEST(HeapSort, ZeroElementArray) {
    std::vector<int> vec { };
    heaps::heap_sort(vec);
	expect_vector_fwd_sorted(vec);
}

TEST(HeapSort, SingleElementArray) {
    std::vector<int> vec { 1 };
    heaps::heap_sort(vec);
	expect_vector_fwd_sorted(vec);
}

TEST(HeapSort, MultipleElementArrays) {
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

TEST(MaxPriorityQueue, MaxSingleElementArray) {
    std::vector<int> vec { 1 };
    heaps::MaxPriorityQueue queue(vec);

    int max = queue.max();

    EXPECT_EQ(vec[0], max);
}

TEST(MaxPriorityQueue, MaxMultiElementArray) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::MaxPriorityQueue queue(vec);

    int max = queue.max();

    EXPECT_EQ(4, max);
}

TEST(MaxPriorityQueue, ExtractSingleMaxSingleElementArray) {
    std::vector<int> vec { 1 };
    heaps::MaxPriorityQueue queue(vec);

    int max = queue.extract_max();

    EXPECT_EQ(vec[0], max);
    EXPECT_EQ(0, queue.size);
}

TEST(MaxPriorityQueue, ExtractSinlgeMaxMultiElementArray) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::MaxPriorityQueue queue(vec);

    int max = queue.extract_max();

    EXPECT_EQ(4, max);
    EXPECT_EQ(3, queue.size);
}

TEST(MaxPriorityQueue, ExtractMultiMaxMultiElementArray) {
    std::vector<int> vec { 1, 2, 3, 4 };
    std::vector<int> expected { 4, 3, 2, 1 };
    heaps::MaxPriorityQueue queue(vec);

    std::vector<int> maxes(4);
    for (int i = 0; i < vec.size(); i++) {
        maxes[i] = queue.extract_max();
    }

    expect_vectors_equal(maxes, expected);
    EXPECT_EQ(0, queue.size);
}

TEST(MaxPriorityQueue, InsertSingleZeroElementArray) {
    std::vector<int> vec { };
    heaps::MaxPriorityQueue queue(vec);

    queue.insert(1);
    int max = queue.max();

    EXPECT_EQ(1, queue.size);
    EXPECT_EQ(1, max);
}

TEST(MaxPriorityQueue, InsertMultipleZeroElementArray) {
    std::vector<int> vec { };
    heaps::MaxPriorityQueue queue(vec);

    queue.insert(1);
    queue.insert(5);
    queue.insert(7);
    queue.insert(3);
    queue.insert(2);
    int max = queue.max();

    EXPECT_EQ(5, queue.size);
    EXPECT_EQ(7, max);
}

TEST(MaxPriorityQueue, IncreaseSingleKeyMultipleElementArray) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::MaxPriorityQueue queue(vec);

    queue.increase_key(3, 7);
    int max = queue.max();

    EXPECT_EQ(4, queue.size);
    EXPECT_EQ(7, max);
}

TEST(MaxPriorityQueue, IncreaseMultipleKeyMultipleElementArray) {
    std::vector<int> vec { 1, 2, 3, 4 };
    heaps::MaxPriorityQueue queue(vec);

    queue.increase_key(3, 5);
    queue.increase_key(1, 6);
    queue.increase_key(2, 7);
    int max = queue.max();

    EXPECT_EQ(4, queue.size);
    EXPECT_EQ(7, max);
}
