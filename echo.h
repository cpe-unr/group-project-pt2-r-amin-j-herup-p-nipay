//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#ifndef ECHO_H
#define ECHO_H

#include "processor.h"
#include <iostream>

class Echo: public Processor{
	int delay;
	int newDelay;
	public:
		Echo();
		Echo(int newDelay);

		int getDelay();
		void setDelay(int newDelay);

		void processorMonoE(int size, unsigned char* buffer);
		void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL);
		void processorMonoS(int size, short* buffer);
		void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL);


};
#endif
