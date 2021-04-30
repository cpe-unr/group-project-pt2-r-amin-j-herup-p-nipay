#include "noiseGate.h"

NoiseGate::NoiseGate(){
	gateLevel = 0;
}

NoiseGate::NoiseGate(double level){
	gateLevel = level;
}

double NoiseGate::getLevel(){
	return gateLevel;
}

void NoiseGate::setLevel(double level){
	gateLevel = level;
}

void NoiseGate::processorMonoE(int size, unsigned char* buffer){
	for(int i = 0; i < size; i++){
		if(buffer[i] > 128 && buffer[i] < (128 + level)){
			buffer[i] = 128;
		}
		else if(buffer[i] < 128 && buffer[i] > (128 - level)){
			buffer[i] = 128;
		}
	}
}

void NoiseGate::processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL){
	for(int i = 0; i < sizeR; i++){
		if(bufferR[i] > 128 && bufferR[i] < (128 + level)){
			bufferR[i] = 128;
		}
		else if(bufferR[i] < 128 && bufferR[i] > (128 - level)){
			bufferR[i] = 128;
		}
	}
	for(int i = 0; i < sizeL; i++){
		if(bufferL[i] > 128 && bufferL[i] < (128 + level)){
			bufferL[i] = 128;
		}
		else if(bufferL[i] < 128 && bufferL[i] > (128 - level)){
			bufferL[i] = 128;
		}
	}
}
void NoiseGate::processorMonoS(int size, short* buffer){
	for(int i = 0; i < size; i++){
		if(buffer[i] > 16385 && buffer[i] < (16385 + level)){
			buffer[i] = 16385;
		}
		else if(buffer[i] < 16385 && buffer[i] > (16385 - level)){
			buffer[i] = 16385;
		}
	}
}
void NoiseGate::processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL){
	for(int i = 0; i < sizeR; i++){
		if(bufferR[i] > 16385 && bufferR[i] < (16385 + level)){
			bufferR[i] = 16385;
		}
		else if(bufferR[i] < 16385 && bufferR[i] > (16385 - level)){
			bufferR[i] = 16385;
		}
	}
	for(int i = 0; i < sizeL; i++){
		if(bufferL[i] > 16385 && bufferL[i] < (16385 + level)){
			bufferL[i] = 16385;
		}
		else if(bufferL[i] < 16385 && bufferL[i] > (16385 - level)){
			bufferL[i] = 16385;
		}
	}
}


