#ifndef TRIES_HPP_INCLUDED
#define TRIES_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>

namespace tries {

    struct node {
        bool is_terminal;
        std::map<char, node*> children;
    };

    class trie {
        public:
            trie();
            ~trie();
            int size();
            void insert_value(std::string value);
            void delete_value(std::string value);
            bool search_value(std::string value);
            std::vector<std::string> get_ordered_values();

        private:
            int _size;
            node *_root;

            void _delete_subtree(node *n);
            std::vector<std::string> _get_ordered_values_internal(node *n, std::string prefix);
    };

}

#endif // TRIES_HPP_INCLUDED
