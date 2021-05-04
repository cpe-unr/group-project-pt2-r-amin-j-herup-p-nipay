//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#pragma once

#include <string>
#include <iostream>
#include <fstream>

class MetaData{
private:
    int mdSize;
    char mdID[4];
    std:: string buffer;
    
public:
    MetaData() = default;
    MetaData(std::ifstream&);
    
    std:: string getMdID() const;
    
    int getMdSize () const;
    
    std::string getBuffer() const;
    void setBuffer(std::string);
    
};
