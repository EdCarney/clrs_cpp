#include "../src/data_structures/stacks.hpp"
#include <gtest/gtest.h>

TEST(StackTests, InitialValueTests) {
    stacks::Stack s(1);

    EXPECT_TRUE(s.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_EQ(1, s.get_size());
}

TEST(StackTests, SingleValuePushPop) {
    stacks::Stack s(1);
    s.push(1);

    EXPECT_FALSE(s.is_empty());
    EXPECT_TRUE(s.is_full());
    EXPECT_EQ(1, s.get_size());
    EXPECT_EQ(1, s.top());

    int val = s.pop();

    EXPECT_EQ(1, val);
    EXPECT_TRUE(s.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_EQ(1, s.get_size());
}

TEST(StackTests, MultiValuePushPop) {
    stacks::Stack s(3);
    s.push(1);
    s.push(5);
    s.push(-3);

    EXPECT_FALSE(s.is_empty());
    EXPECT_TRUE(s.is_full());
    EXPECT_EQ(3, s.get_size());
    EXPECT_EQ(-3, s.top());
    
    int val = s.pop();

    EXPECT_EQ(-3, val);
    EXPECT_FALSE(s.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_EQ(3, s.get_size());
    EXPECT_EQ(5, s.top());

    val = s.pop();

    EXPECT_EQ(5, val);
    EXPECT_FALSE(s.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_EQ(3, s.get_size());
    EXPECT_EQ(1, s.top());

    val = s.pop();

    EXPECT_EQ(1, val);
    EXPECT_TRUE(s.is_empty());
    EXPECT_FALSE(s.is_full());
    EXPECT_EQ(3, s.get_size());
}

TEST(StackTests, UnderflowCheck) {
    stacks::Stack s(3);
    s.push(1);
    s.push(5);
    s.push(-3);

    s.pop();
    s.pop();
    s.pop();

    EXPECT_THROW({
        try {
            s.pop();
        }
        catch (const std::runtime_error e) {
            EXPECT_STREQ("Stack underflow", e.what());
            throw e;
        }
    }, std::runtime_error);
}

TEST(StackTests, OverflowCheck) {
    stacks::Stack s(3);
    s.push(1);
    s.push(5);
    s.push(-3);

    EXPECT_THROW({
        try {
            s.push(8);
        }
        catch (const std::runtime_error e) {
            EXPECT_STREQ("Stack overflow", e.what());
            throw e;
        }
    }, std::runtime_error);
}
