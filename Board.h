#pragma once
#include "SeaPart.h";

class Board
{
public:
	Board();
	~Board();
	Board(SeaPart[3][3]);
	void print();

private:
	SeaPart board[3][3];
};

