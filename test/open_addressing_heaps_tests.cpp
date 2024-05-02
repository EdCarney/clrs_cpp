#include "../src/data_structures/simple_heaps.hpp"
#include <gtest/gtest.h>

TEST(OpenAddressingLinearHeapTests, InitialValues) {
    heaps::open_addressing_heap h(1);

    EXPECT_EQ(nullptr, h.search_data(""));
}

TEST(OpenAddressingLinearHeapTests, SingleValueAdd) {
    heaps::open_addressing_heap h(1);

    h.insert_data(new heaps::entry { "test", 5 });
    heaps::entry *data = h.search_data("test");

    EXPECT_EQ(data->key, "test");
    EXPECT_EQ(data->val, 5);
}

TEST(OpenAddressingLinearHeapTests, MultiValueAdd) {
    heaps::open_addressing_heap h(100);

    h.insert_data(new heaps::entry { "test1", 5 });
    h.insert_data(new heaps::entry { "test2", 6 });
    h.insert_data(new heaps::entry { "test3", 7 });

    heaps::entry *data0 = h.search_data("test");
    heaps::entry *data1 = h.search_data("test1");
    heaps::entry *data2 = h.search_data("test2");
    heaps::entry *data3 = h.search_data("test3");

    EXPECT_EQ(data0, nullptr);
    EXPECT_EQ(data1->key, "test1");
    EXPECT_EQ(data1->val, 5);
    EXPECT_EQ(data2->key, "test2");
    EXPECT_EQ(data2->val, 6);
    EXPECT_EQ(data3->key, "test3");
    EXPECT_EQ(data3->val, 7);
}

TEST(OpenAddressingLinearHeapTests, MultiValueAddSameValue) {
    heaps::open_addressing_heap h(1000);

    h.insert_data(new heaps::entry { "test1", 5 });
    h.insert_data(new heaps::entry { "test2", 6 });
    h.insert_data(new heaps::entry { "test3", 7 });
    h.insert_data(new heaps::entry { "test2", 8 });

    heaps::entry *data0 = h.search_data("test");
    heaps::entry *data1 = h.search_data("test1");
    heaps::entry *data2 = h.search_data("test2");
    heaps::entry *data3 = h.search_data("test3");

    EXPECT_EQ(data0, nullptr);
    EXPECT_EQ(data1->key, "test1");
    EXPECT_EQ(data1->val, 5);
    EXPECT_EQ(data2->key, "test2");
    EXPECT_EQ(data2->val, 8);
    EXPECT_EQ(data3->key, "test3");
    EXPECT_EQ(data3->val, 7);
}

TEST(OpenAddressingLinearHeapTests, SingleValueAddDelete) {
    heaps::open_addressing_heap h(100);

    h.insert_data(new heaps::entry { "test", 5 });
    heaps::entry *data = h.search_data("test");

    EXPECT_EQ(data->key, "test");
    EXPECT_EQ(data->val, 5);

    h.delete_data(data);
    data = h.search_data("test");

    EXPECT_EQ(data, nullptr);
}
