#include "../src/selection.hpp"
#include "utilities.hpp"

TEST(SelectionTests, SingleElementVecMin) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 0);
    EXPECT_EQ(vec.at(0), val);
}

TEST(SelectionTests, SingleElementVecMax) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 1);
    EXPECT_EQ(vec.at(0), val);
}

TEST(SelectionTests, SingleElementVecMaxPlus) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 2);
    EXPECT_EQ(vec.at(0), val);
}
