#include "stdafx.h"
#include "Boat.h"

Boat::Boat()
{
	orientation1 = Orientation::TOP;
	orientation1 = Orientation::BOT;
	part1 = NULL;
	part2 = NULL;
}

Boat::Boat(SeaPart* _part1, Orientation _orientation1, SeaPart* _part2, Orientation _orientation2) {
	orientation1 = _orientation1;
	orientation2 = _orientation2;
	part1 = _part1;
	part2 = _part2;
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
	if (color = Color::RED) {
		identity = _identity + 0;
	}
	if (color = Color::GREEN) {
		identity = _identity + 6;
	}
	if (color = Color::BLUE) {
		identity = _identity + 12;
	}
	if (color = Color::YELLOW) {
		identity = _identity + 18;
	}
}

int Boat::getIdentity() {
	return identity;
}
