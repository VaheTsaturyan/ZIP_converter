#include "../inc/compres.h"
#include "compres.h"


/*	ifstream input_;
	ofstream output_;
	unordered_map<char, int> uMap;
	string fullName;
	string name_;
	string format_;*/
namespace my{

Compressor::Compressor() = default;
void Compressor::setFileName(string fullName, string name, string format){
    fullName_ = fullName;
    name_ = name;
    format_ = format;
    startProces();
}

void Compressor::startProces(){
    input();
    makeUnordredMao();
    makePriorityPueue();
    makeHafmanTree();
    makeHafmanTeble();
    zipProces();
    output();
}

Compressor::~Compressor() = default;



void Compressor::input(){
    input_.open(fullName_, std::ios::binary | std::ios::app);
    if(!input_.is_open()){
        throw runtime_error("file didnt find");
    }
    while(!input_.eof()){
        fileContents_.push_back(input_.get());
    }
    input_.close();
}

void Compressor::makeUnordredMao(){
    for(auto el : fileContents_){
        uMap_[el]++;
    }
}

void Compressor::makePriorityPueue(){
    for(auto el : uMap_){
        pQue_.push(el);
    }
}

void Compressor::makeHafmanTree(){
    hTree_.makeTree(pQue_);
}


void Compressor::makeHafmanTeble(){
    for(auto el : uMap_){
        hTable_.insert(hTree_.find(el.first));
    }
}

void Compressor::zipProces(){
    baytFill();
    iOBject_.getQue(pQue_);
    iOBject_.getIoString(fileContents_);
    iOBject_.getFormat(format_);
    iOBject_.getLasRedundantBits(lasRedundantBits_);
}

void Compressor::output(){
    std::cout<<"outout"<<std::endl;
    string name = name_ + "zbv";
    output_.open(name, std::ios::binary );
    if(!output_.is_open()){
        throw runtime_error("file havenot open");
    }
    boost::archive::binary_oarchive oa(output_);
    oa << iOBject_;
    output_.close();
}


void Compressor::baytFill()
{
    path pth;
    size i = 0;
    oVector_.push_back(0);
    for( auto el : fileContents_ ){
        pth = hTable_.find(el);
        pth = pathRevers(pth);
        while(pth % 10 != 2){
            short bit = pth % 10;
            pth /= 10; 
            if(bit == 0 || bit == 1){
                addBit(bit);
            } else {
                throw runtime_error("Your trying write number other than 0 and 1.");
            } 
            ++i;
            if(i == 8){
                oVector_.push_back(0);
                i == 0;
            }
        }
    }
    lasRedundantBits_ = i;
}

path Compressor::pathRevers(path pth)
{
    path revers = 2;
    while( (pth % 10 )!= 2){
        revers = 10 * revers + pth % 10;
        pth /= 10;
    }
    return revers;
}

void Compressor::addBit(path bit)
{
    auto back = oVector_.back();
    back = back << 1;
    if(bit == 1){
        back = back ^ 1;
    }else{
        return;
    }
}


} // namespace my

