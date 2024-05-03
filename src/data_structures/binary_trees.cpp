#include "binary_trees.hpp"
#include <string>
#include <vector>

namespace binary_trees {

    binary_tree::binary_tree() : _size(0), _root(nullptr) { }

    binary_tree::~binary_tree() {
        _delete_subtree(_root);
    }

    int binary_tree::size() {
        return _size;
    }

    node *binary_tree::max() {
        return _subtree_max(_root);
    }

    node *binary_tree::min() {
        return _subtree_min(_root);
    }

    node *binary_tree::search(int key) {
        node *curr_node = _root;
        while (curr_node != nullptr && curr_node->key != key) {
            if (key < curr_node->key) {
                curr_node = curr_node->left;
            } else {
                curr_node = curr_node->right;
            }
        }
        return curr_node;
    }

    node *binary_tree::successor(node *n) {
        if (n->right != nullptr) {
            return _subtree_min(n->right);
        }

        node *p = n->parent;
        while (p != nullptr && p->left != n) {
            p = p->parent;
            n = p;
        }
        return p;
    }

    node *binary_tree::predecessor(node *n) {
        if (n->left != nullptr) {
            return _subtree_max(n->left);
        }

        node *p = n->parent;
        while (p != nullptr && p->right != n) {
            p = p->parent;
            n = p;
        }
        return p;
    }

    void binary_tree::insert_node(node *n) {
        node *curr_node = _root, *parent = nullptr;
        while (curr_node != nullptr) {
            parent = curr_node;
            curr_node = n->key < curr_node->key
                      ? curr_node->left
                      : curr_node->right;
        }

        // check if first node
        if (parent == nullptr) {
            _root = n;
        }

        n->parent = parent;
        n->left = nullptr;
        n->right = nullptr;

        if (n->key < parent->key) {
            parent->left = n;
        } else {
            parent->right = n;
        }
    }

    void binary_tree::delete_node(node *n) {
    }

    std::vector<node*> binary_tree::get_ordered_nodes() {
        return _subtree_ordered_nodes(_root);
    }

    std::vector<node*> binary_tree::_subtree_ordered_nodes(node *n) {
        if (n == nullptr) {
            return std::vector<node*>(0);
        }

        // get the ordered children recursively
        std::vector<node*> r_children, l_children, ordered;
        l_children = _subtree_ordered_nodes(n->left);
        r_children = _subtree_ordered_nodes(n->right);

        // combine into ordered vector
        ordered.reserve(l_children.size() + r_children.size() + 1);

        ordered.insert(ordered.end(), l_children.begin(), l_children.end());
        ordered.insert(ordered.end(), n);
        ordered.insert(ordered.end(), r_children.begin(), r_children.end());

        return ordered;
    }
        
    void binary_tree::_delete_subtree(node *n) {
        if (n == nullptr) {
            return;
        }
        _delete_subtree(n->left);
        _delete_subtree(n->right);
        delete n;
    }
    
    node *binary_tree::_subtree_max(node *n) {
        while (n->right != nullptr) {
            n = n->right;
        }
        return n;
    }

    node *binary_tree::_subtree_min(node *n) {
        while (n->left != nullptr) {
            n = n->left;
        }
        return n;
    }
}
