#include "../inc/hafmanTable.h"


namespace my{
/*
class HafmanTable{
public:
    HafmanTable();
    ~HafmanTable();
    void pushBack(const pair<char, path> pr);
    path find(char chr);
private:

private:
    unordered_map<char, path> htable_;
};*/

HafmanTable::HafmanTable() = default ;
HafmanTable::~HafmanTable() = default ;

void HafmanTable::insert(const pair<char, path> pr){
    hTable_.insert(pr);
}

path HafmanTable::find(char chr){
     return hTable_[chr];
}

}//namespace my