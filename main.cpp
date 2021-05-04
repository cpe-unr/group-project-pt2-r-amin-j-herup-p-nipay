
/** @file */
#include <iostream>
#include <fstream>

#include "menu.h"
#include "wav.h"
#include "metaData.h"
/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

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

    /*
    WavManager wavM(argv[1]);
    if(wavM.getSize() < 1){
        return 0;
    }
    for(int i =0; i < wavM.getSize(); i++){
        std::cout << "File" << i << ": " << wavM.getWav(i)->getFileName() << std::endl;
        wavM.getWav(i)->printMetaData();
        std::cout << std::endl;
    }
    */
    menu<int> menuObj;
    //menuObj.getMenuChoice();
    menuObj.switchState(file);
    return 0;
}
