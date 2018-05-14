// VikingsBrainstorm.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Board.h"
#include "BoardFactory.h"
#include "Player.h"
#include "Human.h"
#include <iostream>

int main()
{
	std::cout << "Entrez le numero d'une grille : ";
	int nGrid;
	std::cin >> nGrid;
	std::cout << std::endl;
	Board* board = BoardFactory::createBoard(nGrid);
	/*for (int i = 1; i < 12; i++) {
		Board* board = BoardFactory::createBoard(i);
		std::cout << board->getIdentity();
		std::cout << " @ ";
	}
	for (int j = 2; j < 7; j++) {
		Board* board = BoardFactory::createBoard(j*10);
		std::cout << board->getIdentity();
		std::cout << " @ ";
	}*/
	Human player = Human(board);
	player.play();
	char x;
	std::cout << "Entrez quelque chose pour fermer : ";
	std::cin >> x;
	return 0;

}


