#pragma once
#include "SeaPart.h"
#include "Boat.h"
#include "Step.h"
#include <list>

class Board
{
public:
	Board();
	~Board();
	Board(SeaPart[3][3]);
	Board(Board const&);

	unsigned int getBoatsLocation(); //retourn un entier qui décrit de façon unique la position des bateaux
	unsigned int setIdentity();
	unsigned int getIdentity();
	
	SeaPart* getSeaPart(int, int);
	SeaPart* getSeapartWithId(int);

	bool canRotate(int, int);
	bool rotateLeft(int, int);
	bool rotateRight(int, int);
	bool rotateHalf(int, int);

	std::list<Step> getListOfStep();
	bool doStep(Step);

	//fonctions d'initialisation à appeler après la création d'un board
	void initBoats(Boat[4], int);
	void initSeaPart();

	void print(unsigned int);

private:
	void setBoatsIdentity();
	unsigned int getLocation(int, int); //retourne l'emplacement du bateau. L'emplacement du bateau est un entier entre 0 et 23
	unsigned int getBoatLocation(int); //retourne un entier qui décrit de façon unique la position d'un bateau en fonction de sa couleur
	void drawBoatArrival(int,char*, char);

	SeaPart board[3][3];
	Boat boats[4];   //array of boats
	int nbBoats;
	unsigned int identity;
};

