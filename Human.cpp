#include "stdafx.h"
#include "Human.h"
#include <list>


Human::Human(Board* board):Player(board)
{
}


Human::~Human()
{
}

void Human::play() {
	while (true) {
		board->print();
		std::list<Step> steps = board->getListOfStep();
		printListOfSteps(steps);
		std::cout << "Choisissez une action : ";
		int action = 0;
		std::cin >> action;
		std::cout << std::endl << std::endl;
		std::list<Step>::const_iterator it = steps.begin();
		std::advance(it, action - 1);
		board->doStep(*it);
	}
}
