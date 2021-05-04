#pragma once

struct wavHeader{
    char riff_header[4]; //RIFF
    char wave_header[4]; //WAVE
    int wav_size; //total size of file in bytes - 8
};

struct dataChunk{
    char fmt_header[4]; //DATA
    int fmt_chunk_size; //size of chunk in bytes
};

struct FMT{
    unsigned short audio_format; //numeric id of audio format
    unsigned short num_channels; //number of audio channels
    int sample_rate; //sample rate
    int byte_rate; //byte rate
    unsigned short sample_alignment; //sample alignment
    unsigned short bit_depth; //bitdepth
};

struct SubChunkData: public dataChunk{
    char *buffer;
};
