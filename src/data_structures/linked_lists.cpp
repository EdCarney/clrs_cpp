#include "linked_lists.hpp"

namespace linked_lists {

    DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr) { }

    DoublyLinkedList::~DoublyLinkedList() {
        d_node *curr = _head, *prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    const d_node *DoublyLinkedList::get_head() {
        return _head;
    }
    
    const d_node *DoublyLinkedList::get_tail() {
        return _tail;
    }

    bool DoublyLinkedList::is_empty() {
        return _tail == nullptr
            || _head == nullptr;
    }

    int DoublyLinkedList::get_size() {
        int size = 0;
        d_node *curr = _head;
        while (curr != nullptr) {
            curr = curr->next;
            ++size;
        }
        return size;
    }

    d_node *DoublyLinkedList::search_node(int val) {
        d_node *curr = _head;
        while (curr != nullptr && curr->val != val) {
            curr = curr->next;
        }
        return curr;
    }

    void DoublyLinkedList::insert_node(int val) {
        d_node *new_node = new d_node { val, _head, nullptr };
        if (_head != nullptr) {
            _head->prev = new_node;
        } else {
            _tail = new_node;
        }
        _head = new_node;
    }
    
    void DoublyLinkedList::delete_node(int val) {
        d_node *to_delete = search_node(val);

        if (to_delete == nullptr)
            return;

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

    SinglyLinkedList::SinglyLinkedList() : _head(nullptr), _tail(nullptr) { }

    SinglyLinkedList::~SinglyLinkedList() {
        s_node *curr = _head, *prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    const s_node *SinglyLinkedList::get_head() {
        return _head;
    }

    const s_node *SinglyLinkedList::get_tail() {
        return _tail;
    }

    bool SinglyLinkedList::is_empty() {
         return _head == nullptr
             || _tail == nullptr;
    }

    int SinglyLinkedList::get_size() {
        int size = 0;
        s_node *curr = _head;
        while (curr != nullptr) {
            curr = curr->next;
            ++size;
        }
        return size;
    }

    s_node *SinglyLinkedList::search_node(int val) {
        s_node *curr = _head;
        while (curr != nullptr && curr->val != val) {
            curr = curr->next;
        }
        return curr;
    }

    void SinglyLinkedList::insert_node(int val) {
        s_node *new_node = new s_node { val, _head };
        if (_tail == nullptr) {
            _tail = new_node;
        }
        _head = new_node;
    }

    void SinglyLinkedList::delete_node(int val) {
        s_node *to_delete = _head, *prev = nullptr;

        while (to_delete != nullptr && to_delete->val != val) {
            prev = to_delete;
            to_delete = to_delete->next;
        }

        if (to_delete == nullptr)
            return;

        if (prev != nullptr) {
            prev->next = to_delete->next;
        } else {
            _head = to_delete->next;
        }

        if (to_delete->next == nullptr) {
            _tail = prev;
        }

        delete to_delete;
    }
}
