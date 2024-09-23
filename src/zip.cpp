#include "../inc/zip.h"

namespace my{

/*class Zip{
public:
	Zip(string fullName);
	void what_to_do();
	~Zip();
private:
	void intit_name_();
	void intit_format_();
private:
	Compressor copmresor_;
	Decoder decoder_;
	string fullName_;
	string name_;
	string format_;
};
*/


Zip::Zip(const string& fullName){
	this->fullName_ = fullName;
	init_name();
}

void Zip::what_to_do(){
	if(format_ == ZIP_FORMAT ){
		//decoder_.setFileName(fullName_, name_,format_);
		return ;
	}
	copmresor_.setFileName(fullName_, name_,format_);
}

Zip::~Zip() = default;


void Zip::init_name(){
	init_format();
	size sz = fullName_.size();
	size i = sz - 1;
	while(i > 0 && fullName_[i] != '/'){
		--i;
	}
	size step = sz - i - format_.size();
	if( i > sz || i + step > sz){
		runtime_error("substring no valid");
	}
	name_ = fullName_.substr(i, step );
}


void Zip::init_format(){
	size sz = fullName_.size();
	size i = sz - 1;
	while(i > 0 && fullName_[i] != '.'){
		--i;
	}
	if( i > sz || sz - i > sz){
		runtime_error("substring no valid");
	}
	format_ = fullName_.substr(i + 1, sz - i);
}



}//  namespace my