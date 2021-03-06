//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#pragma once


#include <string>
#include <vector>

#include "wavHeader.h"
#include "metaDataManager.h"

class Wav{
protected:
    int bufferSize_data;
    unsigned char** buffers = NULL;
    std::vector <MetaDataHeader> metadata;
    wavHeader wave_Header;
    dataChunk data_Chunk;
    FMT fmt;
    MdManager md;
public:
    wavHeader getwavHeader();
    unsigned char *getBuffer(int i);
    int getBufferSize() const;
    int getBitDepth();
    int getNumChannels();
    void readFile(const std::string &filename);
    void writeFile(const std::string &outFilename);
    void printMetaData();
    ~Wav();
    
};


