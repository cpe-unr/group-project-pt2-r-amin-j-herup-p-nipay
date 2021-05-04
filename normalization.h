#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "processor.h"
#include <iostream>
/**
 * @brief Class that normalizes given wav file.
 * 
 */
class Normalization: public Processor{
	int adjustLevel;
	int newAdjustLevel;
	public:
		/**
		 * @brief Construct a new Normalization object
		 * 
		 */
		Normalization();
		/**
		 * @brief Construct a new Normalization object
		 * 
		 * @param newAdjustLevel - Based off wav file input
		 */
		Normalization(int newAdjustLevel);
		/**
		 * @brief Get the Adjust Level object
		 * 
		 * @return int 
		 */
		int getAdjustLevel();
		/**
		 * @brief Set the Adjust Level object
		 * 
		 * @param newAdjustLevel 
		 */
		void setAdjustLevel(int newAdjustLevel);
		/**
		 * @brief Inherited from processor class for 8 bit mono.
		 * 
		 * @param size - File
		 * @param buffer - Conversion and storage.
		 */
		void processorMonoE(int size, unsigned char* buffer);
		/**
		 * @brief Inherited from processor class for stereo.
		 * 
		 * @param sizeR - Right channel size.
		 * @param sizeL - Left Channel size.
		 * @param bufferR - Right channel buffer.
		 * @param bufferL - Left channel buffer.
		 */
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL);
		/**
		 * @brief Inherited from processor class for mono.
		 * 
		 * @param size - File
		 * @param buffer - Conversion and storage.
		 */
		void processorMonoS(int size, short* buffer);
		/**
		 * @brief Inherited from processor class for mono
		 * 
		 * @param sizeR - Right channel size.
		 * @param sizeL - Left channel size.
		 * @param bufferR - Right channel buffer.
		 * @param bufferL - Left channel buffer.
		 */
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL);


};
#endif

