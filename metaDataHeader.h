#pragma once
/**
 * @brief Structure that defines properties of the wav file metadata.
 * 
 */
struct MetaDataHeader{
    char list_ID[4];
    int list_size;
    char info_ID[4];
};

