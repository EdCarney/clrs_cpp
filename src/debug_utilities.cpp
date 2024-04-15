#include <vector>
#include <iostream>

namespace debug_utilities {

    void print_array(int arr[], int size, char* msg) {
        printf("%s: [ ", msg);
        for (int i = 0; i < size; i++) {
            printf("%d, ", arr[i]);
        }
        printf("]\n");
    }
            
    void print_vector(std::vector<int> vec, std::string msg) {
        std::cout << msg << ": [ ";
        for (auto &elm : vec) {
            std::cout << elm << ", ";
        }
        std::cout << "]" << std::endl;
    }
}
