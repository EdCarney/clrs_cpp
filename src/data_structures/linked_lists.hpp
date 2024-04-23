#ifndef LINKED_LISTS_HEADER_HPP
#define LINKED_LISTS_HEADER_HPP

namespace linked_lists {

    struct node_single {
        int val;
        node_single *next;
    };

    struct node_double {
        int val;
        node_double *next;
        node_double *prev;
    };

    class DoublyLinkedList {
        public:
            DoublyLinkedList();
            ~DoublyLinkedList();

            const node_double * get_head();
            const node_double * get_tail();

            node_double *search_node(int val);
            void insert_node(int val);
            void delete_node(int val);

        private:
            node_double *_head;
            node_double *_tail;
    };

    class SinglyLinkedList {
    };

}

#endif // LINKED_LISTS_HEADER_HPP
