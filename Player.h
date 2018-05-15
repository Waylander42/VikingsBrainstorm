#pragma once
#include "Board.h"
#include <list>
#include <iostream>
#include <ctime>

class Player
{
public:
	Player(Board *, unsigned int);
	~Player();
	virtual void play();
	void printListOfSteps(std::list<Step>);
	unsigned int getEndBoard();
	void startTimer();
	void printTimer();

protected:
	Board * board;
	unsigned int endBoard;
	std::clock_t timer;
};

