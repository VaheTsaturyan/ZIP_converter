#pragma once 
#include "include.h"
#include "myLess.h"

namespace my{

class HafmanTree{
public:
    HafmanTree();
    ~HafmanTree();
    void makeTree(priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> pQue);
    void clear();
    pair<char, path> find(char chr);
private:
    struct Node{
        Node();
        Node(char chr);
        Node(char chr, Node* lPtr, Node* rPtr);
        char data_;
        Node* lNode;
        Node* rNode;
    };

    void clearHelper(Node* head);
    path findHelper(Node* head, char chr);

private:
    Node* head_;
};





    
}//namespace my