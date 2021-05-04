
#include <iostream>
#include <string>
#include <fstream>

#include "wav.h"

wavHeader Wav::getwavHeader(){
    return wave_Header;
}

unsigned char *Wav::getBuffer(){
    return buffer;
}
int Wav::getBufferSize() const{
	return fmt.data_bytes;
}
int Wav::getBitDepth(){
	return fmt.bit_depth;
}
int Wav::getNumChannels(){
	return fmt.num_channels;
}
void Wav::readFile(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    
    if(file.is_open()){
        file.read((char*)&wave_Header, sizeof(wavHeader));

        if (wave_Header.wav_size > 0) {
            file.read((char*)&data_Chunk, sizeof(dataChunk));
        }

        file.read((char*)&fmt, sizeof(FMT));

        dataChunk chunk;
        while (true) {
            file.read((char*)&chunk, sizeof(dataChunk));
            if (chunk.fmt_header[0] == 'd' && chunk.fmt_header[1] == 'a' && chunk.fmt_header[2] == 't' && chunk.fmt_header[3] == 'a') break;
            file.seekg(chunk.fmt_chunk_size, std::ios::cur);
        } 

        int sample_size = fmt.bit_depth / 8;
        int sample_count = chunk.fmt_chunk_size * 8 / fmt.bit_depth;
        bufferSize_data = chunk.fmt_chunk_size;
        buffer = new unsigned char[sample_count];
        for (int i = 0; i < sample_count; i++) {
            file.read((char*)&buffer[i], sample_size);
        }
        
        // while(file){
        //     file.read((char*)&data_Chunk, sizeof(dataChunk));
            
        //     std::string header_word = data_Chunk.fmt_header;
        //     int chunkSize = data_Chunk.fmt_chunk_size;
            
        //     //Format Chunk
        //     if(header_word == "FMT "){
        //         file.read((char*)&fmt, sizeof(FMT));
		// 	 bitDepth = fmt.bit_depth;
		// 	 numChannels = fmt.num_channels;
        //     }
        //     //Metadata Chunk
        //     else if(header_word == "LIST"){
        //         int counter = 0;
        //         char garbage[4];
        //         file.read(garbage, 4);
        //         while(counter < chunkSize){
        //             SubChunkData subchunk;
        //             file.read((char*)&subchunk, sizeof(dataChunk));
        //             subchunk.buffer = new char [subchunk.fmt_chunk_size];
        //             metadata.push_back(subchunk);
        //             counter += (sizeof(dataChunk) + subchunk.fmt_chunk_size);
        //         }
        //     }
        //     //Data Chunk
        //     else if(header_word == "DATA"){
        //         bufferSize_data = chunkSize;
        //         buffer = new unsigned char [chunkSize];
        //         file.read((char*)&buffer, chunkSize);
        //     }else{
        //         //*seekg: allows you to seek to an arbitrary position in a file, it is used in file handling to sets the position of the next character to be extracted from the input stream from a given file.
        //         file.seekg(chunkSize, std::ios::cur);
        //     }
        // }
    }
    file.close();

    std::cout << "RIFF HEADER: " << wave_Header.riff_header << "\n";
    std::cout << "WAV SIZE: " << wave_Header.wav_size << "\n";
    std::cout << "WAV HEADER: " << wave_Header.wave_header << "\n";
    std::cout << "FMT HEADER: " << data_Chunk.fmt_header << "\n";
    std::cout << "FMT CHUNK SIZE: " << data_Chunk.fmt_chunk_size << "\n";
    std::cout << "AUDIO FORMAT: " << fmt.audio_format << "\n";
    std::cout << "NUM OF CHANNELS: " << fmt.num_channels << "\n";
    std::cout << "SAMPLE RATE: " << fmt.sample_rate << "\n";
    std::cout << "BYTE RATE: " << fmt.byte_rate << "\n";
    std::cout << "SAMPLE ALLIGNMENT: " << fmt.sample_alignment << "\n";
    std::cout << "BIT DEPTH: " << fmt.bit_depth << "\n";
}

void Wav::writeFile(const std::string &outFilename){
    std::ofstream outFile(outFilename, std::ios::out | std::ios::binary);
    outFile.write((char*)&wave_Header, sizeof(wavHeader));
    
    //Format Chunk
    outFile.write("fmt ", 4);
    int size = sizeof(fmt);
    outFile.write((char*)&size, sizeof(size));
    outFile.write((char*)&fmt, sizeof(FMT));
    
    //Metadata Chunk
    outFile.write("LIST", 4);
    size = 4;
    for(SubChunkData s: metadata){
        size += (sizeof(dataChunk) + s.fmt_chunk_size);
    }
    outFile.write((char*)&size, sizeof(size));
    outFile.write("INFO", 4);
    for(SubChunkData s: metadata){
        outFile.write((char*)&s, sizeof(dataChunk));
        outFile.write((char*)&s.buffer, sizeof(s.fmt_chunk_size));
    }
    
    //Data Chunk
    outFile.write("DATA", 4);
    outFile.write((char*)&bufferSize_data, sizeof(bufferSize_data));
    outFile.write((char*)buffer, bufferSize_data);
}

Wav::~Wav(){
    if(buffer != NULL){
        delete[] buffer;
    }
}


//missing vectors, perserving it in vector, print out
