#pragma once
#include "Player.h"
#include "Board.h"

class Human : public Player
{
public:
	Human(Board*, unsigned long);
	~Human();
	void play();

private:
	int askAction(int);
};

