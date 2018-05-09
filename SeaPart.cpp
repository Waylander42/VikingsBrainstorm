#include "stdafx.h"
#include "SeaPart.h"

SeaPart::SeaPart(int _top, int _right, int _bot, int _left):top(_top), bot(_bot), left(_left), right(_right)
{
}

SeaPart::SeaPart() :SeaPart(0, 0, 0, 0)
{
}

SeaPart::~SeaPart()
{
}

int SeaPart::getTop() {
	return top;
}

int SeaPart::getBot() {
	return bot;
}

int SeaPart::getLeft() {
	return left;
}

int SeaPart::getRight() {
	return right;
}

void SeaPart::rotateLeft() {
	top, left, bot, right = left, bot, right, top; 
}

void SeaPart::rotateRight() {
	top, right, bot, left = right, bot, left, top;
}

int SeaPart::getIdentity() {
	if (left == 1 && bot == 1) {
		return 0;
	}
	else if (right == 1 && bot == 1) {
		return 1;
	}
	else if (top == 1 && left == 1) {
		return 2;
	}
	else if (top == 1 && left == 1) {
		return 3;
	}
	else if (left == 1 && right == 1) {
		return 4;
	}
	return 5;
}