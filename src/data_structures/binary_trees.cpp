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
        while (nullptr != curr_node && curr_node->key != key) {
            if (key < curr_node->key) {
                curr_node = curr_node->left;
            } else {
                curr_node = curr_node->right;
            }
        }
        return curr_node;
    }

    node *binary_tree::successor(node *n) {
        if (nullptr != n->right) {
            return _subtree_min(n->right);
        }

        node *p = n->parent;
        while (nullptr != p && p->left != n) {
            p = p->parent;
            n = p;
        }
        return p;
    }

    node *binary_tree::predecessor(node *n) {
        if (nullptr != n->left) {
            return _subtree_max(n->left);
        }

        node *p = n->parent;
        while (nullptr != p && p->right != n) {
            p = p->parent;
            n = p;
        }
        return p;
    }

    void binary_tree::insert_node(node *n) {
        node *curr_node = _root, *parent = nullptr;
        while (nullptr != curr_node) {
            parent = curr_node;
            curr_node = n->key < curr_node->key
                      ? curr_node->left
                      : curr_node->right;
        }

        // check if first node
        if (nullptr != parent) {
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
        if (nullptr == n->left) {
            _transplant(n, n->left);
        } else if (nullptr == n->right) {
            _transplant(n, n->right);
        } else {
            // get successor
            node *swap_node = _subtree_min(n->right);
            if (swap_node != n->right) {
                _transplant(swap_node, swap_node->right);
                swap_node->right = n->right;
                n->right->parent = swap_node;
            }
            _transplant(n, swap_node);
            swap_node->left = n->left;
            n->left->parent = swap_node;
        }
    }

    std::vector<node*> binary_tree::get_ordered_nodes() {
        return _subtree_ordered_nodes(_root);
    }

    void binary_tree::_transplant(node *remove, node *replace) {
        if (nullptr == remove->parent) {
            // check if remove is current root
            _root = replace;
        } else if (remove->parent->left == remove) {
            remove->parent->left = replace;
        } else {
            remove->parent->right = replace;
        }
        
        if (nullptr != replace) {
            replace->parent = remove->parent;
        }
    }

    std::vector<node*> binary_tree::_subtree_ordered_nodes(node *n) {
        if (nullptr == n) {
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
        if (nullptr == n) {
            return;
        }
        _delete_subtree(n->left);
        _delete_subtree(n->right);
        delete n;
    }
    
    node *binary_tree::_subtree_max(node *n) {
        while (nullptr != n->right) {
            n = n->right;
        }
        return n;
    }

    node *binary_tree::_subtree_min(node *n) {
        while (nullptr != n->left) {
            n = n->left;
        }
        return n;
    }
}
