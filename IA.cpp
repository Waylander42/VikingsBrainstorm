#include "stdafx.h"
#include "IA.h"
#include <list>

IA::IA(Board* board, unsigned int endBoard, Algorithm* algo):Player(board, endBoard), algorithm(algo)
{
}

IA::~IA()
{
}

void IA::play() {
	startTimer();
	algorithm->launch();
	std::cout << "resolution en ";
	printTimer();
	std::cout << std::endl;
	std::list<Step*> result = algorithm->getResult(); //regarder pour step*
	while (result.empty() == false) {
		result.front()->print();
		board->doStep(*result.front());
		board->print(endBoard);
		result.pop_front();
	}
	board->print(endBoard);
	
}