#include "linked_lists.hpp"

namespace linked_lists {

    DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr) { }

    DoublyLinkedList::~DoublyLinkedList() {
        node_double *curr = _head, *prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    const node_double *DoublyLinkedList::get_head() {
        return _head;
    }
    
    const node_double *DoublyLinkedList::get_tail() {
        return _tail;
    }

    node_double *DoublyLinkedList::search_node(int val) {
        node_double *curr = _head;
        while (curr != nullptr && curr->val != val) {
            curr = curr->next;
        }
        return curr;
    }

    void DoublyLinkedList::insert_node(int val) {
        node_double *new_node = new node_double { val, _head, nullptr };
        if (_head != nullptr) {
            _head->prev = new_node;
        } else {
            _tail = new_node;
        }
        _head = new_node;
    }
    
    void DoublyLinkedList::delete_node(int val) {
        node_double *to_delete = search_node(val);

        if (to_delete->next != nullptr) {
            to_delete->next->prev = to_delete->prev;
        } else {
            _tail = to_delete->prev;
        }

        if (to_delete->prev != nullptr) {
            to_delete->prev->next = to_delete->next;
        } else {
            _head = to_delete->next;
        }

        delete to_delete;
    }
}
