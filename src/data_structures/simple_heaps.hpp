#ifndef SIMPLE_HEAP_HPP_INCLUDED
#define SIMPLE_HEAP_HPP_INCLUDED

#include <string>
#include <vector>
#include <climits>

namespace heaps {

    enum simple_heap_type {
        Multiplication,
        Division,
    };

    enum open_addressing_heap_type {
        Linear,
        Quadratic,
        DoubleHashing,
    };

    struct entry {
        std::string key;
        int val;
    };

    struct node {
        node *next;
        node *prev;
        entry *data;
    };

    class simple_heap {
        public:
            simple_heap(simple_heap_type type, int size);
            ~simple_heap();

            void insert_data(entry *data);
            void delete_data(entry *data);
            entry *search_data(std::string key);

        private:
            const double MULT_FACTOR = 0.6180339887;

            std::vector<node*> _heap_arr;
            int _heap_size;
            simple_heap_type _type;

            int _get_hash(std::string key);
            node *_search_nodes(std::string key);
    };

    class open_addressing_heap {
        public:
            open_addressing_heap(int size);
            ~open_addressing_heap();

            void insert_data(entry *data);
            void delete_data(entry *data);
            entry *search_data(std::string key);

        private:
            const std::string SENTINEL_STR = "";
            const int SENTINEL_INT = INT_MIN;

            int _size, _a, _b, _prime;
            open_addressing_heap_type _type;
            std::vector<entry*> _heap_arr;

            int _generate_prime();
            int _get_hash(std::string key, int permutation);
    };
}

#endif // SIMPLE_HEAP_HPP_INCLUDED
