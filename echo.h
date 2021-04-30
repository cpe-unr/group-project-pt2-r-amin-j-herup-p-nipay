#ifndef ECHO_H
#define ECHO_H

#include "processor.h"
#include <iostream>

class Echo: public Processor{
	int delay;
	int newDelay;
	public:
		Echo();
		Echo(double newDelay);

		int getDelay();
		void setDelay(double newDelay);

		void processorMonoE(int size, unsigned char* buffer);
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL);
		void processorMonoS(int size, short* buffer);
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL);


};
#endif
