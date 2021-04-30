#include "normalization.h"

Normalization::Normalization(){
	adjustLevel = 0;
}

Normalization::Normalization(int newAdjustLevel){
	adjustLevel = newAdjustLevel;
}

int Normalization::getAdjustLevel(){
	return adjustLevel;
}

void Normalization::setAdjustLevel(int newAdjustLevel){
	adjustLevel = newAdjustLevel;
}

void Normalization::processorMonoE(int size, unsigned char* buffer){
	for(int i = 0; i < size - 1; i++){
		if(buffer[i] < 128){
			if((buffer[i] -= adjustLevel) >= 0){
				buffer[i] -= adjustLevel;
			}
			else{
				buffer[i] = 0;
			}
		}
		else if(buffer[i] > 128){
			if((buffer[i] += adjustLevel) <= 255){
				buffer[i] += adjustLevel;
			}
			else{
				buffer[i] = 255;
			}
		}
	}
}

void Normalization::processorStereoE(int sizeR, int sizeL, unsigned char* bufferR, unsigned char* bufferL){
	for(int i = 0; i < sizeR - 1; i++){
		if(bufferR[i] < 128){
			if((bufferR[i] -= adjustLevel) >= 0){
				bufferR[i] -= adjustLevel;
			}
			else{
				bufferR[i] = 0;
			}
		}
		else if(bufferR[i] > 128){
			if((bufferR[i] += adjustLevel) <= 255){
				bufferR[i] += adjustLevel;
			}
			else{
				bufferR[i] = 255;
			}
		}
	}
	for(int i = 0; i < sizeL - 1; i++){
		if(bufferL[i] < 128){
			if((bufferL[i] -= adjustLevel) >= 0){
				bufferL[i] -= adjustLevel;
			}
			else{
				bufferL[i] = 0;
			}
		}
		else if(bufferL[i] > 128){
			if((bufferL[i] += adjustLevel) <= 255){
				bufferL[i] += adjustLevel;
			}
			else{
				bufferL[i] = 255;
			}
		}
	}
}

void Normalization::processorMonoS(int size, short* buffer){
	for(int i = 0; i < size - 1; i++){
		if(buffer[i] < 16385){
			if((buffer[i] -= adjustLevel) >= 0){
				buffer[i] -= adjustLevel;
			}
			else{
				buffer[i] = 0;
			}
		}
		else if(buffer[i] > 16385){
			if((buffer[i] += adjustLevel) <= 32769){
				buffer[i] += adjustLevel;
			}
			else{
				buffer[i] = 32769;
			}
		}
	}
}

void Normalization::processorStereoS(int sizeR, int sizeL, short* bufferR, short* bufferL){
	for(int i = 0; i < sizeR - 1; i++){
		if(bufferR[i] < 16385){
			if((bufferR[i] -= adjustLevel) >= 0){
				bufferR[i] -= adjustLevel;
			}
			else{
				bufferR[i] = 0;
			}
		}
		else if(bufferR[i] > 16385){
			if((bufferR[i] += adjustLevel) <= 32769){
				bufferR[i] += adjustLevel;
			}
			else{
				bufferR[i] = 32769;
			}
		}
	}
	for(int i = 0; i < sizeL - 1; i++){
		if(bufferL[i] < 16385){
			if((bufferL[i] -= adjustLevel) >= 0){
				bufferL[i] -= adjustLevel;
			}
			else{
				bufferL[i] = 0;
			}
		}
		else if(bufferL[i] > 16385){
			if((bufferL[i] += adjustLevel) <= 32769){
				bufferL[i] += adjustLevel;
			}
			else{
				bufferL[i] = 32769;
			}
		}
	}
}
