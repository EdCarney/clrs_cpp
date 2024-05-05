#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

namespace stacks {

    class Stack {
        public:
            Stack(int size);
            ~Stack();
    
            bool is_empty();
            bool is_full();
            int get_size();
            int top();
            int pop();
            void push(int val);
    
        private:
            int _size;
            int _top_ind;
            int *_arr;
    };

}

#endif // STACK_HPP_INCLUDED
