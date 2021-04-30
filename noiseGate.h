#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "processor.h"
#include <iostream>

class NoiseGate: public Processor{
	double gateLevel;
	public:
		void processorMonoE(int size, unsigned char* buffer) = 0;
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL) = 0;
		void processorMonoS(int size, short* buffer) = 0;
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL) = 0;

		NoiseGate();
		NoiseGate(double level);

		double getLevel();
		void setLevel(double level);
};
#endif
