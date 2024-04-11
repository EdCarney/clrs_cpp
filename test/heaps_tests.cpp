#include "../src/heaps.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <limits>

TEST(HeapsBase, InitHeapZeroElementVector) {
    std::vector<int> vec { };

    heaps::Heap heap = heaps::Heap(vec);
	
	EXPECT_EQ(heap.heap_size, 0);
	EXPECT_EQ(heap.length, 0);
}
