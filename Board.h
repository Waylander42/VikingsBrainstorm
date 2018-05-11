#pragma once
#include "SeaPart.h";
#include "Boat.h";

class Board
{
public:
	Board();
	~Board();
	Board(SeaPart[3][3], Boat*, int);
	int getIdentity();
	bool canRotate(int, int);
	bool rotateLeft(int, int);
	bool rotateRight(int, int);
	void print();

private:
	void setBoatsIdentity();

	SeaPart board[3][3];
	Boat* boats;   //array of boats
	int nbBoats;
};

