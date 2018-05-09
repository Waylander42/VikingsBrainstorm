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
