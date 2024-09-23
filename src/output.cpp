#include "../inc/output.h"
#include "output.h"
#include <cstring>
/*
    priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> ioQue;
    short lasRedundantBits;
    char* ioString; 
    char* format;
*/

namespace my
{
    

void ioClass::getQue(priority_queue<pair<char, int>, vector<pair<char, int>>, myLess<pair<char, int>>> ioQue){
    while(ioQue.size() != 0){
        pair<char, int> pir;
        pir = ioQue.top();
        ioVec_.push_back(pir);
        ioQue.pop();
    }
}

void ioClass::getIoString(string &ioString){
    this->ioString_ = ioString;
}

void ioClass::getFormat(string &format){
    this->format_ = format;
}

void ioClass::getLasRedundantBits(short lasRedundantBits){
    this->lasRedundantBits_ = lasRedundantBits;
}

priority_queue<pair<char, int>, vector<pair<char, int>>, myLess<pair<char, int>>> ioClass::setQue()
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, myLess<pair<char, int>>> que;
    for(auto el : ioVec_){
        que.push(el);
    }
    return que;
}

string &ioClass::setIoString(){
    return this->ioString_;
}

string &ioClass::setFormat(){
    return this->format_;
}

short &ioClass::setLasRedundantBits(){
    return this->lasRedundantBits_;
}

} // namespace my
