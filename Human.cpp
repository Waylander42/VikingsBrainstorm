﻿#include "stdafx.h"
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
	}

}
