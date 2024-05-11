#include "../src/data_structures/red_black_trees.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(RedBlackTreesTests, InitialValues) {
    rb_trees::rb_tree rb;

    EXPECT_EQ(rb.size(), 0);
    EXPECT_EQ(rb.min(), nullptr);
    EXPECT_EQ(rb.max(), nullptr);
}

TEST(RedBlackTreesTests, SingleValueInsert) {
    rb_trees::rb_tree rb;

    rb.insert_node(0, "test");
    auto min = rb.min();
    auto max = rb.max();
    auto n = rb.search_node(0);

    EXPECT_EQ(min, n);
    EXPECT_EQ(max, n);
    EXPECT_EQ(n->key, 0);
    EXPECT_EQ(n->data, "test");
}

TEST(RedBlackTreesTests, MultiValueInsert_InOrder) {
    rb_trees::rb_tree rb;

    rb.insert_node(0, "test0");
    rb.insert_node(1, "test1");
    rb.insert_node(2, "test2");
    rb.insert_node(3, "test3");
    auto min = rb.min();
    auto max = rb.max();
    auto n = rb.search_node(2);

    EXPECT_EQ(min->key, 0);
    EXPECT_EQ(min->data, "test0");
    EXPECT_EQ(max->key, 3);
    EXPECT_EQ(max->data, "test3");
    EXPECT_EQ(n->key, 2);
    EXPECT_EQ(n->data, "test2");
}
