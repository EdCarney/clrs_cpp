#ifndef SIMPLE_HEAP_HPP_INCLUDED
#define SIMPLE_HEAP_HPP_INCLUDED

#include <string>
#include <vector>

namespace heaps {

    enum heapType {
        Multiplication,
        Division,
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
            simple_heap(heapType type, int size);
            ~simple_heap();

            void insert_data(entry *data);
            void delete_data(entry *data);
            entry *search_data(std::string key);

        private:
            const double MULT_FACTOR = 0.6180339887;

            std::vector<node*> _heap_arr;
            int _heap_size;
            heapType _type;

            int get_hash(std::string key);
            node *search_nodes(std::string key);
    };
}

#endif // SIMPLE_HEAP_HPP_INCLUDED
