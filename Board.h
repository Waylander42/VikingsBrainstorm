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

	unsigned int getBoatsLocation();
	unsigned int getIdentity();
	
	SeaPart* getSeaPart(int, int);

	bool canRotate(int, int);
	bool rotateLeft(int, int);
	bool rotateRight(int, int);
	bool rotateHalf(int, int);

	std::list<Step> getListOfStep();
	bool doStep(Step);

	void initBoats(Boat[4], int);
	void initSeaPart();

	void print();

private:
	void setBoatsIdentity();
	unsigned int getLocation(int, int);
	unsigned int getBoatLocation(int);

	SeaPart board[3][3];
	Boat boats[4];   //array of boats
	int nbBoats;
};

