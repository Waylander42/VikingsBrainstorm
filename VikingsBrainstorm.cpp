// VikingsBrainstorm.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Board.h"
#include "BoardFactory.h"
#include "EndBoardFactory.h"
#include "Player.h"
#include "Human.h"
#include <iostream>
#include <string>

int main()
{
	Board* board = NULL;
	unsigned int endBoard;
	while (board == NULL) {
		try {
			std::cout << "Entrez le numero d'une grille : ";
			std::string s = "";
			std::cin >> s;
			int nGrid = std::stoi(s);
			board = BoardFactory::createBoard(nGrid);
			endBoard = EndBoardFactory::createEndBoard(nGrid);
		}
		catch (std::exception const & e)
		{
			board = NULL;
		}

	}
	std::cout << std::endl;
	Human player = Human(board, endBoard);
	player.play();
	char x;
	std::cout << "Entrez quelque chose pour fermer : ";
	std::cin >> x;
	return 0;

}


