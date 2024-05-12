#include "red_black_trees.hpp"
#include <string>

namespace rb_trees {

    node::node(int key, std::string data, node_color color, node *left, node *right, node *parent) {
        this->key = key;
        this->data = data;
        this->color = color;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }

    node::node(const node &n) {
        this->key = n.key;
        this->data = n.data;
        this->color = n.color;
        this->left = n.left;
        this->right = n.right;
        this->parent = n.parent;
    }

    rb_tree::rb_tree() : _size(0) {
        _NIL_NODE = new node(-1, "", BLACK, nullptr, nullptr, nullptr);
        _NIL_NODE->parent = _NIL_NODE;
        _NIL_NODE->left = _NIL_NODE;
        _NIL_NODE->right = _NIL_NODE;

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

    bool rb_tree::is_valid_rb_tree() {
        int b_height_l = _get_black_height(_root->left);
        int b_height_r = _get_black_height(_root->right);
        return std::min(b_height_l, b_height_r) > 0
            && b_height_r == b_height_l;
    }

    // if child black heights are equal, return their height plus 1 if n
    // is also a black node; otherwise, propagate up -1 as an error value
    int rb_tree::_get_black_height(node *n) {
        
        if (_NIL_NODE == n) {
            return 1;
        }

        int b_height_l = _get_black_height(n->left);
        int b_height_r = _get_black_height(n->right);
        int is_b_node = BLACK == n->color;

        return b_height_l == b_height_r
            ? b_height_l + is_b_node
            : -1;
    }

    void rb_tree::insert_node(int key, std::string data) {
        auto n = new node(key, data, RED, _NIL_NODE, _NIL_NODE, _NIL_NODE);

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

        ++_size;
        _insert_fixup(n);
    }

    void rb_tree::delete_node(int key) {
        auto n = search_node(key);

        // check for node not found
        if (nullptr == n) {
            return;
        }

        auto y = n;
        auto y_orig_color = y->color;

        // used to reference the node that
        // has been moved
        node *x;
        bool delete_x = false;

        // similar to BST deletion
        if (_NIL_NODE == n->left) {
            x = n->right;
            _transplant(n, n->right);
        } else if (_NIL_NODE == n->right) {
            x = n->left;
            _transplant(n, n->left);
        } else {
            y = _tree_min(n->right);
            y_orig_color = y->color;
            x = y->right;

            // if n's successor is not its
            // right child, move it there
            if (y->parent == n && _NIL_NODE == x) {
                x = new node(*_NIL_NODE);
                x->parent = y;
                delete_x = true;
            } else {
                _transplant(y, y->right);
                y->right = n->right;
                y->right->parent = y;
            }
            _transplant(n, y);
            y->left = n->left;
            y->left->parent = y;
            y->color = n->color;
        }

        delete n;
        --_size;

        if (BLACK == y_orig_color) {
            _delete_fixup(x);
        }

        if (delete_x) {
            delete x;
        }
    }

    void rb_tree::_transplant(node *n1, node *n2) {
        // moves n2 into n1's position
        // does not modify any of n1's links
        if (_NIL_NODE == n1->parent) {
            _root = n2;
        } else if (n1 == n1->parent->left) {
            n1->parent->left = n2;
        } else {
            n1->parent->right = n2;
        }
        n2->parent = n1->parent;
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
                    n->parent->parent->color = RED;
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
                    n->parent->parent->color = RED;
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
        while (n != _root && BLACK == n->color) {
            node *w;
            if (n->parent->left == n) {
                w = n->parent->right;
                
                if (RED == w->color) {
                    w->color = BLACK;
                    n->parent->color = RED;
                    _l_rotate(n->parent);
                    w = n->parent->right;
                }

                if (BLACK == w->left->color && BLACK == w->right->color) {
                    w->color = RED;
                    n = n->parent;
                    continue;
                }

                if (BLACK == w->right->color) {
                    w->left->color = BLACK;
                    w->color = RED;
                    _r_rotate(w);
                    w = n->parent->right;
                }

                w->color = n->parent->color;
                n->parent->color = BLACK;
                w->right->color = BLACK;
                _l_rotate(n->parent);
                n = _root;
            } else {
                w = n->parent->left;
                
                if (RED == w->color) {
                    w->color = BLACK;
                    n->parent->color = RED;
                    _r_rotate(n->parent);
                    w = n->parent->left;
                }

                if (BLACK == w->right->color && BLACK == w->left->color) {
                    w->color = RED;
                    n = n->parent;
                    continue;
                }

                if (BLACK == w->left->color) {
                    w->right->color = BLACK;
                    w->color = RED;
                    _l_rotate(w);
                    w = n->parent->left;
                }

                w->color = n->parent->color;
                n->parent->color = BLACK;
                w->left->color = BLACK;
                _r_rotate(n->parent);
                n = _root;
            }
        }
        n->color = BLACK;
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
