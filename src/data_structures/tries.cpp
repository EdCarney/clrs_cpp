#include "tries.hpp"
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace tries {

    trie::trie() : _size(0), _root(new node { false }) { }

    trie::~trie() {
        _delete_subtree(_root);
    }

    int trie::size() {
        return _size;
    }

    void trie::insert_value(std::string value) {
        node *curr_node = _root;
        for (char &c : value) {
            if (!curr_node->children.count(c)) {
                curr_node->children.insert(std::pair<char, node*>(c, new node { false }));
            }
            curr_node = curr_node->children.at(c);
        }

        // handle case where word is already present
        if (curr_node->is_terminal) {
            return;
        }
        curr_node->is_terminal = true;
        ++_size;
    }

    void trie::delete_value(std::string value) {
        std::stack<node*> nodes;
        
        node *curr_node = _root;
        for (char &c : value) {
            // handle case if value is not present
            if (!curr_node->children.count(c)) {
                return;
            }
            nodes.push(curr_node);
            curr_node = curr_node->children.at(c);
        }

        // handle last case if value not present
        if (!curr_node->is_terminal) {
            return;
        }

        curr_node->is_terminal = false;
        --_size;

        // iterate backwards over the string and delete
        // stop if node has any other children or is terminal
        for (auto it = value.rbegin(); it != value.rend(); ++it) {
            char c = *it;
            node *n = nodes.top();
            if (!n->children.at(c)->children.empty() || n->children.at(c)->is_terminal) {
                return;
            }
            delete n->children.at(c);
            n->children.erase(c);
            nodes.pop();
        }
            
    }

    bool trie::search_value(std::string value) {
        node *curr_node = _root;
        for (char &c : value) {
            if (!curr_node->children.count(c)) {
                return false;
            }
            curr_node = curr_node->children.at(c);
        }
        return curr_node->is_terminal;
    }

    std::vector<std::string> trie::get_ordered_values() {
        return _get_ordered_values_internal(_root, "");
    }

    std::vector<std::string> trie::_get_ordered_values_internal(node *n, std::string prefix) {
        std::vector<std::string> vec, tmp;
        
        // if current node is terminal, include in return
        if (n->is_terminal) {
            vec.push_back(prefix);
        }

        for (auto &pair : n->children) {
            tmp = _get_ordered_values_internal(pair.second, prefix + pair.first);
            vec.reserve(vec.size() + tmp.size());
            vec.insert(vec.end(), tmp.begin(), tmp.end());
        }
        
        return vec;
    }

    void trie::_delete_subtree(node *n) {
        for (auto &pair : n->children) {
            _delete_subtree(pair.second);
        }
        delete n;
    }
}
