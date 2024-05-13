#include "../src/data_structures/treaps.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(TreapsTests, InitialValues) {
    treaps::treap tr;

    EXPECT_EQ(tr.size(), 0);
    EXPECT_EQ(tr.search_node(0), nullptr);
}

TEST(TreapsTests, SingleValueInsert) {
    treaps::treap tr;

    tr.insert_node(1, "test");
    auto n = tr.search_node(1);

    EXPECT_EQ(tr.size(), 1);
    EXPECT_EQ(n->key, 1);
    EXPECT_EQ(n->data, "test");
}

TEST(TreapsTests, SingleValueInsertDelete) {
    treaps::treap tr;

    tr.insert_node(1, "test");
    tr.delete_node(1);
    auto n = tr.search_node(1);

    EXPECT_EQ(tr.size(), 0);
    EXPECT_EQ(n, nullptr);
}

TEST(TreapsTests, MultiValueInsert) {
    treaps::treap tr;

    tr.insert_node(10, "test10");
    tr.insert_node(7, "test7");
    tr.insert_node(5, "test5");
    tr.insert_node(2, "test2");
    tr.insert_node(15, "test15");
    tr.insert_node(12, "test12");

    auto n5 = tr.search_node(5);
    auto n7 = tr.search_node(7);
    auto n12 = tr.search_node(12);

    EXPECT_EQ(tr.size(), 6);
    EXPECT_EQ(n5->key, 5);
    EXPECT_EQ(n5->data, "test5");
    EXPECT_EQ(n7->key, 7);
    EXPECT_EQ(n7->data, "test7");
    EXPECT_EQ(n12->key, 12);
    EXPECT_EQ(n12->data, "test12");
}

TEST(TreapsTests, MultiValueInsertDelete) {
    treaps::treap tr;

    tr.insert_node(10, "test10");
    tr.insert_node(7, "test7");
    tr.insert_node(5, "test5");
    tr.insert_node(2, "test2");
    tr.insert_node(15, "test15");
    tr.insert_node(12, "test12");

    tr.delete_node(10);
    tr.delete_node(2);
    tr.delete_node(15);

    auto n5 = tr.search_node(5);
    auto n7 = tr.search_node(7);
    auto n12 = tr.search_node(12);

    EXPECT_EQ(tr.size(), 3);
    EXPECT_EQ(n5->key, 5);
    EXPECT_EQ(n5->data, "test5");
    EXPECT_EQ(n7->key, 7);
    EXPECT_EQ(n7->data, "test7");
    EXPECT_EQ(n12->key, 12);
    EXPECT_EQ(n12->data, "test12");
}
