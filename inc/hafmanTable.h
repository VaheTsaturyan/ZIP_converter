#pragma once 

#include "include.h"

namespace my{


class HafmanTable{
public:
    HafmanTable();
    ~HafmanTable();
    void insert(const pair<char, path> pr);
    path find(char chr);
private:

private:
    unordered_map<char, path> hTable_;
};




}//namespace my