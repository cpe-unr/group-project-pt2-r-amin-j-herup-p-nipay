
//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project


#include <iostream>
#include <fstream>

#include "menu.h"


using namespace std;

int main(int argc, char* const argv[]){

    if(argc != 2){
        std::cout << "Correct usage: " << std::endl;
        std::cout << argv[0] << " filename" << std::endl;
        return 0;
    }
	std::string file = argv[1];
	std::ifstream wavFile;
	wavFile.open(file);


	if(wavFile.fail()){
		std::cout << "File " << file << " could not be opened." << std::endl;
		return 0;
	}
	wavFile.close();
    menu<int> menuObj;
    menuObj.switchState(file);
    return 0;
}
