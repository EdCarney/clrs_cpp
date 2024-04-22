#include "stacks.hpp"
#include <stdexcept>

namespace stacks {

    Stack::Stack(int size) : _size(size), _top_ind(-1) {
        _arr = new int[_size];
    }
    
    Stack::~Stack() {
        delete[] _arr;
    }
    
    bool Stack::is_empty() {
        return _top_ind < 0;
    }

    bool Stack::is_full() {
        return _top_ind == _size - 1;
    }
    
    int Stack::get_size() {
        return _size;
    }

    int Stack::top() {
        if (_top_ind < 0) {
            throw new std::runtime_error("Stack underflow");
        }
        return _arr[_top_ind];
    }

    int Stack::pop() {
        if (_top_ind < 0) {
            throw new std::runtime_error("Stack underflow");
        }
        return _arr[_top_ind--];
    }

    void Stack::push(int val) {
        if (_top_ind + 1 == _size) {
            throw new std::runtime_error("Stack overflow");
        }
        _arr[++_top_ind] = val;
    }
}
