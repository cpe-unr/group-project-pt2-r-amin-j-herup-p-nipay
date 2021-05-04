
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


int MdManager::getMdSize() const{
    return meta_data.list_size();
}

char MdManager::getMdID() const{ //convert char to string
    std::string dString;
    for(char chunk : list_ID){
        dstring.push_back(chunk);
    }
    dstring.push_back('\0');
    
    return dstring;;
}

char MdManager::getBuffer() const{
    std::string bString;
    for(char chunk : list_ID){
        bstring.push_back(chunk);
    }
    bstring.push_back('\0');
    
    return bstring;
}
void MdManager::setBuffer(std::string newBuffer){
    this->buffer = newBuffer;
}

char MdManager::getINAM() const{
    std::string iString;
    for(char chunk : list_ID){
        istring.push_back(chunk);
    }
    istring.push_back('\0');
    
    return istring;;
   
}

char MdManager::getIART() const{
    std::string aString;
    for(char chunk : IART){
        astring.push_back(chunk);
    }
    astring.push_back('\0');
    
    return astring;
;
}

char MdManager::getIGNR() const{
    std::string aString;
    for(char chunk : IGNR){
        gstring.push_back(chunk);
    }
    gstring.push_back('\0');
    
    return gstring;;
 
}

char MdManager::getICRD() const{
    std::string cString;
    for(char chunk : ICRD){
        cstring.push_back(chunk);
    }
    cstring.push_back('\0');
    
    return cstring;;
   
}

char MdManager::getITRK() const{
    std::string tString;
    for(char chunk : ITRK){
        tstring.push_back(chunk);
    }
    tstring.push_back('\0');
    
    return tstring;;

}

char MdManager::getICMT() const{
    std::string mString;
    for(char chunk : ICMT){
        mstring.push_back(chunk);
    }
    mstring.push_back('\0');
    
    return mstring;
}

void MdManager::printMd(){
    for(MetaData& metaD : meta_data){
        std::cout << metaD.getMdID() << '\n' << metaD.getMdSize() << '\n Info: ' << metaD.getMdInfo() << '\n Song Title: ' << metaD.getINAM << '\n Artist: ' << metaD.getIART << '\n Genre: ' << metaD.getIGNR << '\n Release: ' << metaD.getICRD << '\n Track Number: ' << metaD.getITRK << '\n Comments: '<< metaD.getICMT << std::endl;
    }
}

