#pragma once

struct wavHeader{
    char riff_header[4]; //RIFF 4 Bytes
    char wave_header[4]; //Wave
    int wav_size; //file 8 bytes
};

struct dataChunk{
    char fmt_header[4]; //Data
    int fmt_chunk_size; //size of chunk in bytes
}

struct FMT{
    int sample_rate; // sample rate
    int byte_rate; //byte rate
    short audio_format; //numeric if of audio format
    short num_channels; //numeric of audio channels
    short sample_alignment; //sample alignment
    short bit_depth; //bit depth
};

struct SubChunckData: public dataChunk{
    char *buffer;
};
