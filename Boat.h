﻿#pragma once
#include "SeaPart.h"

class Boat
{
public:
	enum Orientation { TOP, BOT, RIGHT, LEFT }; //enum ayant en valeurs TOP, BOT, RIGHT, LEFT 
	enum Color { RED, GREEN, BLUE, YELLOW }; //enum ayant en valeurs RED, GREEN, BLUE, YELLOW

	Boat();
	Boat(SeaPart*, Orientation, SeaPart*, Orientation, Color);
	~Boat();
			
	void rotate(SeaPart*, Orientation, SeaPart*, Orientation); //Update l'orientation du bateau par rapport au 2 pièces

	SeaPart* getPart1() const; //Renvoie la première pièce à côté du bâteau
	SeaPart* getPart2() const; //Renvoie la deuxième pièce à côté du bâteau

	Orientation getOrientation1() const; //Renvoie la première orientation à côté du bâteau
	Orientation getOrientation2() const; //Renvoie la deuxième orientation à côté du bâteau

	void setIdentity(int); //Crée une identité pour le bateau
	int getIdentity() const; //Renvoie l'identité du bateau

	char getColorChar() const; //Renvoie la couleur du bateau
	Boat::Color getColor() const;

	Boat &operator=(const Boat &); //Surcharge de l'opérateur = 

private:
	Orientation orientation1;
	Orientation orientation2;

	SeaPart* part1;
	SeaPart* part2;

	Color color;

	int identity;
};

