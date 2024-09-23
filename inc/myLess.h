#pragma once 
#include "include.h"
namespace my{


template< class T >
struct myLess{
    
    constexpr bool operator()(const T &lhs, const T &rhs) const {
        return lhs < rhs;     
    }
};

template<>
struct myLess<pair<char, int>>{
    
    constexpr bool operator()(const pair<char, int> &lhs, const pair<char, int> &rhs) const {
        return lhs.second > rhs.second;     
    }
};

}//namespace my