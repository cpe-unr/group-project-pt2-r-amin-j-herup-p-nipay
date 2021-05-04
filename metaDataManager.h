
//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#pragma once

#pragma once

#include "metaDataHeader.h"
#include <vector>

class MdManager{
private:
    MetaDataHeader list_ID;
    MetaDataHeader list_size;
    MetaDataHeader info_ID;
    MetaDataHeader INAM;
    MetaDataHeader IART;
    MetaDataHeader IGNR;
    MetaDataHeader ICRD;
    MetaDataHeader ITRK;
    MetaDataHeader ICMT;

    std::vector<MetaData> meta_data;

public:
    MdManager() = default;
    MdManager(std::ifstream&);
    
    void printMd();
    
    char getMdID() const;

    int getMdSize() const;

    char getMdID() const;

    char getBuffer() const;
    void setBuffer(std::string);

    char getINAM() const;

    char getIART() const;

    char getIGNR() const;

    char getICRD() const;

    char getITRK() const;

    char getICMT() const;

};
