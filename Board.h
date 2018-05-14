#pragma once
#include "SeaPart.h"
#include "Boat.h"
#include "Step.h"
#include <list>

class Board
{
public:
	Board();
	~Board();
	Board(SeaPart[3][3]);
	Board(Board const&);
	unsigned int getIdentity();
	void setBoats(Boat[4], int);
	SeaPart* getSeaPart(int, int);
	bool canRotate(int, int);
	bool rotateLeft(int, int);
	bool rotateRight(int, int);
	void print();
	std::list<Step> getListOfStep();

private:
	void setBoatsIdentity();

	SeaPart board[3][3];
	Boat boats[4];   //array of boats
	int nbBoats;
};

