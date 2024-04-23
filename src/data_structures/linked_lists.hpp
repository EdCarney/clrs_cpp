#ifndef LINKED_LISTS_HEADER_HPP
#define LINKED_LISTS_HEADER_HPP

namespace linked_lists {

    struct s_node {
        int val;
        s_node *next;
    };

    struct d_node {
        int val;
        d_node *next;
        d_node *prev;
    };

    class DoublyLinkedList {
        public:
            DoublyLinkedList();
            ~DoublyLinkedList();

            const d_node * get_head();
            const d_node * get_tail();

            bool is_empty();
            int get_size();
            d_node *search_node(int val);
            void insert_node(int val);
            void delete_node(int val);

        private:
            d_node *_head;
            d_node *_tail;
    };

    class SinglyLinkedList {
        public:
            SinglyLinkedList();
            ~SinglyLinkedList();

            const s_node * get_head();
            const s_node * get_tail();

            bool is_empty();
            int get_size();
            s_node *search_node(int val);
            void insert_node(int val);
            void delete_node(int val);

        private:
            s_node *_head;
            s_node *_tail;
    };

}

#endif // LINKED_LISTS_HEADER_HPP
