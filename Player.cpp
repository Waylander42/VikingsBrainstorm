#include "stdafx.h"
#include "Player.h"


Player::Player(Board* _board, unsigned int _endBoard):board(_board),endBoard(_endBoard)
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

unsigned int Player::getEndBoard() {
	return endBoard;
}

void Player::startTimer() {
	timer = clock();
}

#ifdef _WIN32
void Player::printTimer() {
	finalTime = ((double)clock() - timer);
	int seconde = finalTime / 1000;
	int miliSeconde = finalTime - seconde * 1000;
	std::cout << seconde << "," << miliSeconde << " secondes";
}
#elif __linux__
void Player::printTimer() {
	finalTime = ((double)clock() - timer);
	int seconde = finalTime / 1000000;
	int miliSeconde = finalTime - seconde * 1000000;
	std::cout << seconde << "," << miliSeconde << " secondes";
}
#endif

double Player::getFinalTime() {
	return finalTime;
}