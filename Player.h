#pragma once
#include "Board.h"
#include <list>
#include <iostream>

class Player
{
public:
	Player(Board *);
	~Player();
	virtual void play();
	void printListOfSteps(std::list<Step>);

protected:
	Board * board;
};

