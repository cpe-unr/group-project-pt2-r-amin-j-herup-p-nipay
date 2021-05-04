#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "processor.h"
#include <iostream>
/**
 * @brief Class that makes a given file noise gate.
 * 
 */
class NoiseGate: public Processor{
	double gateLevel;
	double level;
	public:
		/**
		 * @brief Construct a new Noise Gate object
		 * 
		 */
		NoiseGate();
		/**
		 * @brief Construct a new Noise Gate object
		 * 
		 * @param level - The value for which the file will be 'noise gated'
		 */
		NoiseGate(double level);
		/**
		 * @brief Get the Level object (accessor)
		 * 
		 * @return double 
		 */
		double getLevel();
		/**
		 * @brief Set the Level object (accessor)
		 * 
		 * @param level 
		 */
		void setLevel(double level);
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

