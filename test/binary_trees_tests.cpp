#include "../src/data_structures/binary_trees.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(BinaryTreesTests, InitialValues) {
    binary_trees::binary_tree b;

    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();

    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.min(), nullptr);
    EXPECT_EQ(b.max(), nullptr);
    EXPECT_EQ(b.search(0), nullptr);

    EXPECT_EQ(ordered.size(), 0);
}

TEST(BinaryTreesTests, SingleValueInsert) {
    binary_trees::binary_tree b;

    binary_trees::node *n = b.insert_node(0, "test");
    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();

    EXPECT_EQ(b.size(), 1);
    EXPECT_EQ(b.min(), n);
    EXPECT_EQ(b.max(), n);
    EXPECT_EQ(b.search(0), n);
    EXPECT_EQ(b.successor(n), nullptr);
    EXPECT_EQ(b.predecessor(n), nullptr);

    EXPECT_EQ(ordered.size(), 1);
    EXPECT_EQ(ordered.at(0), n);
}

TEST(BinaryTreesTests, SingleValueInsertDelete) {
    binary_trees::binary_tree b;

    binary_trees::node *n = b.insert_node(0, "test");
    b.delete_node(n);
    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();

    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.min(), nullptr);
    EXPECT_EQ(b.max(), nullptr);
    EXPECT_EQ(b.search(0), nullptr);
    EXPECT_EQ(b.successor(n), nullptr);
    EXPECT_EQ(b.predecessor(n), nullptr);

    EXPECT_EQ(ordered.size(), 0);
}

TEST(BinaryTreesTests, MultiValueInsert) {
    binary_trees::binary_tree b;

    binary_trees::node *n1 = b.insert_node(3, "test");
    binary_trees::node *n2 = b.insert_node(5, "test");
    binary_trees::node *n3 = b.insert_node(0, "test");
    binary_trees::node *n4 = b.insert_node(2, "test");
    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();
    std::vector<int> expected { 0, 2, 3, 5 };

    EXPECT_EQ(b.size(), 4);
    EXPECT_EQ(b.min(), n3);
    EXPECT_EQ(b.max(), n2);
    EXPECT_EQ(b.search(2), n4);
    EXPECT_EQ(b.successor(n1), n2);
    EXPECT_EQ(b.predecessor(n4), n3);

    EXPECT_EQ(ordered.size(), 4);
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i)->key);
    }
}

TEST(BinaryTreesTests, MultiValueInsertDeleteLeaf) {
    binary_trees::binary_tree b;

    binary_trees::node *n4 = b.insert_node(4, "test");
    binary_trees::node *n6 = b.insert_node(6, "test");
    binary_trees::node *n1 = b.insert_node(1, "test");
    binary_trees::node *n3 = b.insert_node(3, "test");
    binary_trees::node *n2 = b.insert_node(2, "test");
    binary_trees::node *n8 = b.insert_node(8, "test");
    binary_trees::node *n5 = b.insert_node(5, "test");
    binary_trees::node *n7 = b.insert_node(7, "test");

    b.delete_node(n2);

    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();
    std::vector<int> expected { 1, 3, 4, 5, 6, 7, 8};

    EXPECT_EQ(b.size(), 7);
    EXPECT_EQ(b.min(), n1);
    EXPECT_EQ(b.max(), n8);
    EXPECT_EQ(b.search(2), nullptr);
    EXPECT_EQ(b.successor(n7), n8);
    EXPECT_EQ(b.predecessor(n5), n4);

    EXPECT_EQ(ordered.size(), expected.size());
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i)->key);
    }
}

TEST(BinaryTreesTests, MultiValueInsertDeleteWithOneChild) {
    binary_trees::binary_tree b;

    binary_trees::node *n4 = b.insert_node(4, "test");
    binary_trees::node *n6 = b.insert_node(6, "test");
    binary_trees::node *n1 = b.insert_node(1, "test");
    binary_trees::node *n3 = b.insert_node(3, "test");
    binary_trees::node *n2 = b.insert_node(2, "test");
    binary_trees::node *n8 = b.insert_node(8, "test");
    binary_trees::node *n5 = b.insert_node(5, "test");
    binary_trees::node *n7 = b.insert_node(7, "test");

    b.delete_node(n3);

    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();
    std::vector<int> expected { 1, 2, 4, 5, 6, 7, 8 };

    EXPECT_EQ(b.size(), 7);
    EXPECT_EQ(b.min(), n1);
    EXPECT_EQ(b.max(), n8);
    EXPECT_EQ(b.search(3), nullptr);
    EXPECT_EQ(b.successor(n7), n8);
    EXPECT_EQ(b.predecessor(n5), n4);

    EXPECT_EQ(ordered.size(), expected.size());
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i)->key);
    }
}

TEST(BinaryTreesTests, MultiValueInsertDeleteWithBothChildren) {
    binary_trees::binary_tree b;

    binary_trees::node *n4 = b.insert_node(4, "test");
    binary_trees::node *n6 = b.insert_node(6, "test");
    binary_trees::node *n1 = b.insert_node(1, "test");
    binary_trees::node *n3 = b.insert_node(3, "test");
    binary_trees::node *n2 = b.insert_node(2, "test");
    binary_trees::node *n8 = b.insert_node(8, "test");
    binary_trees::node *n5 = b.insert_node(5, "test");
    binary_trees::node *n7 = b.insert_node(7, "test");

    b.delete_node(n8);

    std::vector<binary_trees::node*> ordered = b.get_ordered_nodes();
    std::vector<int> expected { 1, 2, 3, 4, 5, 6, 7 };

    EXPECT_EQ(b.size(), 7);
    EXPECT_EQ(b.min(), n1);
    EXPECT_EQ(b.max(), n7);
    EXPECT_EQ(b.search(8), nullptr);
    EXPECT_EQ(b.successor(n7), nullptr);
    EXPECT_EQ(b.predecessor(n5), n4);

    EXPECT_EQ(ordered.size(), expected.size());
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i)->key);
    }
}
