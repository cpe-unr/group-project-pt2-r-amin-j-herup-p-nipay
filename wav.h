#pragma once


#include <string>
#include <vector>

#include "wavHeader.h"
/**
 * @brief Wav class that allows for transfer to buffer
 * 
 */
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
    /**
     * @brief Generates wavHeader
     * 
     * @return wavHeader 
     */
    wavHeader getwavHeader();
    /**
     * @brief Get the Buffer object
     * 
     * @return unsigned char* 
     */
    unsigned char *getBuffer();
    /**
     * @brief Get the Buffer Size object
     * 
     * @return int 
     */
    int getBufferSize() const;
    /**
     * @brief Get the Bit Depth object
     * 
     * @return int 
     */
    int getBitDepth();
    /**
     * @brief Get the Num Channels object
     * 
     * @return int 
     */
    int getNumChannels();
    /**
     * @brief Read in file via pass by reference
     * 
     * @param filename 
     */
    void readFile(const std::string &filename);
    /**
     * @brief Write to the wav file
     * 
     * @param outFilename 
     */
    void writeFile(const std::string &outFilename);
    ~Wav();
    
};


