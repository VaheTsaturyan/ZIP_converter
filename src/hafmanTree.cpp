#include "../inc/hafmanTree.h"

namespace my{

/*
class HafmanTree{
public:
    HafmanTree();
    ~HafmanTree();
    void makeTree(priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> pQue);
private:
    struct Node{
        char data;
        Node* lNode;
        Node* rNode;
    };



private:
    Node* head;
};*/

HafmanTree::Node::Node(){
    data_ = NULL;
}


HafmanTree::Node::Node(char chr){
    data_ = chr;
}

HafmanTree::Node::Node(char chr, Node* lPtr, Node* rPtr){
    this->data_ = chr;
    this->lNode = lPtr;
    this->rNode = rPtr;
}

HafmanTree::HafmanTree(){
    head_ = nullptr;
}

HafmanTree::~HafmanTree(){
    clear();
}

void HafmanTree::makeTree( priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> pQue ){
    Node* tempNode = new Node;
    tempNode->lNode = new Node(pQue.top().first);
    pQue.pop();
    tempNode->rNode = new Node(pQue.top().first);
    pQue.pop();
    while(pQue.size() != 0){
        tempNode = new Node(NULL, tempNode, nullptr);
        tempNode->rNode = new Node(pQue.top().first);
        pQue.pop();
    }
    this->head_ = tempNode;
    //std::cout<<"hafman tree Make"<<std::endl;
}


pair<char, path> HafmanTree::find( char chr ){
    pair<char, path> result;
    result.first = chr;
    std::cout<<"find Helper start"<<std::endl;
    result.second = findHelper( this->head_, chr );
    std::cout<<"find Helper"<<std::endl;
    return result;
}



void HafmanTree::clear(){
    clearHelper( head_ );
}


void HafmanTree::clearHelper( Node* head ){
    if(head == nullptr){
        return;
    }
    if( head->lNode == nullptr && head->rNode == nullptr ){
        delete head;
        return;
    }
    if( head->lNode == nullptr && head->rNode != nullptr ){
        clearHelper(head->rNode);
        delete head;
        return;
    }
    if( head->lNode != nullptr && head->rNode == nullptr ){
        clearHelper( head->lNode );
        delete head;
        return;
    }
    clearHelper( head->lNode );
    clearHelper( head->rNode );
    delete head;
    return;
}

path HafmanTree::findHelper( Node* head, char chr ){
    if(head == nullptr){
        throw runtime_error("head == nullptr : hafmanTree.cpp : 101");
    }
    if(head->data_ == chr){
        return 2;
    }
    if(head->data_ != chr && head->lNode == nullptr && head->lNode == nullptr){
        return 0;
    }
    if(head->rNode != nullptr){
        return 10 * findHelper(head->rNode, chr) + 1;
    }
    if(head->lNode != nullptr){
        return 10 * findHelper(head->lNode, chr);
    }
    /* if (t_node._left)
        generateCode(*t_node._left, path * 10);
    if (t_node._right)
        generateCode(*t_node._right, path * 10 + 1);    
    if (!t_node._left && !t_node._right)
        _codes[t_node._value] = path;*/
}




}//namespace my