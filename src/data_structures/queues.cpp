#include "queues.hpp"
#include <stdexcept>

namespace queues {

    Queue::Queue(int size) : _size(size), _head_ind(0), _tail_ind(0), _is_empty(true), _is_full(false) {
        _arr = new int[_size];
    }

    Queue::~Queue() {
        delete[] _arr;
    }

    bool Queue::is_empty() {
        return _is_empty;
    }

    bool Queue::is_full() {
        return _is_full;
    }

    int Queue::get_size() {
        return _size;
    }

    int Queue::peek() {
        if (_is_empty) {
            throw new std::runtime_error("Queue underflow");
        }
        return _arr[_head_ind];
    }

    int Queue::dequeue() {
        if (_is_empty) {
            throw new std::runtime_error("Queue underflow");
        }
        int val = _arr[_head_ind];
        _head_ind = (_head_ind + 1) % _size;

        _is_empty = _head_ind == _tail_ind;
        _is_full = false;
        return val;
    }

    void Queue::enqueue(int val) {
        if (_is_full) {
            throw new std::runtime_error("Queue overflow");
        }
        _arr[_tail_ind] = val;
        _tail_ind = (_tail_ind + 1) % _size;

        _is_empty = false;
        _is_full = _head_ind == _tail_ind;
    }
}
