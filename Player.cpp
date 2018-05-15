#include "stdafx.h"
#include "Player.h"


Player::Player(Board* _board):board(_board)
{
}


Player::~Player()
{
}

void Player::play()
{
}

void Player::printListOfSteps(std::list<Step> steps) {
	int count = 1;
	for (std::list<Step>::const_iterator it = steps.begin(); it != steps.end(); ++it) {
		std::cout << count << " : ";
		it->print();
		count++;
	}
}

void Player::startTimer() {
	timer = time(NULL);
}

double Player::getTimer() {
	return ((double)clock() - timer);
}