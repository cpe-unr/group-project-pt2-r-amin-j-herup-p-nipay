//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#include "metaData.h"

MetaData::MetaData(std::ifstream& file){
    file.read(mdID, sizeof(mdID));
    file.read((char*)&mdSize, sizeof(mdSize));
    buffer.resize(mdSize);
    file.read(&buffer[0], mdSize);
}

std::string MetaData:: getMdID() const{
    std::string dstring;
    for(char chunk : mdID){
        dstring.push_back(chunk);
    }
    dstring.push_back('\0');
    return dstring;
}

int MetaData::getMdSize() const{
    return mdSize;
}

std:: string MetaData::getBuffer() const{
    return buffer;
}

void MetaData::setBuffer(std::string newBuffer){
    this->buffer = newBuffer;
}
