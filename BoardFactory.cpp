#include "stdafx.h"
#include "BoardFactory.h"



BoardFactory::BoardFactory()
{
}


BoardFactory::~BoardFactory()
{
}

Board* BoardFactory::createBoard(int number) {
	switch (number) {
	case 1: return createBoard1();
	case 10: return createBoard10();
	case 20: return createBoard20();
	case 30: return createBoard30();
	case 40: return createBoard40();
	case 50: return createBoard50();
	case 60: return createBoard60();
	}
}

Board* BoardFactory::createBoard1() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 0, 1); //3
	board[0][1] = SeaPart(0, 1, 0, 1); //5
	board[0][2] = SeaPart(1, 1, 0, 0); //4
	board[1][0] = SeaPart(1, 0, 0, 1); //3
	board[1][1] = SeaPart(1, 0, 1, 0); //6
	board[1][2] = SeaPart(0, 1, 0, 1); //5
	board[2][0] = SeaPart(1, 0, 0, 1); //3
	board[2][1] = SeaPart(0, 0, 1, 1); //1
	board[2][2] = SeaPart(1, 1, 0, 0); //4
	return new Board(board);
}

Board* BoardFactory::createBoard10() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0, 1, 0, 1); //5
	board[0][1] = SeaPart(1, 1, 0, 0); //4
	board[0][2] = SeaPart(1, 0, 1, 0); //6
	board[1][0] = SeaPart(0, 0, 1, 1); //1
	board[1][1] = SeaPart(1,1,0,0); //4
	board[1][2] = SeaPart(0,1,1,0); //2
	board[2][0] = SeaPart(0,0,1,1); //1
	board[2][1] = SeaPart(0,0,1,1); //1
	board[2][2] = SeaPart(0,1,0,1); //5
	return new Board(board);

}

Board* BoardFactory::createBoard20() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0,1,0,1); //5
	board[0][1] = SeaPart(1,1,0,0); //4
	board[0][2] = SeaPart(1,1,0,0); //4
	board[1][0] = SeaPart(1,0,0,1); //3
	board[1][1] = SeaPart(0,1,0,1); //5
	board[1][2] = SeaPart(0,1,1,0); //2
	board[2][0] = SeaPart(1,0,0,1); //3
	board[2][1] = SeaPart(0,0,1,1); //1
	board[2][2] = SeaPart(0,1,0,1); //5	
	return new Board(board);

}

Board* BoardFactory::createBoard30() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0,1,0,1); //5
	board[0][1] = SeaPart(1,0,1,0); //6
	board[0][2] = SeaPart(1,0,1,0); //6
	board[1][0] = SeaPart(0,0,1,1); //1
	board[1][1] = SeaPart(0,0,1,1); //1
	board[1][2] = SeaPart(0,0,1,1); //1
	board[2][0] = SeaPart(0, 1, 1, 0); //2
	board[2][1] = SeaPart(0, 1, 1, 0); //2
	board[2][2] = SeaPart(0, 1, 1, 0); //2
	return new Board(board);
}

Board* BoardFactory::createBoard40() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(1,0,1,0);
	board[0][1] = SeaPart(1,1,0,0);
	board[0][2] = SeaPart(1,0,1,0);
	board[1][0] = SeaPart(0,0,1,1);
	board[1][1] = SeaPart(1,1,0,0);
	board[1][2] = SeaPart(0,1,1,0);
	board[2][0] = SeaPart(0,1,1,0);
	board[2][1] = SeaPart(1,0,1,0);
	board[2][2] = SeaPart(0,1,1,0);
	return new Board(board);
}

Board* BoardFactory::createBoard50() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(1,0,0,1);
	board[0][1] = SeaPart(1,0,0,1);
	board[0][2] = SeaPart(0,0,1,1);
	board[1][0] = SeaPart(0,1,0,1);
	board[1][1] = SeaPart(1,0,1,0);
	board[1][2] = SeaPart(0,1,0,1);
	board[2][0] = SeaPart(1,1,0,0);
	board[2][1] = SeaPart(0,1,1,0);
	board[2][2] = SeaPart(0,1,1,0);
	return new Board(board);
}

Board* BoardFactory::createBoard60() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(1,0,1,0);
	board[0][1] = SeaPart(1,0,0,1);
	board[0][2] = SeaPart(0,0,1,1);
	board[1][0] = SeaPart(0,0,1,1);
	board[1][1] = SeaPart(1,0,1,0);
	board[1][2] = SeaPart(0,1,0,1);
	board[2][0] = SeaPart(0,0,1,1);
	board[2][1] = SeaPart(0,0,1,1);
	board[2][2] = SeaPart(0,0,1,1);
	return new Board(board);
}
