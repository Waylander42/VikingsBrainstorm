#include "stdafx.h"
#include "Step.h"
#include <iostream>


Step::Step():Step(0, 0, HALF)
{
}

Step::Step(int _x, int _y, Rotation _rotation):x(_x), y(_y), rotation(_rotation)
{
}


Step::~Step()
{
}

int Step::getX() {
	return x;
}

int Step::getY() {
	return y;
}

Step::Rotation Step::getRotation() {
	return rotation;
}

void Step::print() const{
	std::cout << "Tourner la Piece (" << x << "," << y << ") ";
	switch (rotation) {
	case LEFT: std::cout << "vers la gauche" << std::endl;
		break;
	case RIGHT : std::cout << "vers la droite" << std::endl;
		break;
	case HALF : std::cout << "d'un demi-tour" << std::endl;
		break;
	}
}
