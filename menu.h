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
#endif
