#include <string>
#include <unordered_set>

namespace treaps {

    struct node {
        int key;
        int pri;
        std::string data;
        node *parent;
        node *left;
        node *right;
    };

    class treap {
        public:
            treap();
            ~treap();

            int size();
            void insert_node(int key, std::string data);
            node *search_node(int key);
            void delete_node(int key);

        private:
            node *_root;
            int _size;
            std::unordered_set<int> _priorities;
            int _generate_pri();
            void _rotate_left(node *n);
            void _rotate_right(node *n);
            void _delete_tree(node *n);
            void _transplant(node *n1, node *n2);
            node *_subtree_min(node *n);
            node *_subtree_max(node *n);
            void _fixup(node *n);
    };
}
