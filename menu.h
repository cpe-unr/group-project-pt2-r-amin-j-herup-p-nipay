//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 3/2/2021
//Semester Project

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "processor.h"
#include "wavHeader.h"
#include "wav.h"
#include "echo.h"
#include "noiseGate.h"
#include "normalization.h"
//#include the wav guys

using namespace std;

template<typename T>
class menu{

    private:
	T userChoice, userChoice2, userChoice5, userChoice4, userChoice3;
	T Yn, Yn2, Yn3, Yn4, Yn5, Yn6, Yn7, Yn8, Yn9;
	string outFileName;
	//void wavManager, wavIO;

    public:
	//default ctor
	menu();
	//parameterized ctor
	menu(T userChoice);

	//int getMenuChoice();

	void switchState(string fileName);


};

template<typename T>
menu<T>::menu(){
    userChoice = 0;
}

//parameterized ctor
template<typename T>
menu<T>::menu(T userChoice) : userChoice(userChoice){
}

template<typename T>
void menu<T>::switchState(string fileName){
//wavManager and wavIO class, pass in objects of those class to menu, in default ctor of menu set equal to class, and in main.cpp wavManager and wavIO get created first, then create menu and pass in objects via constructor
	Wav wav;
	wav.readFile(fileName);

	do{

		//int userInput;
		cout << "**AUDIO FILE MANAGEMENT SYSTEM**" << endl;
		cout << "1. Modify/Add Metadata" << endl;
		cout << "2. Process Files" << endl;
		cout << "3. Export Files" << endl;
		cout << "0. EXIT" << endl;
		cout << "What do you want to do? " << endl;
		cin >> userChoice;

	    //userChoice = getMenuChoice();
	    switch(userChoice){
		case 1:
		cout << "Creating Metadata..." << endl;
		//modifyMetadata function
			break;
		case 2:
			//processFiles function
			cout << "How do you want to process your files?" << endl;
			cout << "1. Normalization" << endl;
			cout << "2. Noise Gate" << endl;
			cout << "3. Echo" << endl;
			cout << "Pick one: " << endl;
			cin >> userChoice2;
		
			switch(userChoice2){
			    case 1:
				cout << "One normalization coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
				cin >> Yn;
				
					if(Yn == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Noise Gate" << endl;
						cout << "2. Echo" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice3;

						switch(userChoice3){
							case 1:
						   		cout << "One normalization and one noise gate coming right up, do you want to echo your file as well? (enter 1 for yes and 2 for no) " << endl;
						    		cin >> Yn2;
								if(Yn2 == 1){
									cout << "One normalization, one noise gate, and one echo coming right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											cout << "Normalize, gate, echo, 8bit mono" << endl;
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){
											/*int size = wav.getBufferSize();
											short* buffer = wav.getBuffer();
											Processor *normalization = new Normalization(3);
											normalization->processorMonoS(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoS(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoS(size, buffer);*/
										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add normailization then noise gate then echo then break
								}else if(Yn2 == 2){
									cout << "Alright, one normalization and one noise gate coming right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add normalization and noise gate and break
								}
								break;
							case 2:
						    		cout << "One normalization and one echo coming right up, do you want to noise gate your file as well? (enter 1 for yes and 2 for no) " << endl;
						   		cin >> Yn3;
								if(Yn3 == 1){
									cout << "One normalization, one echo, and one noise gate coming right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add normailization then echo then noise gate then break;
								}else if(Yn3 == 2){
									cout << "Alright, one normalization and one echo coming right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add normalization and echo and break
								}
					        }
					}else if(Yn == 2){
						cout << "Alright, just the normalization, coming right up!" << endl;
						if(wav.getBitDepth() == 8){
							if(wav.getNumChannels() == 1){
								int size = wav.getBufferSize();
								unsigned char* buffer = wav.getBuffer(0);
								Processor *normalization = new Normalization(3);
								normalization->processorMonoE(size, buffer);
								break;
							}
							else if(wav.getNumChannels() == 2){
								int size = wav.getBufferSize();
								int newSize = size/2;
								unsigned char* bufferL = wav.getBuffer(0);
								unsigned char* bufferR = wav.getBuffer(1);
								Processor *normalization = new Normalization(3);
								normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
								break;
							}
							else{
								cout << "Invalid audio file." << endl;
								break;
							}
						}
						else if(wav.getBitDepth() == 16){
							if(wav.getNumChannels() == 1){

							}
							else if(wav.getNumChannels() == 2){

							}
							else{
								cout << "Invalid audio file." << endl;
								break;
							}	
						}
						else{
							cout << "Invalid audio file." << endl;
							break;
						}
						//add normalization and break
						break;
					}
					break;
			    case 2:
					cout << "One noise gate coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
					cin >> Yn4;

					if(Yn4 == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Normalization" << endl;
						cout << "2. Echo" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice4;
						
						switch(userChoice4){
							case 1:
								cout << "One noise gate and one normalization coming right up, do you want to echo your file as well? (enter 1 for yes and 2 for no) " << endl;
						    		cin >> Yn5;
								if(Yn5 == 1){
									cout << "All three comin right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add noise gate then normalization then echo then break;
								}else if(Yn5 == 2){
									cout << "Alright, just noise gate and normalization." << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}	
									//add noise gate then normalization then break;
								}
								break;
							case 2:
								cout << "One noise gate and one echo comin right up, do you want to normalize as well? (enter 1 for yes and 2 for no) " << endl;
								cin >> Yn6;
								if(Yn6 == 1){
									cout << "All three coming right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add noise gate then echo then normalization then break
								}else if(Yn6 == 2){
									cout << "Alright, just noise gate and echo." << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;
										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add noise gate then echo and break
								}
						}
					}else if(Yn4 == 2){
						cout << "Alright, just the noise gate, comin right up!" << endl;
						if(wav.getBitDepth() == 8){
							if(wav.getNumChannels() == 1){
								int size = wav.getBufferSize();
								unsigned char* buffer = wav.getBuffer(0);
								Processor *noiseGate = new NoiseGate(2);
								noiseGate->processorMonoE(size, buffer);
								break;
							}
							else if(wav.getNumChannels() == 2){
								int size = wav.getBufferSize();
								int newSize = size/2;
								unsigned char* bufferL = wav.getBuffer(0);
								unsigned char* bufferR = wav.getBuffer(1);
								Processor *noiseGate = new NoiseGate(2);
								noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
								break;
							}
							else{
								cout << "Invalid audio file." << endl;
								break;
							}
						}
						else if(wav.getBitDepth() == 16){
							if(wav.getNumChannels() == 1){

							}
							else if(wav.getNumChannels() == 2){

							}
							else{
								cout << "Invalid audio file." << endl;
								break;
							}	
						}
						else{
							cout << "Invalid audio file." << endl;
							break;
						}
						//add noise gate then break;
					}
					break;
				case 3:
					cout << "One echo coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
					cin >> Yn7;
			
					if(Yn7 == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Normalization" << endl;
						cout << "2. Noisegate" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice5;

						switch(userChoice5){
							case 1:
						    		cout << "One echo and one normalization coming right up, do you want to noise gate your file as well? (enter 1 for yes and 2 for no) " << endl;
						   		cin >> Yn8;
								if(Yn8 == 1){
									cout << "All three comin right up!" << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add echo then normalization then noise gate then break
								}else if(Yn8 == 2){
									cout << "Alright just echo and normalization." << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add echo then normalization then break
								}
								break;
							case 2:
								cout << "One echo and one noise gate coming right up, do you want to normalize your file as well? (enter 1 for yes and 2 for no) " << endl;
								cin >> Yn9;
							    	if(Yn9 == 1){
									cout << "All three comin right up!" << endl;

									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											Processor *normalization = new Normalization(3);
											normalization->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *normalization = new Normalization(3);
											normalization->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}									//add echo then noise gate then normalization then break
							    	}else if(Yn9 == 2){
									cout << "Alright just echo and noise gate." << endl;
									if(wav.getBitDepth() == 8){
										if(wav.getNumChannels() == 1){
											int size = wav.getBufferSize();
											unsigned char* buffer = wav.getBuffer(0);
											Processor *echo = new Echo(10000);
											echo->processorMonoE(size, buffer);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorMonoE(size, buffer);
											break;
										}
										else if(wav.getNumChannels() == 2){
											int size = wav.getBufferSize();
											int newSize = size/2;
											unsigned char* bufferL = wav.getBuffer(0);
											unsigned char* bufferR = wav.getBuffer(1);
											Processor *echo = new Echo(10000);
											echo->processorStereoE(newSize, newSize, bufferR, bufferL);
											Processor *noiseGate = new NoiseGate(2);
											noiseGate->processorStereoE(newSize, newSize, bufferR, bufferL);
											break;

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}
									}
									else if(wav.getBitDepth() == 16){
										if(wav.getNumChannels() == 1){

										}
										else if(wav.getNumChannels() == 2){

										}
										else{
											cout << "Invalid audio file." << endl;
											break;
										}	
									}
									else{
										cout << "Invalid audio file." << endl;
										break;
									}
									//add echo then noise gate then break;
							    	}
						}
					}
				
			}	
			cout << "Please input a file name, followed by the .wav extension." << endl;
			cin >> outFileName;
			wav.writeFile(outFileName);
			cout << "Processing Files..." << endl;

			break;
		case 3:
			//exportFiles function
			cout << "Exporting Files..." << endl;

			break;
		case 0:

			break;

		default:
			cout << "Not a valid option." << endl;
			break;
		}
	}while(userChoice != 0);
}
#endif
