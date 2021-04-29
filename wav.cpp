
#include "wav.h"

wav_header wav::getWavHeader(){
    return waveHeader;
}


void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        
        while(file){
            file.read(char*)&info, sizeof(info));
            
            string header_word = info.fmt_header;
            int infoSize = info.fmt_info_size;
            
            if(header_word == "FMT"){
                file.read((char*)&fmt, sizeof(FMT);
            }
            else if(header_word == "LIST"){
                file.read((char*)&metadata, sizeof(METADATA);
            }
            else if(header_word == "DATA"){
                file.read((char*)&data, sizeof(DATA);
            }
                else{
                    file.setg(infoSize);
                }
            
    file.read((char*)buffer, waveHeader.data_bytes);
    file.close();
        }
    unsigned char low = buffer[0];
    unsigned char high = buffer[1];
    short s = ((short*)buffer)0];
    short s1 - (*(short*)buffer);
}

unsigned char *wav::getBuffer(){
    return buffer;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}
