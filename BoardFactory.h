#pragma once
#include "Board.h"
#include "SeaPart.h"

class BoardFactory
{
public:
	BoardFactory();
	~BoardFactory();

	static Board* createBoard(int);

	static Board* createBoard1();
	static Board* createBoard10();
	static Board* createBoard20();
	static Board* createBoard30();
	static Board* createBoard40();
	static Board* createBoard50();
	static Board* createBoard60();

};

