#include "red_black_trees.hpp"
#include <string>

namespace rb_trees {

    rb_tree::rb_tree() : _NIL_NODE (new node { -1, nullptr, nullptr, nullptr, node_color::BLACK, "" }), _root(_NIL_NODE), _size(0) { }

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

    void rb_tree::insert_node(std::string data) {
    }

    void rb_tree::delete_node(std::string data) {
    }

    bool rb_tree::search_node(std::string data) {
        return false;
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

    node *rb_tree::_tree_min(node *n) {
        node *curr_node = n;
        while (nullptr != curr_node->left) {
            curr_node = curr_node->left;
        }
        return curr_node;
    }

    node *rb_tree::_tree_max(node *n) {
        node *curr_node = n;
        while (nullptr != curr_node->right) {
            curr_node = curr_node->right;
        }
        return curr_node;
    }
}
