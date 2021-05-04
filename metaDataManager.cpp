
//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project
#include "metaDataManager.h"

MdManager::MdManager(std::ifstream& file){
    file.read((char*)&mheader, sizeof(MetaDataHeader));
    int i = 0, count = 0;

    while(i < mheader.list_size){
        meta_data.emplace_back(file);
        
        i += meta_data[count++].getMdSize();
    }
}

void MdManager::printMd(){
    for(MetaData& metaD : meta_data){
        std::cout << metaD.getMdID() << '\n' << metaD.getMdSize() << '\n' << metaD.getBuffer() << std::endl;
    }
}

int MdManager::getSize() const{
    return meta_data.size();
}
