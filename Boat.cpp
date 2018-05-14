#include "stdafx.h"
#include "Boat.h"
#include <iostream>

Boat::Boat():orientation1(Orientation::TOP), orientation2(Orientation::BOT), part1(NULL), part2(NULL), color(Boat::Color::RED)
{
}

Boat::Boat(SeaPart* _part1, Orientation _orientation1, SeaPart* _part2, Orientation _orientation2, Color _color): orientation1(_orientation1), orientation2(_orientation2), part1(_part1), part2(_part2), color(_color) {
}

Boat::Boat(Boat const& boat) : orientation1(boat.orientation1), orientation2(boat.orientation2), part1(boat.part1), part2(boat.part2), color(boat.color), identity(boat.identity) {
}

Boat::~Boat()
{
}

Boat::Orientation Boat::rotateRight(Orientation orientation)
{
	switch (orientation) {
		case Orientation::TOP : return Orientation::RIGHT;
			break;
		case Orientation::RIGHT : return Orientation::BOT;
			break;
		case Orientation::BOT : return Orientation::LEFT;
			break;
		case Orientation::LEFT : return Orientation::TOP;
			break;
	}
}

Boat::Orientation Boat::rotateLeft(Orientation orientation)
{
	switch (orientation) {
	case Orientation::TOP: return Orientation::LEFT;
		break;
	case Orientation::LEFT : return Orientation::BOT;
		break;
	case Orientation::BOT: return Orientation::RIGHT;
		break;
	case Orientation::RIGHT : return Orientation::TOP;
		break;
	}
}

void Boat::rotate(SeaPart* _part1, Orientation _orientation1, SeaPart* _part2, Orientation _orientation2)
{
	orientation1 = _orientation1;
	orientation2 = _orientation2;
	part1 = _part1;
	part2 = _part2;
}

SeaPart * Boat::getPart1()
{
	return part1;
}

SeaPart * Boat::getPart2()
{
	return part2;
}

Boat::Orientation Boat::getOrientation1() {
	return orientation1;
}

Boat::Orientation Boat::getOrientation2() {
	return orientation2;
}

void Boat::setIdentity(int _identity) {
	if (color == Color::RED) {
		identity = _identity + 0;
	}
	if (color == Color::GREEN) {
		identity = _identity + 6;
	}
	if (color == Color::BLUE) {
		identity = _identity + 12;
	}
	if (color == Color::YELLOW) {
		identity = _identity + 18;
	}
}

int Boat::getIdentity() const{
	return identity;
}

char Boat::getColor() const{
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
