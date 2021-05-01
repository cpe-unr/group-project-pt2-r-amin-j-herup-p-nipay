//Roohan Amin, Pamella Nipay, Josh Herup
//Date: 5/2/2021
//Semester Project

#ifndef MENU_H
#define MENU_H

#include <iostream>
//#include the wav guys

using namespace std;

template<typename T>
class menu{

    private:
	T userChoice;
	//void wavManager, wavIO;

    public:
	//default ctor
	menu();
	//parameterized ctor
	menu(T userChoice);

	//int getMenuChoice();

	T switchState();

};

#include "menu.cpp"

template<typename T>
menu<T>::menu(){
    userChoice = 0;
}

//parameterized ctor
template<typename T>
menu<T>::menu(T userChoice) : userChoice(userChoice){
}

/*
int menu::getMenuChoice(){

	int userInput;
	cout << "**AUDIO FILE MANAGEMENT SYSTEM**" << endl;
	cout << "1. Modify/Add Metadata" << endl;
	cout << "2. Process Files" << endl;
	cout << "3. Export Files" << endl;
	cout << "0. EXIT" << endl;
	cout << "What do you want to do? " << endl;
	cin >> userInput;

	return userInput;
}
*/

template<typename T>
T menu<T>::switchState(){
//wavManager and wavIO class, pass in objects of those class to menu, in default ctor of menu set equal to class, and in main.cpp wavManager and wavIO get created first, then create menu and pass in objects via constructor
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
