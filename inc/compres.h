#pragma once

#include "include.h"
#include "myLess.h"
#include "hafmanTree.h"
#include "hafmanTable.h"
#include "output.h"
namespace my{


class Compressor{
public:

	Compressor();
	void setFileName(string fullName, string name, string format);
	void startProces();
	~Compressor();

private:

	void input();
	void makeUnordredMao();
	void makePriorityPueue();
	void makeHafmanTree();
	void makeHafmanTeble();
	void zipProces();
	void output();

	void baytFill();
	path pathRevers(path pth);
	void addBit(path bit);
	
private:

	ifstream input_;
	ofstream output_;
	unordered_map<char, int> uMap_;
	priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> pQue_;
	HafmanTree hTree_;
	HafmanTable hTable_;
	ioClass iOBject_;
	vector<char> oVector_;
	string fileContents_;
	string fullName_;
	string name_;
	string format_;
	short lasRedundantBits_;
};


}//namespace my