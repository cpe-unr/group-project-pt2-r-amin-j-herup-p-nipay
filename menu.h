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
		menu() = default;

		//parameterized ctor
		menu(T userChoice);

		//int getMenuChoice();

		T switchState();

};



#endif
