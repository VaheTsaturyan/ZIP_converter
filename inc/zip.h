#pragma once
#include "include.h"
#include "compres.h"

namespace my{


class Zip{
public:
	Zip(const string& fullName);
	void what_to_do();
	~Zip();
private:
	void init_name();
	void init_format();
private:
	Compressor copmresor_;
	//Decoder decoder_;
	string fullName_;
	string name_;
	string format_;
};


}