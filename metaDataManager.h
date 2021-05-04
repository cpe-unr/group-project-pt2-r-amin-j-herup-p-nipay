#pragma once

#include "metaData.h"
#include "metaDataHeader.h"
#include <vector>
/**
 * @brief Class that allows exporting of metadata to a .csv file
 * 
 */
class MdManager{
private:
    MetaDataHeader mheader;
    std::vector<MetaData> meta_data;

public:
    /**
     * @brief Construct a new Md Manager object
     * 
     */
    MdManager() = default;
    /**
     * @brief Construct a new Md Manager object
     * 
     */
    MdManager(std::ifstream&);
    /**
     * @brief Print's stored metadata values.
     * 
     */
    void printMd();
    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize() const;
};

