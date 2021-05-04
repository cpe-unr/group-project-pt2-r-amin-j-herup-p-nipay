//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#pragma once

struct MetaDataHeader{
    char list_ID[4]; //contains LIST
    int list_size;
    char info_ID[4]; //contains INFO store it in vector
    char INAM[4]; //contains song title
    char IART[4]; //contains artist name
    char IGNR[4]; //contains genre
    char ICRD[4]; //contains release time
    char ITRK[4]; //contains track number
    char ICMT[4]; //contains comments
};
