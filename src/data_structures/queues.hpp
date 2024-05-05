#ifndef QUEUES_HPP_INCLUDED
#define QUEUES_HPP_INCLUDED

namespace queues {
    class Queue {
        public:
            Queue(int size);
            ~Queue();

            bool is_empty();
            bool is_full();
            int get_size();
            int peek();
            int dequeue();
            void enqueue(int val);

        private:
            bool _is_empty;
            bool _is_full;
            int _size;
            int _head_ind;
            int _tail_ind;
            int *_arr;
    };
}

#endif // QUEUES_HPP_INCLUDED
