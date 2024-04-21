#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

#include <gtest/gtest.h>
#include <vector>
#include <tuple>

void expect_array_fwd_sorted(int arr[], int size);

void expect_vector_fwd_sorted(std::vector<int> vec);

void expect_maps_equal(std::unordered_map<int, int> arr_map_1, std::unordered_map<int, int> arr_map_2);

void expect_vectors_equal(std::vector<int> vec_1, std::vector<int> vec_2);

std::tuple<int*, int> generate_random_array();

std::vector<int> generate_random_vector();

void populate_array_map(std::unordered_map<int, int> arr_map, int arr[], int size);

void populate_vector_map(std::unordered_map<int, int> vec_map, std::vector<int> vec);

int max_vector_ind(std::vector<int> vec);

int min_vector_ind(std::vector<int> vec);

int max_array_ind(int arr[], int size);

int min_array_ind(int arr[], int size);

#endif // UTILITIES_HPP_INCLUDED
