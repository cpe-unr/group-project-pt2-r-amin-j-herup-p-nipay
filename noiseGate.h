#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "processor.h"
#include <iostream>

class NoiseGate: public Processor{
	double gateLevel;
	double level;
	public:
		NoiseGate();
		NoiseGate(double level);

		double getLevel();
		void setLevel(double level);

		void processorMonoE(int size, unsigned char* buffer);
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL);
		void processorMonoS(int size, short* buffer);
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL);


};
#endif
