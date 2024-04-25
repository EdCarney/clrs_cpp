#include "../src/data_structures/simple_heaps.hpp"
#include <gtest/gtest.h>

TEST(SimpleDivisionHeapTests, InitialValue) {
    heaps::heap h(heaps::Division, 1567);

    EXPECT_EQ(nullptr, h.search_data(""));
}

TEST(SimpleDivisionHeapTests, SingleValue) {
    heaps::heap h(heaps::Division, 1567);

    h.insert_data(new heaps::entry { "test", 5 });
    heaps::entry *data = h.search_data("test");

    EXPECT_EQ(data->key, "test");
    EXPECT_EQ(data->val, 5);
}

TEST(SimpleMultiplicationHeapTests, InitialValue) {
    heaps::heap h(heaps::Multiplication, 16384);

    EXPECT_EQ(nullptr, h.search_data(""));
}

