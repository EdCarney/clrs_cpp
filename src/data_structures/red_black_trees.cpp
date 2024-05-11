#include "red_black_trees.hpp"
#include <string>

namespace rb_trees {

    rb_tree::rb_tree() : _size(0) {
        _NIL_NODE = new node { -1, _NIL_NODE, _NIL_NODE, _NIL_NODE, BLACK, "" };
        _root = _NIL_NODE;
    }

    rb_tree::~rb_tree() {
        // delete all nodes in the tree
    }

    int rb_tree::size() {
        return _size;
    }

    node *rb_tree::min() {
        return _tree_min(_root);
    }

    node *rb_tree::max() {
        return _tree_max(_root);
    }

    void rb_tree::insert_node(int key, std::string data) {
        auto n = new node { key, _NIL_NODE, _NIL_NODE, _NIL_NODE, RED, data };

        auto curr_node = _root;
        auto prev_node = _NIL_NODE;
        while (_NIL_NODE != curr_node) {
            prev_node = curr_node;
            curr_node = n->key < curr_node->key
                      ? curr_node->left
                      : curr_node->right;
        }

        n->parent = prev_node;

        if (_NIL_NODE == n->parent) {
            _root = n;
        } else if (n->key < prev_node->key) {
            prev_node->left = n;
        } else {
            prev_node->right = n;
        }

        _insert_fixup(n);
    }

    void rb_tree::delete_node(std::string data) {
    }

    node *rb_tree::search_node(int key) {
        auto curr_node = _root;
        while (_NIL_NODE != curr_node && key != curr_node->key) {
            curr_node = key < curr_node->key
                      ? curr_node->left
                      : curr_node->right;
        }
        return _NIL_NODE == curr_node ? nullptr : curr_node;
    }

    void rb_tree::_r_rotate(node *n) {
        node *y = n->left;

        n->left = y->right;
        y->parent = n->parent;

        if (_NIL_NODE == n->parent) {
            _root = y;
        } else if (n->parent->left == n) {
            n->parent->left = y;
        } else if (n->parent->right == n) {
            n->parent->right = y;
        }

        if (_NIL_NODE != y->right) {
            y->right->parent = n;
        }

        y->right = n;
        n->parent = y;
    }

    void rb_tree::_l_rotate(node *n) {
        node *y = n->right;

        n->right = y->left;
        y->parent = n->parent;

        if (_NIL_NODE == n->parent) {
            _root = y;
        } else if (n->parent->left == n) {
            n->parent->left = y;
        } else if (n->parent->right == n) {
            n->parent->right = y;
        }

        if (_NIL_NODE != y->left) {
            y->left->parent = n;
        }

        y->left = n;
        n->parent = y;
    }

    void rb_tree::_insert_fixup(node *n) {
        while (RED == n->parent->color) {
            // n's parent is left child
            if (n->parent == n->parent->parent->left) {
                // n's uncle
                auto y = n->parent->parent->right;
                
                // if uncle is red, then we can update both
                // parent and uncle to black w/out changing
                // black length; then break
                if (RED == y->color) {
                    n->parent->color = BLACK;
                    y->color = BLACK;
                    n = n->parent->parent;
                    continue;
                }

                // if n is a right child, rotate left and move up
                // (which will be at the same level after rotation)
                if (n->parent->right == n) {
                    n = n->parent;
                    _l_rotate(n);
                }

                // now that n is a left child, shift black up,
                // and rotate right; note this will stop the loop
                // since our parent is now black
                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                _r_rotate(n->parent->parent);
            }
            // n's parent is right child
            // (logic is symmetrical)
            else {
                auto y = n->parent->parent->left;
                
                if (RED == y->color) {
                    n->parent->color = BLACK;
                    y->color = BLACK;
                    n = n->parent->parent;
                    continue;
                }

                if (n->parent->left == n) {
                    n = n->parent;
                    _r_rotate(n);
                }

                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                _l_rotate(n->parent->parent);
            }
        }
        _root->color = BLACK;
    }

    void rb_tree::_delete_fixup(node *n) {
    }

    node *rb_tree::_tree_min(node *n) {
        if (_NIL_NODE == n) {
            return nullptr;
        }

        node *curr_node = n;
        while (_NIL_NODE != curr_node->left) {
            curr_node = curr_node->left;
        }
        return curr_node;
    }

    node *rb_tree::_tree_max(node *n) {
        if (_NIL_NODE == n) {
            return nullptr;
        }

        node *curr_node = n;
        while (_NIL_NODE != curr_node->right) {
            curr_node = curr_node->right;
        }
        return curr_node;
    }
}
