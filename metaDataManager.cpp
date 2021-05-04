
//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project
#include "metaDataManager.h"

MdManager::MdManager(std::ifstream& file){
    file.read((char*)&list_ID, sizeof(list_ID));
    file.read((char*)&list_size, sizeof(list_size));
    file.read((char*)&info_ID, sizeof(info_ID));
    file.read((char*)&INAM, sizeof(INAM));
    file.read((char*)&IART, sizeof(IART));
    file.read((char*)&IGNR, sizeof(IGNR));
    file.read((char*)&ICRD, sizeof(ICRD));
    file.read((char*)&ITRK, sizeof(ITRK));
    file.read((char*)&ICMT, sizeof(ICMT));
    int i = 0, count = 0;

    while(i < mheader.list_size){
        meta_data.emplace_back(file);
        
        i += meta_data[count++].getMdSize();
    }
}

char MdManager::getMdID() const{
    return meta_data.list_ID();
}

int MdManager::getMdSize() const{
    return meta_data.list_size();
}

char MdManager::getMdID() const{
    return meta_data.info_ID();
}

char MdManager::getBuffer() const{
    return buffer;
}

char MdManager::getINAM() const{
    return meta_data.INAM();
}

char MdManager::getIART() const{
    return meta_data.IART();
}

char MdManager::getIGNR() const{
    return meta_data.IGNR();
}

char MdManager::getICRD() const{
    return meta_data.ICRD();
}

char MdManager::getITRK() const{
    return meta_data.ITRK();
}

char MdManager::getICMT() const{
    return meta_data.ICMT();
}

void MdManager::printMd(){
    for(MetaData& metaD : meta_data){
        std::cout << metaD.getMdID() << '\n' << metaD.getMdSize() << '\n' << metaD.getBuffer() << '\n Song Title: ' << metaD.getINAM << '\n Artist: ' << metaD.getIART << '\n Genre: ' << metaD.getIGNR << '\n Release: ' << metaD.getICRD << '\n Track Number: ' << metaD.getITRK << '\n Comments: '<< metaD.getICMT << std::endl;
    }
}



