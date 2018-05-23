#pragma once
#include "Board.h"
#include "Step.h"
#include <list>
#include "Node.h"

class Algorithm
{
public:
	Algorithm();
	Algorithm(Board*, unsigned int);
	~Algorithm();
	virtual void launch() {};
	std::list<Step*> getResult();

protected:
	Board * board;
	unsigned int endBoard;
	std::list<Step*> result;
	std::list<Node*> nodeAdress;
};

