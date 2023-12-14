#include <iostream>
#include "minefield.h"
#include "keyboard.h"


int main(){

	std::string file_name = "../fields/game.txt";
	Minefield c;
	Minefield d;
	
		
	c.LoadField(file_name);
	
	d.LoadField(file_name);
	
	imprimi_campo(&c, &d);
	
	while(!c.GameOver()){
		int comando;
		comando = tecla();
		movimento_campo(&c, comando, &d);
		
	}
	
	return 0;
} 
