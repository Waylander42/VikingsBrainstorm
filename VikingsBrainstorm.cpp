// VikingsBrainstorm.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Board.h"
#include "BoardFactory.h"
#include <iostream>

int main()
{
	std::cout << "Entrez le numero d'une grille : ";
	int nGrid;
	std::cin >> nGrid;
	std::cout << std::endl;
	Board* board = BoardFactory::createBoard(nGrid);
	board->print();
	char x;
	std::cout << "Entrez quelque chose pour fermer : ";
	std::cin >> x;
	return 0;
}

