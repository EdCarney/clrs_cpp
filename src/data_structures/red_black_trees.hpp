#ifndef RED_BLACK_TREES_HPP_INCLUDED
#define RED_BLACK_TREES_HPP_INCLUDED

#include <string>

namespace rb_trees {

    enum node_color {
        RED,
        BLACK,
    };
    
    struct node {
        int key;
        node *parent;
        node *left;
        node *right;
        node_color color;
        std::string data;
    };        
    
    class rb_tree {
        public:
            rb_tree();
            ~rb_tree();
            int size();
            node *min();
            node *max();
            void insert_node(int key, std::string data);
            void delete_node(int key);
            node *search_node(int key);

        private:
            node * _NIL_NODE;
            node *_root;
            int _size;
            void _r_rotate(node *n);
            void _l_rotate(node *n);
            void _insert_fixup(node *n);
            void _delete_fixup(node *n);
            void _transplant(node *n1, node *n2);
            node *_tree_min(node *n);
            node *_tree_max(node *n);
    };

}

#endif // RED_BLACK_TREES_HPP_INCLUDED
