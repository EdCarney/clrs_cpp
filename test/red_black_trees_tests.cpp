#include "../src/data_structures/red_black_trees.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(RedBlackTreesTests, InitialValues) {
    rb_trees::rb_tree rb;

    EXPECT_EQ(rb.size(), 0);
    EXPECT_EQ(rb.min(), nullptr);
    EXPECT_EQ(rb.max(), nullptr);
    EXPECT_TRUE(rb.is_valid_rb_tree());
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
    EXPECT_TRUE(rb.is_valid_rb_tree());
}

TEST(RedBlackTreesTests, SingleValueInsertDelete) {
    rb_trees::rb_tree rb;

    rb.insert_node(0, "test");
    rb.delete_node(0);

    EXPECT_EQ(rb.size(), 0);
    EXPECT_EQ(rb.search_node(0), nullptr);
    EXPECT_EQ(rb.min(), nullptr);
    EXPECT_EQ(rb.max(), nullptr);
    EXPECT_TRUE(rb.is_valid_rb_tree());
}

TEST(RedBlackTreesTests, MultiValueInsert_InOrder) {
    rb_trees::rb_tree rb;

    rb.insert_node(0, "test0");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(1, "test1");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(2, "test2");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(3, "test3");
    EXPECT_TRUE(rb.is_valid_rb_tree());

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

TEST(RedBlackTreesTests, MultiValueInsert_InOrder_2) {
    rb_trees::rb_tree rb;

    rb.insert_node(2, "test2");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(0, "test0");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(3, "test3");
    EXPECT_TRUE(rb.is_valid_rb_tree());

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

TEST(RedBlackTreesTests, MultiValueInsertDelete_InOrder) {
    rb_trees::rb_tree rb;

    rb.insert_node(0, "test0");
    rb.insert_node(1, "test1");
    rb.insert_node(2, "test2");
    rb.insert_node(3, "test3");
    rb.delete_node(1);
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.delete_node(2);
    EXPECT_TRUE(rb.is_valid_rb_tree());

    auto min = rb.min();
    auto max = rb.max();
    auto n = rb.search_node(3);

    EXPECT_EQ(min->key, 0);
    EXPECT_EQ(min->data, "test0");
    EXPECT_EQ(max->key, 3);
    EXPECT_EQ(max->data, "test3");
    EXPECT_EQ(n->key, 3);
    EXPECT_EQ(n->data, "test3");
}

TEST(RedBlackTreesTests, MultiValueInsert_RandomOrder) {
    rb_trees::rb_tree rb;

    rb.insert_node(12, "test12");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(7, "test7");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(0, "test0");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(13, "test13");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(110, "test110");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(2, "test2");
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.insert_node(10, "test10");
    EXPECT_TRUE(rb.is_valid_rb_tree());

    auto min = rb.min();
    auto max = rb.max();
    auto n7 = rb.search_node(7);
    auto n13 = rb.search_node(13);
    auto n2 = rb.search_node(2);

    EXPECT_EQ(min->key, 0);
    EXPECT_EQ(min->data, "test0");
    EXPECT_EQ(max->key, 110);
    EXPECT_EQ(max->data, "test110");
    EXPECT_EQ(n7->key, 7);
    EXPECT_EQ(n7->data, "test7");
    EXPECT_EQ(n13->key, 13);
    EXPECT_EQ(n13->data, "test13");
    EXPECT_EQ(n2->key, 2);
    EXPECT_EQ(n2->data, "test2");
}

TEST(RedBlackTreesTests, MultiValueInsertDelete_RandomOrder) {
    rb_trees::rb_tree rb;

    rb.insert_node(12, "test12");
    rb.insert_node(7, "test7");
    rb.insert_node(0, "test0");
    rb.insert_node(13, "test13");
    rb.insert_node(110, "test110");
    rb.insert_node(2, "test2");
    rb.insert_node(10, "test10");

    rb.delete_node(12);
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.delete_node(7);
    EXPECT_TRUE(rb.is_valid_rb_tree());
    rb.delete_node(10);
    EXPECT_TRUE(rb.is_valid_rb_tree());

    auto min = rb.min();
    auto max = rb.max();
    auto n13 = rb.search_node(13);
    auto n2 = rb.search_node(2);

    EXPECT_EQ(min->key, 0);
    EXPECT_EQ(min->data, "test0");
    EXPECT_EQ(max->key, 110);
    EXPECT_EQ(max->data, "test110");
    EXPECT_EQ(n13->key, 13);
    EXPECT_EQ(n13->data, "test13");
    EXPECT_EQ(n2->key, 2);
    EXPECT_EQ(n2->data, "test2");
}
