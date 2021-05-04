#ifndef PROCESSOR_H
#define PROCESSOR_H

/**
 * @brief Abstract class/Interface for wav processing.
 * 
 */
class Processor{
	public:
		/**
		 * @brief Inherited from processor class for 8 bit mono.
		 * 
		 * @param size - File
		 * @param buffer - Conversion and storage.
		 */
		virtual void processorMonoE(int size, unsigned char* buffer) = 0;
		/**
		 * @brief Inherited from processor class for stereo.
		 * 
		 * @param sizeR - Right channel size.
		 * @param sizeL - Left Channel size.
		 * @param bufferR - Right channel buffer.
		 * @param bufferL - Left channel buffer.
		 */
		virtual void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL) = 0;
		/**
		 * @brief Inherited from processor class for mono.
		 * 
		 * @param size - File
		 * @param buffer - Conversion and storage.
		 */
		virtual void processorMonoS(int size, short* buffer) = 0;
		/**
		 * @brief Inherited from processor class for mono
		 * 
		 * @param sizeR - Right channel size.
		 * @param sizeL - Left channel size.
		 * @param bufferR - Right channel buffer.
		 * @param bufferL - Left channel buffer.
		 */
		virtual void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL) = 0;
};
#endif

