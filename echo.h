#ifndef ECHO_H
#define ECHO_H

#include "processor.h"
#include <iostream>
/**
 * @brief This is the echo class. It produces an echo effect in a file.
 * 
 */
class Echo: public Processor{
	int delay;
	int newDelay;
	public:
		/**
		 * @brief Construct a new Echo object.
		 * 
		 */
		Echo();
		/**
		 * @brief Construct a new Echo object with parameters.
		 * 
		 * @param newDelay - Used for logic of echo class.
		 */
		Echo(int newDelay);
		/**
		 * @brief Get the Delay object. An accessor.
		 * 
		 * @return int - Receives a value for which the program will echo.
		 */
		int getDelay();
		/**
		 * @brief Set the Delay object.
		 * 
		 * @param newDelay - Offset the given value by a set amount per the class.
		 */
		void setDelay(int newDelay);
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

