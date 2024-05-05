#ifndef SELECTION_HPP_INCLUDED
#define SELECTION_HPP_INCLUDED

#include <vector>

namespace selection {

    int randomized_select(std::vector<int> vec, int i);
    
    int split_select(std::vector<int> vec, int i);
}

#endif // SELECTION_HPP_INCLUDED 
