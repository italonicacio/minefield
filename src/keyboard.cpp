#include <iostream>

#include "keyboard.h"


int key(){
	
	int command;
	std::cin >> command;
	switch(command)
	{
		case 72:
			return UP;
			
		case 75:
			return LEFT;
			
		case 80:
			return DOWN;
			
		case 77:
			return RIGHT;

		case 32: 
			return SPACE;
			
		default:
			return UNKNOWN;
			
	}
}

