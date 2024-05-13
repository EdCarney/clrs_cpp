#include "treaps.hpp"
#include <random>
#include <string>
#include <unordered_set>

namespace treaps {

    treap::treap() : _root(nullptr), _size(0) { }

    treap::~treap() {
        _delete_tree(_root);
    }

    int treap::size() {
        return _size;
    }

    void treap::insert_node(int key, std::string data) {
        node *curr = _root, *prev = nullptr;
        while (nullptr != curr) {
            prev = curr;
            curr = key < curr->key
                 ? curr->left
                 : curr->right;
        }

        int pri = _generate_pri();
        auto n = new node { key, pri, data, prev, nullptr, nullptr };

        if (nullptr == prev) {
            _root = n;
        } else if (key < prev->key) {
            prev->left = n;
        } else {
            prev->right = n;
        }

        ++_size;
        _fixup(n);
    }

    node *treap::search_node(int key) {
        auto curr = _root;
        while (nullptr != curr && curr->key != key) {
            curr = key < curr->key
                 ? curr->left
                 : curr->right;
        }
        return curr;
    }

    void treap::delete_node(int key) {
        node *n = search_node(key), *y = nullptr;

        if (nullptr == n->left) {
            y = n->right;
            _transplant(n, n->right);
        } else if (nullptr == n->right) {
            y = n->left;
            _transplant(n, n->left);
        } else {
            y = _subtree_min(n->right);

            if (n->right != y) {
                _transplant(y, y->right);
                y->right = n->right;
                n->right->parent = y;
            }
            
            _transplant(n, y);
            y->pri = n->pri;
            y->left = n->left;
            n->left->parent = y;
        }

        delete n;
        --_size;
    }

    int treap::_generate_pri() {
        static bool init = false;
        static std::random_device rd;
        static std::mt19937 mt;
        static std::uniform_int_distribution<int> dist(0, 10'000);
        if (!init) {
            mt.seed(rd());
            init = true;
        }
        int pri = dist(mt);
        while (_priorities.count(pri)) {
            pri = dist(mt);
        }
        return pri;
    }

    void treap::_fixup(node *n) {
        while (nullptr != n->parent && n->pri < n->parent->pri) {
            if (n == n->parent->right) {
                _rotate_left(n->parent);
            } else {
                _rotate_right(n->parent);
            }
            n = n->parent;
        }
    }
}

