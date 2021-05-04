#pragma once

#include <string>
#include <iostream>
#include <fstream>
/**
 * @brief This is the metadata class. It includes accessors for wav file metadata.
 * 
 */
class MetaData{
private:
    int mdSize;
    char mdID[4];
    std:: string buffer;
    
public:
    /**
     * @brief Construct a new Meta Data object.
     * 
     */
    MetaData() = default;
    /**
     * @brief Construct a new Meta Data object
     * 
     */
    MetaData(std::ifstream&);
    /**
     * @brief Get the MdID object
     * 
     * @return std:: 
     */
    std:: string getMdID() const;
    /**
     * @brief Set the MdID object
     * 
     */
    void setMdID(char) const;
    /**
     * @brief Get the size of the metadata object
     * 
     * @return int 
     */
    int getMdSize () const;
    /**
     * @brief Set the Md Size object
     * 
     */
    void setMdSize(int);
    /**
     * @brief Get the Buffer object
     * 
     * @return std::string 
     */
    std::string getBuffer() const;
    /**
     * @brief Set the Buffer object
     * 
     */
    void setBuffer(std::string);
    
};

