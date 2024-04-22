#include "../src/sorting_and_ordering/selection.hpp"
#include "utilities.hpp"

const int NUM_ARRAYS = 100;

TEST(SelectionTestsRandom, SingleElementVecMin) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 0);
    EXPECT_EQ(vec.at(0), val);
}

TEST(SelectionTestsRandom, SingleElementVecMax) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 1);
    EXPECT_EQ(vec.at(0), val);
}

TEST(SelectionTestsRandom, SingleElementVecMaxPlus) {
    std::vector<int> vec { 1 };
    int val = selection::randomized_select(vec, 2);
    EXPECT_EQ(vec.at(0), val);
}

TEST(SelectionTestsRandom, MultiElementVecIth) {
    std::vector<int> vec { 4, 6, 1, 19, -2, 3 };
    int val = selection::randomized_select(vec, 4);
    EXPECT_EQ(6, val);
}

TEST(SelectionTestsRandom, MultiElementVecMin) {
	srand(time(NULL));
	std::unordered_map<int, int> vec_map_pre;
	std::unordered_map<int, int> vec_map_post;
	for (int i = 0; i < NUM_ARRAYS; i++) {
        std::vector<int> vec = generate_random_vector();
        populate_vector_map(vec_map_pre, vec);
        
        int min_ind = min_vector_ind(vec);
        int val = selection::randomized_select(vec, 0);

        populate_vector_map(vec_map_post, vec);
        expect_maps_equal(vec_map_pre, vec_map_post);
	}
}

TEST(SelectionTestsRandom, MultiElementVecMax) {
	srand(time(NULL));
	std::unordered_map<int, int> vec_map_pre;
	std::unordered_map<int, int> vec_map_post;
	for (int i = 0; i < NUM_ARRAYS; i++) {
        std::vector<int> vec = generate_random_vector();
        populate_vector_map(vec_map_pre, vec);
        
        int max_ind = max_vector_ind(vec);
        int val = selection::randomized_select(vec, vec.size() - 1);

        populate_vector_map(vec_map_post, vec);
        expect_maps_equal(vec_map_pre, vec_map_post);
	}
}

TEST(SelectionTestsSplit, SingleElementVecMin) {
    std::vector<int> vec { 1 };
    int val = selection::split_select(vec, 0);
    EXPECT_EQ(1, val);
}

TEST(SelectionTestsSplit, SingleElementVecMax) {
    std::vector<int> vec { 1 };
    int val = selection::split_select(vec, 1);
    EXPECT_EQ(1, val);
}

TEST(SelectionTestsSplit, SingleElementVecMaxPlus) {
    std::vector<int> vec { 1 };
    int val = selection::split_select(vec, 2);
    EXPECT_EQ(1, val);
}

TEST(SelectionTestsSplit, MultiElementVecIth_1) {
    std::vector<int> vec { 4, 6, 1, 19, -2, 3 };
    int val = selection::split_select(vec, 0);
    EXPECT_EQ(-2, val);
}

TEST(SelectionTestsSplit, MultiElementVecIth_2) {
    std::vector<int> vec { 4, 6, 1, 19, -2, 3 };
    int val = selection::split_select(vec, 2);
    EXPECT_EQ(3, val);
}

TEST(SelectionTestsSpit, MultiElementVecMin) {
	srand(time(NULL));
	std::unordered_map<int, int> vec_map_pre;
	std::unordered_map<int, int> vec_map_post;
	for (int i = 0; i < NUM_ARRAYS; i++) {
        std::vector<int> vec = generate_random_vector();
        populate_vector_map(vec_map_pre, vec);
        
        int min_ind = min_vector_ind(vec);
        int val = selection::split_select(vec, 0);

        populate_vector_map(vec_map_post, vec);
        expect_maps_equal(vec_map_pre, vec_map_post);
	}
}

TEST(SelectionTestsSplit, MultiElementVecMax) {
	srand(time(NULL));
	std::unordered_map<int, int> vec_map_pre;
	std::unordered_map<int, int> vec_map_post;
	for (int i = 0; i < NUM_ARRAYS; i++) {
        std::vector<int> vec = generate_random_vector();
        populate_vector_map(vec_map_pre, vec);
        
        int max_ind = max_vector_ind(vec);
        int val = selection::split_select(vec, vec.size() - 1);

        populate_vector_map(vec_map_post, vec);
        expect_maps_equal(vec_map_pre, vec_map_post);
	}
}
