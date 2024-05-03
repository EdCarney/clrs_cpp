#ifndef BINARY_TREES_HPP_INCLUDED
#define BINARY_TREES_HPP_INCLUDED

#include <string>
#include <vector>

namespace binary_trees {

    struct node {
        std::string data;
        int key;
        node* left;
        node* right;
        node* parent;
    };
        
    class binary_tree {
        public:
            binary_tree();
            ~binary_tree();
            int size();
            node *max();
            node *min();
            node *search(int key);
            node *successor(node *n);
            node *predecessor(node *n);
            void delete_node(node *n);
            void insert_node(node *n);
            std::vector<node*> get_ordered_nodes();

        private:
            node *_root;
            int _size;
            
            void _delete_subtree(node *n);
            node *_subtree_max(node *n);
            node *_subtree_min(node *n);
            std::vector<node*> _subtree_ordered_nodes(node *n);
            
            // updates the parent of remove to point to replace
            // and updates replace to have remove's parent
            void _transplant(node *remove, node *replace);
    };
}

#endif // BINARY_TREES_HPP_INCLUDED
