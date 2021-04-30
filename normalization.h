#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "processor.h"
#include <iostream>

class Normalization: public Processor{
	int adjustLevel;
	int newAdjustLevel;
	public:
		Normalization();
		Normalization(int newAdjustLevel);

		int getAdjustLevel();
		void setAdjustLevel(int newAdjustLevel);

		void processorMonoE(int size, unsigned char* buffer);
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL);
		void processorMonoS(int size, short* buffer);
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL);


};
#endif
