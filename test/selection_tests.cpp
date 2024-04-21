#include "../src/selection.hpp"
#include "utilities.hpp"

const int NUM_ARRAYS = 100;

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

TEST(SelectionTests, MultiElementVecIth) {
    std::vector<int> vec { 4, 6, 1, 19, -2, 3 };
    int val = selection::randomized_select(vec, 4);
    EXPECT_EQ(6, val);
}

TEST(SelectionTests, MultiElementVecMin) {
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

TEST(SelectionTests, MultiElementVecMax) {
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
