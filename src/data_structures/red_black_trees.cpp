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
    }

    void rb_tree::_l_rotate(node *n) {
    }

    node *rb_tree::_tree_min(node *n) {
        node *curr_node = n;
        while (nullptr != curr_node->l) {
            curr_node = curr_node->l;
        }
        return curr_node;
    }

    node *rb_tree::_tree_max(node *n) {
        node *curr_node = n;
        while (nullptr != curr_node->r) {
            curr_node = curr_node->r;
        }
        return curr_node;
    }
}
