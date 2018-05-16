// VikingsBrainstorm.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Board.h"
#include "BoardFactory.h"
#include "EndBoardFactory.h"
#include "Player.h"
#include "Human.h"
#include "Constantes.h"
#include "IA.h"
#include "ParcoursEnLargeur.h"
#include <iostream>
#include <string>

int main()
{
	Board* board = NULL;
	unsigned int endBoard;
	int modeJeu = 0;
	int nAlgo = 0;
	while (modeJeu == 0) {
		try {
			std::cout << "Choisissez votre mode de jeu :" << std::endl;
			std::cout << "1 : Humain" << std::endl;
			std::cout << "2 : IA" << std::endl;
			std::string s = "";
			std::cin >> s;
			modeJeu = std::stoi(s);
			if (modeJeu <= 0 || modeJeu > NB_MODEJEU) {
				modeJeu = 0;
			}
		}
		catch (std::exception const & e)
		{
			modeJeu = 0;
		}
	}
	while (nAlgo == 0) {
		try {
			std::cout << "Choisissez votre algorithme de resolution ";
			for (int i = 1; i < NB_ALGO; i++) {
				std::cout << i << "." << ALGOS[i-1];
			}
			std::string s = "";
			std::cin >> s;
			nAlgo = std::stoi(s);
			if (nAlgo <= 0 || nAlgo > NB_ALGO) {
				nAlgo = 0;
			}
		}
		catch (std::exception const & e)
		{
			nAlgo = 0;
		}
	}
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
	if (modeJeu == 1) {
		Human player = Human(board, endBoard);
		player.play();
	}
	else {
		Algorithm algo;
		switch (nAlgo) {
		case 1: algo = ParcoursEnLargeur(board, endBoard);
		//case 2: algo = Algorithm();
		//case 3: algo = Algorithm();
		default: break;
		}
		IA player = IA(board, endBoard, algo);
		player.play();
	}
	char x;
	std::cout << "Entrez quelque chose pour fermer : ";
	std::cin >> x;
	return 0;

}


