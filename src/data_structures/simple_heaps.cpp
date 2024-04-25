#include "simple_heaps.hpp"
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>

namespace heaps {

    heap::heap(heapType type, int size) : _type(type), _heap_size(size) {
        _heap_arr = std::vector<node*>(_heap_size);

        for (auto &e : _heap_arr) {
            e = nullptr;
        }
    }

    heap::~heap() {
        for (auto &e : _heap_arr) {
            if (e != nullptr) {
                node *curr_node = e, *prev_node;
                while (curr_node != nullptr) {
                    prev_node = curr_node;
                    curr_node = curr_node->next;
                    delete prev_node->data;
                    delete prev_node;
                }
            }
        }
    }

    void heap::insert_data(entry *data) {
        int hash_val = get_hash(data->key);
        node *new_node = new node { nullptr, nullptr, data }; 

        if (_heap_arr[hash_val] != nullptr) {
            _heap_arr[hash_val]->prev = new_node;
            new_node->next = _heap_arr[hash_val];
        }

        _heap_arr[hash_val] = new_node;
    }

    void heap::delete_data(entry *data) {
        int hash_val = get_hash(data->key);
        node *to_delete = search_nodes(data->key);

        // noop if not found
        if (to_delete == nullptr) {
            return;
        }

        if (to_delete->next != nullptr) {
            to_delete->next->prev = to_delete->prev;
        }

        if (to_delete->prev != nullptr) {
            to_delete->prev->next = to_delete->next;
        } else {
            // update heap pointer if needed
            _heap_arr[hash_val] = to_delete->next;
        }

        delete to_delete->data;
        delete to_delete;
    }

    entry *heap::search_data(std::string key) {
        node *curr_node = search_nodes(key);
        return curr_node == nullptr ? nullptr : curr_node->data;
    }

    int heap::get_hash(std::string key) {
        int key_int = 0;

        for (int i = 0; i < key.length(); ++i) {
            key_int += (wchar_t)key[i];
        }

        switch (_type) {
            case heaps::Multiplication: {
                double temp = MULT_FACTOR * (double)key_int;
                return floor(_heap_size * (temp - floor(temp)));
            }
            case heaps::Division: {
                return key_int % _heap_size;
            }
            default: {
                throw std::runtime_error("Invalid heap type");
            }
        }
    }

    node *heap::search_nodes(std::string key) {
        int hash_val = get_hash(key);

        node *curr_node = _heap_arr[hash_val];
        while (curr_node != nullptr && curr_node->data->key != key) {
            curr_node = curr_node->next;
        }
        
        return curr_node;
    }
}
