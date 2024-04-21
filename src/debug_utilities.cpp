#include "debug_utilities.hpp"
#include <vector>
#include <iostream>

namespace debug_utilities {

    void print_array(int arr[], int size, char* msg) {
        print_array(arr, 0, size - 1, msg);
    }
            
    void print_vector(std::vector<int> vec, std::string msg) {
        print_vector(vec, 0, vec.size() - 1, msg);
    }

    void print_array(int arr[], int start, int end, char* msg) {
        printf("%s: [ ", msg);
        for (int i = start; i <= end; i++) {
            printf("%d, ", arr[i]);
        }
        printf("]\n");
    }
            
    void print_vector(std::vector<int> vec, int start, int end, std::string msg) {
        std::cout << msg << ": [ ";
        for (int i = start; i <= end; i++) {
            std::cout << vec.at(i) << ", ";
        }
        std::cout << "]" << std::endl;
    }
}
