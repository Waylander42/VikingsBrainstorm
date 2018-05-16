#pragma once
#include "Board.h"
#include "Step.h"
#include <list>

class Node
{
public:
	Node(Board*);
	Node(Board*, Step*, Node*, int);
	~Node();
	std::list<Step*> getStepsFromRacine();
	Board* getBoard();
	int getDepth();

private:
	Board board;
	Step* step;
	Node* father;
	int depth;
};

