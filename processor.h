//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#ifndef PROCESSOR_H
#define PROCESSOR_H


class Processor{
	public:
		virtual void processorMonoE(int size, unsigned char* buffer) = 0;

		virtual void processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL) = 0;

		virtual void processorMonoS(int size, short* buffer) = 0;

		virtual void processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL) = 0;
};
#endif
