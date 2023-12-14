#include <iostream>
#include <fstream>

#include "keyboard.h"
#include "minefield.h"

Minefield::Minefield()
{
	this->game_over = 0;
	this->to_discover = 0;
	this->score = 0;	
}

void Minefield::LoadField(const std::string &file_name)
{
	std::ifstream ifs (file_name.c_str(), std::ifstream::in);
	ifs >> this->n;
	
	for(unsigned int i = 0; i < this->n; i++)
	{
		for(unsigned int j = 0; j < this->n; j++)
		{
			ifs >> this->field[i][j];
			
			if(this->field[i][j] == JOGADOR)
			{
				this->line_player = i;
				this->column_player = j;
			}
			
		}
		

	}
	
	
	ifs.close();
	
}


Minefield::~Minefield()
{

}


void Minefield::PrintField(){
	int i,j;
	system("cls");
	for(unsigned int i = 0; i < this->n; i++){
		
		for(unsigned int j = 0; j < this->n; j++){
			

			switch(this->field[i][j]){
				
				case JOGADOR:
						printf("[J]");
					
					
				break;
				
				case CELULA:
					printf(" X ");

				break;
				
				case BOMBA:
					if(c->descobrir == 1)
					{
						printf("[O]");


					}else if(c->descobrir == 0){
						printf(" X ");
					}



				break;
				
				case ABERTO:
					if( i == c->linhajogador  && c->colunajogador == j){
						printf("[ ]");

					}else{
						printf("   ");
					}
				break;

			}
		}
		printf("\n");

	}
	if (c->descobrir == 1)
		{
			printf("PONTUACAO FINAL = %d\n", this->score);
			printf("O JOGO ACABOU");
			c->jogoacabou = 1;
			imprimi_campo(d,c );
			
		}else{
			printf("PONTUACAO = %d\n", c->pontos);
		}



}



void Minefield::movimento_campo(campomin *c, int comando, campomin *d){
	
	int aux_line = this->player_line;
	int aux_column = this->player_column;
	
	switch(comando)
	{
		case CIMA:
			--auxlinha;
			break;
		case ESQUERDA:
			--auxcoluna;
			break;
		case DIREITA:
			++auxcoluna;
			break;
		case BAIXO:
			++auxlinha;
			break;
		case ESPACO:
			comparacao_campo(c, comando, d);
			break;
		case DESCONHECIDO:
			return;
	}
	
	if((auxlinha < 0) || (auxlinha >= c->n)
     	|| (auxcoluna < 0) || (auxcoluna >= c->n))
    {
        return;
    }
	
	/*modificações no campo*/
    switch(c->campo[auxlinha][auxcoluna]){
    	case CELULA:
    		c->campo[auxlinha][auxcoluna] = JOGADOR;
    		c->campo[c->linhajogador][c->colunajogador] = CELULA;
            c->linhajogador = auxlinha;
            c->colunajogador = auxcoluna;
            break;
        case BOMBA:
        	
        		c->campo[auxlinha][auxcoluna] = JOGADOR;
            	c->campo[c->linhajogador][c->colunajogador] = BOMBA;
            	c->linhajogador = auxlinha;
            	c->colunajogador = auxcoluna;
        	
        	break;

    }
    imprimi_campo(d,c);
}


/*Função que faz comparação de campos*/

void comparacao_campo(campomin *c, int comando, campomin *d){
	
	
	if((d->campo[c->linhajogador][c->colunajogador] == CELULA 
	   ||
	   d->campo[c->linhajogador][c->colunajogador] == JOGADOR)
	   && 
	   c->campo[c->linhajogador][c->colunajogador] != ABERTO ){
			
			c->pontos++;
			c->campo[c->linhajogador][c->colunajogador] = ABERTO;
			d->campo[c->linhajogador][c->colunajogador] = ABERTO;
			imprimi_campo(d,c);
		
	
	}else if(d->campo[c->linhajogador][c->colunajogador] == BOMBA){
		
		c->jogoacabou = 1;
		c->campo[c->linhajogador][c->colunajogador] = BOMBA;
	    c->descobrir = 1;
	    
	}
			
	
}


bool Minefield::GameOver()
{
	if(this->game_over)
		return true;
	else
		return false;
}