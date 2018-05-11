// VikingsBrainstorm.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Board.h"
#include "BoardFactory.h"
#include <iostream>

/*
int getIdentity() {
	int boardID = board[0][0].getIdentity() + board[0][1].getIdentity() * 6 + board[0][2].getIdentity() * 36
		+ board[1][0].getIdentity() * 216 + board[1][1].getIdentity() * 1296 + board[1][2].getIdentity() * 7776
		+ board[2][0].getIdentity() * 46656 + board[2][1].getIdentity() * 279936 + board[2][2].getIdentity() * 1679616;
	int boatsID = 0;
	for (int i = 0; i < nbBoats; i++) {
		boatsID = boats[i].getIdentity();
	}
	int ID = boardID + boatsID;
	return ID;	
}
*/

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


