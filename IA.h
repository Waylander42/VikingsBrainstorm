#pragma once
#include "Player.h"
#include "Board.h"
#include "Algorithm.h"


class IA : public Player
{
public:
	IA(Board*, unsigned long, Algorithm*);
	~IA();
	
	void play();

private:
	Algorithm* algorithm;
};



