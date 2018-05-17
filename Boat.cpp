#include "stdafx.h"
#include "Boat.h"
#include <iostream>

Boat::Boat():orientation1(Orientation::TOP), orientation2(Orientation::BOT), part1(NULL), part2(NULL), color(Boat::Color::RED)
{
}

Boat::Boat(SeaPart* _part1, Orientation _orientation1, SeaPart* _part2, Orientation _orientation2, Color _color):
		orientation1(_orientation1), orientation2(_orientation2), part1(_part1), part2(_part2), color(_color) {
}

Boat::~Boat()
{
}

//Update l'orientation du bateau par rapport au 2 pièces
void Boat::rotate(SeaPart* _part1, Orientation _orientation1, SeaPart* _part2, Orientation _orientation2)
{
	orientation1 = _orientation1;
	orientation2 = _orientation2;
	part1 = _part1;
	part2 = _part2;
}

//Renvoie la première pièce à côté du bâteau
SeaPart * Boat::getPart1() const
{
	return part1;
}

//Renvoie la deuxième pièce à côté du bâteau
SeaPart * Boat::getPart2() const
{
	return part2;
}

//Renvoie la première orientation à côté du bâteau
Boat::Orientation Boat::getOrientation1() const{
	return orientation1;
}

//Renvoie la deuxième orientation à côté du bâteau
Boat::Orientation Boat::getOrientation2() const{
	return orientation2;
}

//Crée une identité pour le bateau
void Boat::setIdentity(int _identity) {
	if (color == Color::RED) {
		identity = _identity;
	}
	if (color == Color::GREEN) {
		identity = _identity * 6;
	}
	if (color == Color::BLUE) {
		identity = _identity * 36;
	}
	if (color == Color::YELLOW) {
		identity = _identity * 216;
	}
}

//Renvoie l'identité du bateau
int Boat::getIdentity() const{
	return identity;
}

//Renvoie la couleur du bateau
char Boat::getColorChar() const{
	switch (color)
	{
	case Boat::Color::RED: return 'R';
		break;
	case Boat::Color::GREEN: return 'G';
		break;
	case Boat::Color::BLUE: return 'B';
		break;
	case Boat::Color::YELLOW: return 'Y';
		break;
	}
	return 'X';
}

//Renvoie la couleur du bateau
Boat::Color Boat::getColor() const {
	return color;
}

//Surcharge opérateur =
Boat &Boat::operator=(const Boat &source)
{
	orientation1 = source.orientation1;
	part1 = source.part1;
	orientation2 = source.orientation2;
	part2 = source.part2;
	color = source.color;
	identity = source.identity;
	return *this;
}
