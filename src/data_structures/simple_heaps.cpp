#include "simple_heaps.hpp"
#include "../utility_algos/prime_numbers.hpp"
#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <stdexcept>

namespace heaps {

    simple_heap::simple_heap(simple_heap_type type, int size) : _type(type), _heap_size(size) {
        _heap_arr = std::vector<node*>(_heap_size);


        for (auto &e : _heap_arr) {
            e = nullptr;
        }
    }

    simple_heap::~simple_heap() {
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

    void simple_heap::insert_data(entry *data) {
        int hash_val = _get_hash(data->key);
        node *new_node = new node { nullptr, nullptr, data }; 

        if (_heap_arr[hash_val] != nullptr) {
            _heap_arr[hash_val]->prev = new_node;
            new_node->next = _heap_arr[hash_val];
        }

        _heap_arr[hash_val] = new_node;
    }

    void simple_heap::delete_data(entry *data) {
        int hash_val = _get_hash(data->key);
        node *to_delete = _search_nodes(data->key);

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

    entry *simple_heap::search_data(std::string key) {
        node *curr_node = _search_nodes(key);
        return curr_node == nullptr ? nullptr : curr_node->data;
    }

    int simple_heap::_get_hash(std::string key) {
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

    node *simple_heap::_search_nodes(std::string key) {
        int hash_val = _get_hash(key);

        node *curr_node = _heap_arr[hash_val];
        while (curr_node != nullptr && curr_node->data->key != key) {
            curr_node = curr_node->next;
        }
        
        return curr_node;
    }

    open_addressing_heap::open_addressing_heap(int size) {
        _size = size;
        _heap_arr = std::vector<entry*>(_size, nullptr);

        _prime = _generate_prime();
        std::random_device rd;
        std::mt19937 gen(rd);
        std::uniform_int_distribution<int> a_dist(1, _prime - 1);
        std::uniform_int_distribution<int> b_dist(0, _prime - 1);

        _a = a_dist(gen);
        _b = b_dist(gen);
    }

    open_addressing_heap::~open_addressing_heap() {
        int i = -1;
        while (++i < _size) {
            if (_heap_arr[i] != nullptr) {
                delete _heap_arr[i];
            }
        }
    };

    void open_addressing_heap::insert_data(entry *data) {
        int permutation = -1, hash;
        do {
            hash = _get_hash(data->key, ++permutation);
        } while (_heap_arr[hash] != nullptr && permutation < _size);

        if (permutation == _size) {
            throw std::runtime_error("Heap overflow");
        }

        _heap_arr[hash] = new entry { data->key, data->val };
    }

    void open_addressing_heap::delete_data(entry *data) {
        // hash key
        // search for key to find
        // delete entry and set to nullptr
    }

    entry *open_addressing_heap::search_data(std::string key) {
        int permutation = -1, hash;
        do {
            hash = _get_hash(key, ++permutation);
        } while (_heap_arr[hash] != nullptr && _heap_arr[hash]->key != key && permutation < _size);

        if (_heap_arr[hash] == nullptr || permutation == _size) {
            return new entry { "", -1 };
        } else {
            return _heap_arr[hash];
        }
    }

    int open_addressing_heap::_generate_prime() {
        std::vector<int> primes = prime_numbers::generate_primes_sieve(_size * 2);
        int max_prime = primes.at(0);
        for (int i = 0; i < primes.size(); ++i) {
            max_prime = std::max(max_prime, primes.at(i));
        }
        return max_prime;
    }

    int open_addressing_heap::_get_hash(std::string key, int permutation) {
        int key_int = 0;

        for (int i = 0; i < key.length(); ++i) {
            key_int += (wchar_t)key[i];
        }

        int h = ((_a * key_int + _b) % _prime) % _size;

        switch (_type) {
            case Linear: 
                return (h + permutation) % _size;
            default:
                return h;
        }
    }

    node *open_addressing_heap::_search_nodes(std::string key) {
    }
}
