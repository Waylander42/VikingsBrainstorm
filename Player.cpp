#include "stdafx.h"
#include "Player.h"


Player::Player(Board* _board, unsigned long _endBoard):board(_board),endBoard(_endBoard)
{
}


Player::~Player()
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

unsigned long Player::getEndBoard() {
	return endBoard;
}

void Player::startTimer() {
	timer = clock();
}

void Player::printTimer() {
	double time = ((double)clock() - timer);
	int seconde = time / 1000;
	int miliSeconde = time - seconde * 1000;
	std::cout << seconde << "," << miliSeconde << " secondes";
}