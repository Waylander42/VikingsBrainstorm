#include "stdafx.h"
#include "Human.h"
#include <list>
#include <string>


Human::Human(Board* board):Player(board)
{
}


Human::~Human()
{
}

void Human::play() {
	startTimer();
	while (true) {
		board->print();
		std::list<Step> steps = board->getListOfStep();
		printListOfSteps(steps);
		int action = askAction(steps.size());
		std::cout << std::endl;
		std::list<Step>::const_iterator it = steps.begin();
		std::advance(it, action - 1);
		board->doStep(*it);
	}
	std::cout << "resolution en " << getTimer() << "secondes" << std::endl;
}

int Human::askAction(int size) {
	int action = 0;
	while (action == 0)
	{
		try {
			std::cout << "Choisissez une action : ";
			std::string s = "";
			std::cin >> s;
			action = std::stoi(s);
			if (action > size || action < 0) {
				action = 0;
			}
		}
		catch (std::exception const & e)
		{
			action = 0;
		}
	}
	return action;
}
