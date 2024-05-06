#include "red_black_trees.hpp"
#include <string>

namespace rb_trees {

    rb_tree::rb_tree() : _NIL_NODE (new node { nullptr, nullptr, nullptr, node_color::BLACK, "" }), _root(_NIL_NODE), _size(0) { }

    rb_tree::~rb_tree() {
        // delete all nodes in the tree
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
}
