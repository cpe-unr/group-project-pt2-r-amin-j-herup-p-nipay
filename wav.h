#pragma once


#include <string>
#include <vector>

#include "wavHeader.h"

class Wav{
protected:
    int bufferSize_data;
    unsigned char* buffer = NULL;
    int bitDepth;
    int numChannels;
    std::vector <SubChunkData> metadata;
    wavHeader wave_Header;
    dataChunk data_Chunk;
    FMT fmt;
public:
    wavHeader getwavHeader();
    unsigned char *getBuffer();
    int getBufferSize() const;
    int getBitDepth();
    int getNumChannels();
    void readFile(const std::string &filename);
    void writeFile(const std::string &outFilename);
    ~Wav();
    
};

