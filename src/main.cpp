#include "zip.h"


int main(int argc, char** argv){
	char* arg = argv[1] ;
	std::cout << argc << std::endl << arg << std::endl;
	my::Zip zipl(arg);
	zipl.what_to_do();
	return 0;
}
