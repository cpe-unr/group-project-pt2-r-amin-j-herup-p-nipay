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
