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
	case 2: return createBoard2();
	case 3: return createBoard3();
	case 4: return createBoard4();
	case 5: return createBoard5();
	case 6: return createBoard6();
	case 7: return createBoard7();
	case 8: return createBoard8();
	case 9: return createBoard9();
	case 10: return createBoard10();
	case 11: return createBoard11();
	case 12: return createBoard12();
	case 13: return createBoard13();
	case 14: return createBoard14();
	case 15: return createBoard15();
	case 16: return createBoard16();
	case 17: return createBoard17();
	case 18: return createBoard18();
	case 19: return createBoard19();
	case 20: return createBoard20();
	case 21: return createBoard21();
	case 22: return createBoard22();
	case 23: return createBoard23();
	case 24: return createBoard24();
	case 25: return createBoard25();
	case 26: return createBoard26();
	case 27: return createBoard27();
	case 28: return createBoard28();
	case 29: return createBoard29();
	case 30: return createBoard30();
	case 40: return createBoard40();
	case 50: return createBoard50();
	case 60: return createBoard60();
	default: return NULL;
	}
}

Board* BoardFactory::createBoard1() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1); 
	board[0][1] = SeaPart(4); 
	board[0][2] = SeaPart(2); 
	board[1][0] = SeaPart(1); 
	board[1][1] = SeaPart(5); 
	board[1][2] = SeaPart(4); 
	board[2][0] = SeaPart(1); 
	board[2][1] = SeaPart(0); 
	board[2][2] = SeaPart(2); 

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard2() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5); 
	board[0][1] = SeaPart(4); 
	board[0][2] = SeaPart(5); 
	board[1][0] = SeaPart(0); 
	board[1][1] = SeaPart(2); 
	board[1][2] = SeaPart(3); 
	board[2][0] = SeaPart(0); 
	board[2][1] = SeaPart(3); 
	board[2][2] = SeaPart(3); 

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2, 1), Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->initBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard3() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5); 
	board[0][1] = SeaPart(2); 
	board[0][2] = SeaPart(5); 
	board[1][0] = SeaPart(3); 
	board[1][1] = SeaPart(2); 
	board[1][2] = SeaPart(3); 
	board[2][0] = SeaPart(3); 
	board[2][1] = SeaPart(5); 
	board[2][2] = SeaPart(3); 
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0, 1), Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard4() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5); 
	board[0][1] = SeaPart(5); 
	board[0][2] = SeaPart(1); 
	board[1][0] = SeaPart(0); 
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(1); 
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0); 
	board[2][2] = SeaPart(5); 
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard5() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5); 
	board[0][1] = SeaPart(2); 
	board[0][2] = SeaPart(2); 
	board[1][0] = SeaPart(3);
	board[1][1] = SeaPart(2);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(3); 
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(3);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0,1), Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 1);
	return b;
}

Board* BoardFactory::createBoard6() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(3);
	board[1][0] = SeaPart(4);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::GREEN),
					  Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0, 1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard7() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(4);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
					Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1, 0), Boat::Orientation::BOT, Boat::Color::BLUE),
					Boat(b->getSeaPart(1,0), Boat::Orientation::TOP, b->getSeaPart(2, 0), Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard8() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(3);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
					Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2, 1), Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard9() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(0);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(5);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(3);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,2), Boat::Orientation::RIGHT, Boat::Color::RED),
					Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW),
					Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard10() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4); 
	board[0][1] = SeaPart(2); 
	board[0][2] = SeaPart(5); 
	board[1][0] = SeaPart(0); 
	board[1][1] = SeaPart(2); 
	board[1][2] = SeaPart(3); 
	board[2][0] = SeaPart(0); 
	board[2][1] = SeaPart(0); 
	board[2][2] = SeaPart(4); 
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1, 0), Boat::Orientation::BOT, Boat::Color::GREEN),
					  Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard11() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
					Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1, 1), Boat::Orientation::BOT, Boat::Color::GREEN),
					Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2, 1), Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard12() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1, 2), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2, 2), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard13() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(1,0), Boat::Orientation::TOP, b->getSeaPart(2,0), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2, 1), Boat::Orientation::BOT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2, 1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard14() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
		Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1, 1), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,1), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard15() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1, 2), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard16() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(4);
	board[1][0] = SeaPart(3);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(0,2), Boat::Orientation::TOP, b->getSeaPart(1, 2), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard17() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1, 0), Boat::Orientation::BOT, Boat::Color::RED),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard18() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(5);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,2), Boat::Orientation::RIGHT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2, 2), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard19() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(3);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(5);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2, 1), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard20() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4); 
	board[0][1] = SeaPart(2); 
	board[0][2] = SeaPart(2); 
	board[1][0] = SeaPart(1); 
	board[1][1] = SeaPart(4); 
	board[1][2] = SeaPart(3); 
	board[2][0] = SeaPart(1); 
	board[2][1] = SeaPart(0); 
	board[2][2] = SeaPart(4); 	
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2,1), Boat::Orientation::BOT, Boat::Color::GREEN),
					Boat(b->getSeaPart(2,2), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 2);
	return b;

}

Board* BoardFactory::createBoard21() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2,1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard22() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(1);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2,2), Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,0), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard23() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(1);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(1);
	board[2][2] = SeaPart(4);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1,1), Boat::Orientation::BOT, Boat::Color::RED),
		Boat(b->getSeaPart(2,2), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard24() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1,0), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard25() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,0), Boat::Orientation::TOP, b->getSeaPart(2,0), Boat::Orientation::BOT, Boat::Color::RED),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::GREEN) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard26() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(3);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2,2), Boat::Orientation::BOT, Boat::Color::GREEN) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard27() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(4);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(2);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1,2), Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard28() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(2);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(2);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board); //A finir
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1,2), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1,2), Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard30() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4); 
	board[0][1] = SeaPart(5); 
	board[0][2] = SeaPart(5); 
	board[1][0] = SeaPart(0); 
	board[1][1] = SeaPart(0); 
	board[1][2] = SeaPart(0); 
	board[2][0] = SeaPart(3); 
	board[2][1] = SeaPart(3); 
	board[2][2] = SeaPart(3); 
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
					Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1, 0), Boat::Orientation::BOT, Boat::Color::GREEN),
					Boat(b->getSeaPart(2, 0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard40() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(2);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
					Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0, 1), Boat::Orientation::RIGHT, Boat::Color::YELLOW),
					Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED),
					Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::GREEN) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard50() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(4);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(2);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
					Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE),
					Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2,2), Boat::Orientation::BOT, Boat::Color::GREEN),
					Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT,NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW)};
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard60() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);
	
	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
					Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW),
					Boat(b->getSeaPart(1, 0), Boat::Orientation::LEFT, b->getSeaPart(1, 1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}
