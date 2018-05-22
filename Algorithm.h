#pragma once
#include "Board.h"
#include "Step.h"
#include <list>

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
};

