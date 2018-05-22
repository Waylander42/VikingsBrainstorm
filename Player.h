#pragma once
#include "Board.h"
#include <list>
#include <iostream>
#include <ctime>

class Player
{
public:
	Player(Board *, unsigned long);
	~Player();
	virtual void play() {};
	void printListOfSteps(std::list<Step>);
	unsigned long getEndBoard();
	void startTimer();
	void printTimer();

protected:
	Board * board;
	unsigned long endBoard;
	std::clock_t timer;
};

