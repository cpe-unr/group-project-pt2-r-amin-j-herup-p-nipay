#include "metaData.h"

MetaData::MetaData(std::ifstream& file){
    file.read(mdID, sizeof(mdID));
    file.read((char*)&mdSize, sizeof(mdSize));
    buffer.resize(mdSize);
    fileread(&buffer[0], mdSize);
}

std::string MetaData:: getMdID() const;{
    std::string dstring;
    for(char chunk : mdID){
        dstring.push_back(chunk);
    }
    str.push_back('\0');
    return dstring;
}
void MetaData:: setMdID(char mdID){
    this->mdID = mdID;
}

int MetaData::getMdSize() const{
    return mdSize;
}
void MetaData:: setMdSize(int mdSize){
    this->mdSize = mdSize;
}

std:: string MetaData::getBuffer() const{
    return buffer;
}

void MetaData::setBuffer(std::string newBuffer){
    this->buffer = newBuffer;
}
