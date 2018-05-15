#pragma once
#include "Board.h"
#include <list>
#include <iostream>
#include <ctime>

class Player
{
public:
	Player(Board *);
	~Player();
	virtual void play();
	void printListOfSteps(std::list<Step>);
	void startTimer();
	double getTimer();

protected:
	Board * board;
	std::clock_t timer;
};

