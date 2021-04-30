#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "processor.h"
#include <iostream>

class NoiseGate: public Processor{
	double gateLevel;
	public:
		NoiseGate();
		NoiseGate(double level);

		double getLevel();
		void setLevel(double level);

		void processorMonoE(int size, unsigned char* buffer) = 0;
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL) = 0;
		void processorMonoS(int size, short* buffer) = 0;
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL) = 0;


};
#endif
