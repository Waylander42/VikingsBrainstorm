#include "stdafx.h"
#include "BoardFactory.h"

#include <iostream>



BoardFactory::BoardFactory()
{
}


BoardFactory::~BoardFactory()
{
}

Board* BoardFactory::createBoard(int number) {
	switch (number) {
	case 1: return createBoard1();
	case 2: return createBoard2();/*
	case 3: return createBoard3();
	case 4: return createBoard4();
	case 5: return createBoard5();*/
	case 6: return createBoard6();/*
	case 7: return createBoard7();
	case 8: return createBoard8();
	case 9: return createBoard9();
	case 10: return createBoard10();
	case 11: return createBoard11();
	case 20: return createBoard20();
	case 30: return createBoard30();
	case 40: return createBoard40();
	case 50: return createBoard50();
	case 60: return createBoard60();*/
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

	Board* b = new Board(board);
	Boat boats[4] = { Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->setBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard2() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0); 
	board[0][1] = SeaPart(0, 1, 0, 1); 
	board[0][2] = SeaPart(1, 0, 1, 0); 
	board[1][0] = SeaPart(0, 0, 1, 1); 
	board[1][1] = SeaPart(1, 1, 0, 0); 
	board[1][2] = SeaPart(0, 1, 1, 0); 
	board[2][0] = SeaPart(0, 0, 1, 1); 
	board[2][1] = SeaPart(0, 1, 1, 0); 
	board[2][2] = SeaPart(0, 1, 1, 0); 

	Board* b = new Board(board);
	Boat boats[4] = { Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2, 1), Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->setBoats(boats, 1);
	return b;
}
/*
Board* BoardFactory::createBoard3() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0); 
	board[0][1] = SeaPart(1, 1, 0, 0); 
	board[0][2] = SeaPart(1, 0, 1, 0); 
	board[1][0] = SeaPart(0, 1, 1, 0); 
	board[1][1] = SeaPart(1, 1, 0, 0); 
	board[1][2] = SeaPart(0, 1, 1, 0); 
	board[2][0] = SeaPart(0, 1, 1, 0); 
	board[2][1] = SeaPart(1, 0, 1, 0); 
	board[2][2] = SeaPart(0, 1, 1, 0); 
	
	Boat boats[4];
	boats[0] = Boat(&board[0][0], Boat::Orientation::RIGHT, &board[0][1], Boat::Orientation::LEFT, Boat::Color::YELLOW);
	return new Board(board, boats, 1);
}

Board* BoardFactory::createBoard4() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0); 
	board[0][1] = SeaPart(1, 0, 1, 0); 
	board[0][2] = SeaPart(1, 0, 0, 1); 
	board[1][0] = SeaPart(0, 0, 1, 1); 
	board[1][1] = SeaPart(0, 0, 1, 1);
	board[1][2] = SeaPart(1, 0, 0, 1); 
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 0, 1, 1); 
	board[2][2] = SeaPart(1, 0, 1, 0); 
	
	Boat boats[4];
	boats[0] = Boat(&board[2][2], Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED);
	return new Board(board, boats, 1);
}

Board* BoardFactory::createBoard5() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0); 
	board[0][1] = SeaPart(1, 1, 0, 0); 
	board[0][2] = SeaPart(1, 1, 0, 0); 
	board[1][0] = SeaPart(0, 1, 1, 0);
	board[1][1] = SeaPart(1, 1, 0, 0);
	board[1][2] = SeaPart(1, 0, 1, 0);
	board[2][0] = SeaPart(0, 1, 1, 0); 
	board[2][1] = SeaPart(1, 0, 1, 0);
	board[2][2] = SeaPart(0, 1, 1, 0);
	
	Boat boats[4];
	boats[0] = Boat(&board[0][0], Boat::Orientation::RIGHT, &board[0][1], Boat::Orientation::LEFT, Boat::Color::BLUE);
	return new Board(board, boats, 1);
}
*/
Board* BoardFactory::createBoard6() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0);
	board[0][1] = SeaPart(1, 0, 1, 0);
	board[0][2] = SeaPart(0, 1, 1, 0);
	board[1][0] = SeaPart(0, 1, 0, 1);
	board[1][1] = SeaPart(0, 1, 1, 0);
	board[1][2] = SeaPart(0, 1, 1, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 1, 1, 0);
	board[2][2] = SeaPart(0, 1, 1, 0);
	
	Board* b = new Board(board);
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::GREEN),
					  Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0, 1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->setBoats(boats, 2);
	return b;
}
/*
Board* BoardFactory::createBoard7() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0, 1, 0, 1);
	board[0][1] = SeaPart(1, 0, 1, 0);
	board[0][2] = SeaPart(1, 1, 0, 0);
	board[1][0] = SeaPart(0, 1, 0, 1);
	board[1][1] = SeaPart(0, 1, 1, 0);
	board[1][2] = SeaPart(0, 1, 1, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 1, 1, 0);
	board[2][2] = SeaPart(0, 1, 1, 0);
	
	Boat boats[4];
	boats[0] = Boat(&board[0][0], Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED);
	boats[1] = Boat(&board[0][0], Boat::Orientation::TOP, &board[1][0], Boat::Orientation::BOT, Boat::Color::BLUE);
	boats[2] = Boat(&board[1][0], Boat::Orientation::TOP, &board[2][0], Boat::Orientation::BOT, Boat::Color::YELLOW);
	return new Board(board, boats, 3);
}

Board* BoardFactory::createBoard8() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0);
	board[0][1] = SeaPart(0, 1, 0, 1);
	board[0][2] = SeaPart(1, 1, 0, 0);
	board[1][0] = SeaPart(0, 0, 1, 1);
	board[1][1] = SeaPart(0, 1, 0, 1);
	board[1][2] = SeaPart(0, 1, 1, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 0, 1, 1);
	board[2][2] = SeaPart(0, 1, 1, 0);
	
	Boat boats[4];
	boats[0] = Boat(&board[0][1], Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE);
	boats[1] = Boat(&board[1][1], Boat::Orientation::TOP, &board[2][1], Boat::Orientation::BOT, Boat::Color::YELLOW);
	return new Board(board, boats, 2);
}

Board* BoardFactory::createBoard9() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 0, 1);
	board[0][1] = SeaPart(0, 0, 1, 1);
	board[0][2] = SeaPart(1, 1, 0, 0);
	board[1][0] = SeaPart(1, 0, 1, 0);
	board[1][1] = SeaPart(0, 1, 0, 1);
	board[1][2] = SeaPart(1, 0, 1, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 0, 1, 1);
	board[2][2] = SeaPart(0, 1, 1, 0);
	
	Boat boats[4];
	boats[0] = Boat(&board[0][1], Boat::Orientation::LEFT, &board[0][2], Boat::Orientation::RIGHT, Boat::Color::RED);
	boats[1] = Boat(&board[1][2], Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW);
	boats[2] = Boat(&board[2][1], Boat::Orientation::LEFT, &board[2][2], Boat::Orientation::RIGHT, Boat::Color::GREEN);
	return new Board(board, boats, 3);
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
	
	Boat boats[4];
	boats[0] = Boat(&board[0][0], Boat::Orientation::TOP, &board[1][0], Boat::Orientation::BOT, Boat::Color::GREEN);
	boats[1] = Boat(&board[1][0], Boat::Orientation::LEFT, &board[1][1], Boat::Orientation::RIGHT, Boat::Color::BLUE);
	return new Board(board, boats, 2);
}

Board* BoardFactory::createBoard11() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1, 0, 1, 0);
	board[0][1] = SeaPart(0, 1, 0, 1);
	board[0][2] = SeaPart(1, 1, 0, 0);
	board[1][0] = SeaPart(0, 0, 1, 1);
	board[1][1] = SeaPart(0, 1, 0, 1);
	board[1][2] = SeaPart(1, 1, 0, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 0, 1, 1);
	board[2][2] = SeaPart(0, 0, 1, 1);
	
	Boat boats[4];
	boats[0] = Boat(&board[0][1], Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW);
	boats[1] = Boat(&board[0][1], Boat::Orientation::TOP, &board[1][1], Boat::Orientation::BOT, Boat::Color::GREEN);
	boats[2] = Boat(&board[1][1], Boat::Orientation::TOP, &board[2][1], Boat::Orientation::RIGHT, Boat::Color::RED);
	return new Board(board, boats, 3);
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
*/