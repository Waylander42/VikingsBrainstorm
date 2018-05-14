#pragma once
#include "Player.h"
#include "Board.h"

class Human : public Player
{
public:
	Human(Board*);
	~Human();
	void play();
};

