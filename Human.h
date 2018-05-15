#pragma once
#include "Player.h"
#include "Board.h"

class Human : public Player
{
public:
	Human(Board*, unsigned int);
	~Human();
	void play();

private:
	int askAction(int);
};

