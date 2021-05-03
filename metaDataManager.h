#pragma once

#include "metaData.h"
#include "metaDataHeader.h"
#include <vector>

class MdManager{
private:
    MetaDataHeader mheader;
    std::vector<MetaData> meta_data;

public:
    MdManager() = default;
    MdManager(std::ifstream&);
    
    void printMd();
    int getSize() const;
};
