#include "stdafx.h"
#include "Node.h"


Node::Node(Board* _board, Step _step, Node* _father, int _depth):board(Board(*_board)), step(new Step(_step)), father(_father), depth(_depth)
{
}

Node::Node(Board* _board): board(Board(*_board)), step(NULL), father(NULL), depth(0)
{
}


Node::~Node()
{
	if (step != NULL) {
		delete step;
	}
}

Board* Node::getBoard() {
	return &board;
}

int Node::getDepth() {
	return depth;
}

std::list<Step*> Node::getStepsFromRacine() {
	if (depth == 0) {
		std::list<Step*> steps;
		steps.push_back(NULL);
		return steps;
	}
	std::list<Step*> steps = father->getStepsFromRacine();
	steps.push_back(new Step(*step));
	return steps;
}
