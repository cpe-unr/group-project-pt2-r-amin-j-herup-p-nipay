//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#include "echo.h"
#include <cmath>
Echo::Echo(){
	delay = 0;
}

Echo::Echo(int newDelay){
	delay = newDelay;
}

int Echo::getDelay(){
	return delay;
}

void Echo::setDelay(int newDelay){
	delay = newDelay;
}
void Echo::processorMonoE(int size, unsigned char* buffer){
	float nAdjust;
	float nAdjustDelayed;
	float echoLevel = .3f;
	float value;
	for(int i = 0; i < size - delay; i++){
		nAdjust = (float)(buffer[i] - 128);
		nAdjustDelayed = (float)(buffer[i + delay] - 128);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 128;
		buffer[i + delay] = (unsigned char)(round(value));
	}
}
void Echo::processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL){
	float nAdjust;
	float nAdjustDelayed;
	float echoLevel = .3f;
	float value;
	for(int i = 0; i < sizeR - delay; i++){
		nAdjust = (float)(bufferR[i] - 128);
		nAdjustDelayed = (float)(bufferR[i + delay] - 128);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 128;
		bufferR[i + delay] = (unsigned char)(round(value));
	}
	for(int i = 0; i < sizeL - delay; i++){
		nAdjust = (float)(bufferL[i] - 128);
		nAdjustDelayed = (float)(bufferL[i + delay] - 128);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 128;
		bufferL[i + delay] = (unsigned char)(round(value));
	}
}
void Echo::processorMonoS(int size, short* buffer){
	float nAdjust;
	float nAdjustDelayed;
	float echoLevel = .3f;
	float value;
	for(int i = 0; i < size - delay; i++){
		nAdjust = (float)(buffer[i] - 16385);
		nAdjustDelayed = (float)(buffer[i + delay] - 16385);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 16385;
		buffer[i + delay] = (unsigned char)(round(value));
	}
}
void Echo::processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL){
	float nAdjust;
	float nAdjustDelayed;
	float echoLevel = .3f;
	float value;
	for(int i = 0; i < sizeR - delay; i++){
		nAdjust = (float)(bufferR[i] - 16385);
		nAdjustDelayed = (float)(bufferR[i + delay] - 16385);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 16385;
		bufferR[i + delay] = (unsigned char)(round(value));
	}
	for(int i = 0; i < sizeL - delay; i++){
		nAdjust = (float)(bufferL[i] - 16385);
		nAdjustDelayed = (float)(bufferL[i + delay] - 16385);
		value = nAdjust * echoLevel + nAdjustDelayed * .3F + 16385;
		bufferL[i + delay] = (unsigned char)(round(value));
	}
}
