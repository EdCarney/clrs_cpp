#include "../src/data_structures/linked_lists.hpp"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, InitialValueTests) {
    linked_lists::DoublyLinkedList dl;

    EXPECT_EQ(nullptr, dl.get_head());
    EXPECT_EQ(nullptr, dl.get_tail());
    EXPECT_EQ(0, dl.get_size());
    EXPECT_TRUE(dl.is_empty());
}

TEST(DoublyLinkedListTest, SingleNodeTests) {
    linked_lists::DoublyLinkedList dl;
    dl.insert_node(1);

    EXPECT_NE(nullptr, dl.get_head());
    EXPECT_NE(nullptr, dl.get_tail());
    EXPECT_EQ(1, dl.get_size());
    EXPECT_FALSE(dl.is_empty());

    linked_lists::d_node *n = dl.search_node(1);

    EXPECT_EQ(1, n->val);
    EXPECT_EQ(nullptr, n->next);
    EXPECT_EQ(nullptr, n->prev);
}

TEST(DoublyLinkedListTest, MultiNodeTests) {
    linked_lists::DoublyLinkedList dl;
    dl.insert_node(1);
    dl.insert_node(2);
    dl.insert_node(3);

    EXPECT_NE(nullptr, dl.get_head());
    EXPECT_NE(nullptr, dl.get_tail());
    EXPECT_EQ(3, dl.get_size());
    EXPECT_FALSE(dl.is_empty());

    linked_lists::d_node *n1 = dl.search_node(1);
    linked_lists::d_node *n2 = dl.search_node(2);
    linked_lists::d_node *n3 = dl.search_node(3);

    EXPECT_EQ(1, n1->val);
    EXPECT_EQ(2, n2->val);
    EXPECT_EQ(3, n3->val);
}

TEST(DoublyLinkedListTest, MultiNodeWithDeleteTests) {
    linked_lists::DoublyLinkedList dl;
    dl.insert_node(1);
    dl.insert_node(2);
    dl.insert_node(3);

    dl.delete_node(2);
    dl.delete_node(1);

    EXPECT_NE(nullptr, dl.get_head());
    EXPECT_NE(nullptr, dl.get_tail());
    EXPECT_EQ(1, dl.get_size());
    EXPECT_FALSE(dl.is_empty());

    linked_lists::d_node *n = dl.search_node(3);

    EXPECT_EQ(3, n->val);

    dl.delete_node(3);

    EXPECT_EQ(nullptr, dl.get_head());
    EXPECT_EQ(nullptr, dl.get_tail());
    EXPECT_EQ(0, dl.get_size());
    EXPECT_TRUE(dl.is_empty());
}

TEST(DoublyLinkedListTest, MultiNodeWithDeleteAddTests) {
    linked_lists::DoublyLinkedList dl;
    dl.insert_node(1);
    dl.insert_node(2);
    dl.insert_node(3);

    dl.delete_node(2);
    dl.delete_node(1);

    EXPECT_NE(nullptr, dl.get_head());
    EXPECT_NE(nullptr, dl.get_tail());
    EXPECT_EQ(1, dl.get_size());
    EXPECT_FALSE(dl.is_empty());

    linked_lists::d_node *n = dl.search_node(3);

    EXPECT_EQ(3, n->val);

    dl.insert_node(1);
    dl.insert_node(2);
    dl.insert_node(4);

    EXPECT_NE(nullptr, dl.get_head());
    EXPECT_NE(nullptr, dl.get_tail());
    EXPECT_EQ(4, dl.get_size());
    EXPECT_FALSE(dl.is_empty());
}

TEST(SinglyLinkedListTest, InitialValueTests) {
    linked_lists::SinglyLinkedList sl;

    EXPECT_EQ(nullptr, sl.get_head());
    EXPECT_EQ(nullptr, sl.get_tail());
    EXPECT_EQ(0, sl.get_size());
    EXPECT_TRUE(sl.is_empty());
}

TEST(SinglyLinkedListTest, SingleNodeTests) {
    linked_lists::SinglyLinkedList sl;
    sl.insert_node(1);

    EXPECT_NE(nullptr, sl.get_head());
    EXPECT_NE(nullptr, sl.get_tail());
    EXPECT_EQ(1, sl.get_size());
    EXPECT_FALSE(sl.is_empty());

    linked_lists::s_node *n = sl.search_node(1);

    EXPECT_EQ(1, n->val);
    EXPECT_EQ(nullptr, n->next);
}

TEST(SinglyLinkedListTest, MultiNodeTests) {
    linked_lists::SinglyLinkedList sl;
    sl.insert_node(1);
    sl.insert_node(2);
    sl.insert_node(3);

    EXPECT_NE(nullptr, sl.get_head());
    EXPECT_NE(nullptr, sl.get_tail());
    EXPECT_EQ(3, sl.get_size());
    EXPECT_FALSE(sl.is_empty());

    linked_lists::s_node *n1 = sl.search_node(1);
    linked_lists::s_node *n2 = sl.search_node(2);
    linked_lists::s_node *n3 = sl.search_node(3);

    EXPECT_EQ(1, n1->val);
    EXPECT_EQ(2, n2->val);
    EXPECT_EQ(3, n3->val);
}

TEST(SinglyLinkedListTest, MultiNodeWithDeleteTests) {
    linked_lists::SinglyLinkedList sl;
    sl.insert_node(1);
    sl.insert_node(2);
    sl.insert_node(3);

    sl.delete_node(2);
    sl.delete_node(1);

    EXPECT_NE(nullptr, sl.get_head());
    EXPECT_NE(nullptr, sl.get_tail());
    EXPECT_EQ(1, sl.get_size());
    EXPECT_FALSE(sl.is_empty());

    linked_lists::s_node *n = sl.search_node(3);

    EXPECT_EQ(3, n->val);

    sl.delete_node(3);

    EXPECT_EQ(nullptr, sl.get_head());
    EXPECT_EQ(nullptr, sl.get_tail());
    EXPECT_EQ(0, sl.get_size());
    EXPECT_TRUE(sl.is_empty());
}

TEST(SinglyLinkedListTest, MultiNodeWithDeleteAddTests) {
    linked_lists::SinglyLinkedList sl;
    sl.insert_node(1);
    sl.insert_node(2);
    sl.insert_node(3);

    sl.delete_node(2);
    sl.delete_node(1);

    EXPECT_NE(nullptr, sl.get_head());
    EXPECT_NE(nullptr, sl.get_tail());
    EXPECT_EQ(1, sl.get_size());
    EXPECT_FALSE(sl.is_empty());

    linked_lists::s_node *n = sl.search_node(3);

    EXPECT_EQ(3, n->val);

    sl.insert_node(1);
    sl.insert_node(2);
    sl.insert_node(4);

    EXPECT_NE(nullptr, sl.get_head());
    EXPECT_NE(nullptr, sl.get_tail());
    EXPECT_EQ(4, sl.get_size());
    EXPECT_FALSE(sl.is_empty());
}
