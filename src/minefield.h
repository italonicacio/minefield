#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <string>

#define JOGADOR 0
#define CELULA 1
#define BOMBA 2
#define ABERTO 3

class Minefield
{
	public:

		Minefield();
		~Minefield();
		
		void LoadField(const std::string &file_name);

		void PrintField();

		void movimento_campo(int command);

		void comparacao_campo(int command);

		bool GameOver();

	private:

		int **field = nullptr;
		int player_line;
		int player_column;
		int n;
		bool game_over;
		int to_discover;
		int score;

};


#endif //MINEFIELD_H



