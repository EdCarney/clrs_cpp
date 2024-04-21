#include <vector>
#include <string>

namespace debug_utilities {

    void print_array(int arr[], int size, char* msg);

    void print_array(int arr[], int start, int end, char* msg);

    void print_vector(std::vector<int> vec, std::string msg);

    void print_vector(std::vector<int> vec, int start, int end, std::string msg);

}
