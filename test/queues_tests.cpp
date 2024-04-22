#include "../src/data_structures/queues.hpp"
#include <gtest/gtest.h>

TEST(QueueTests, InitialValueTests) {
    queues::Queue q(1);

    EXPECT_TRUE(q.is_empty());
    EXPECT_FALSE(q.is_full());
    EXPECT_EQ(1, q.get_size());
}

TEST(QueueTests, SingleValueEnDeQueue) {
    queues::Queue q(1);
    q.enqueue(1);

    EXPECT_FALSE(q.is_empty());
    EXPECT_TRUE(q.is_full());
    EXPECT_EQ(1, q.get_size());
    EXPECT_EQ(1, q.peek());
    
    int val = q.dequeue();

    EXPECT_EQ(1, val);
    EXPECT_TRUE(q.is_empty());
    EXPECT_FALSE(q.is_full());
    EXPECT_EQ(1, q.get_size());
}

TEST(QueueTests, MultiValueEnDeQueue) {
    queues::Queue q(3);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(-3);

    EXPECT_FALSE(q.is_empty());
    EXPECT_TRUE(q.is_full());
    EXPECT_EQ(3, q.get_size());
    EXPECT_EQ(1, q.peek());
    
    int val = q.dequeue();

    EXPECT_EQ(1, val);
    EXPECT_FALSE(q.is_empty());
    EXPECT_FALSE(q.is_full());
    EXPECT_EQ(3, q.get_size());
    EXPECT_EQ(5, q.peek());

    val = q.dequeue();

    EXPECT_EQ(5, val);
    EXPECT_FALSE(q.is_empty());
    EXPECT_FALSE(q.is_full());
    EXPECT_EQ(3, q.get_size());
    EXPECT_EQ(-3, q.peek());

    val = q.dequeue();

    EXPECT_EQ(-3, val);
    EXPECT_TRUE(q.is_empty());
    EXPECT_FALSE(q.is_full());
    EXPECT_EQ(3, q.get_size());
}

TEST(QueueTests, UnderflowCheck) {
    queues::Queue q(3);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(-3);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    EXPECT_THROW({
        try {
            q.dequeue();
        }
        catch (const std::runtime_error e) {
            EXPECT_STREQ("Queue underflow", e.what());
            throw e;
        }
    }, std::runtime_error);
}

TEST(QueueTests, OverflowCheck) {
    queues::Queue q(3);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(-3);

    EXPECT_THROW({
        try {
            q.enqueue(8);
        }
        catch (const std::runtime_error e) {
            EXPECT_STREQ("Queue overflow", e.what());
            throw e;
        }
    }, std::runtime_error);
}
