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
	case 31: return createBoard31();
	case 32: return createBoard32();
	case 33: return createBoard33();
	case 34: return createBoard34();
	case 35: return createBoard35();
	case 36: return createBoard36();
	case 37: return createBoard37();
	case 38: return createBoard38();
	case 39: return createBoard39();
	case 40: return createBoard40();
	case 41: return createBoard41();
	case 42: return createBoard42();
	case 43: return createBoard43();
	case 44: return createBoard44();
	case 45: return createBoard45();
	case 46: return createBoard46();
	case 47: return createBoard47();
	case 48: return createBoard48();
	case 49: return createBoard49();
	case 50: return createBoard50();
	case 51: return createBoard51();
	case 52: return createBoard52();
	case 53: return createBoard53();
	case 54: return createBoard54();
	case 55: return createBoard55();
	case 56: return createBoard56();
	case 57: return createBoard57();
	case 58: return createBoard58();
	case 59: return createBoard59();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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
	b->setIdentity();
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

	Board* b = new Board(board); 
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,1), Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(2,1), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard29() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2,1), Boat::Orientation::BOT, Boat::Color::GREEN) };
	b->initBoats(boats, 2);
	b->setIdentity();
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
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard31() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(4);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::LEFT, b->getSeaPart(0, 1), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard32() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(0);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,1), Boat::Orientation::LEFT, b->getSeaPart(2, 2), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard33() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(3);
	board[1][0] = SeaPart(4);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(2);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
		Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1, 1), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED),
		Boat(b->getSeaPart(2,0), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::GREEN) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard34() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(1);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1, 2), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard35() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(3);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(4);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1, 1), Boat::Orientation::BOT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2,2), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,0), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard36() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(1);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard37() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard38() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(2);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(5);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2,1), Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard39() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(5);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
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
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard41() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(5);
	board[1][2] = SeaPart(0);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard42() { //top right bot left
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
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2,2), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard43() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(3);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard44() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(0);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(1);
	board[2][2] = SeaPart(4);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,2), Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard45() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(3);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(4);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::TOP, b->getSeaPart(1,2), Boat::Orientation::BOT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,0), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::BLUE) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard46() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(5);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2,1), Boat::Orientation::BOT, Boat::Color::BLUE) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard47() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(5);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 3);
	return b;
}

Board* BoardFactory::createBoard48() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(2);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,2), Boat::Orientation::RIGHT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	return b;
}

Board* BoardFactory::createBoard49() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(4);
	board[1][0] = SeaPart(2);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,2), Boat::Orientation::TOP, b->getSeaPart(1,2), Boat::Orientation::BOT, Boat::Color::RED),
		Boat(b->getSeaPart(1,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE) };
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
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard51() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(1);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(3);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(4);
	board[2][0] = SeaPart(1);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,1), Boat::Orientation::TOP, b->getSeaPart(1,1), Boat::Orientation::BOT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,2), Boat::Orientation::TOP, b->getSeaPart(2,2), Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard52() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(5);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(1,0), Boat::Orientation::LEFT, b->getSeaPart(1,1), Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::RED),
		Boat(b->getSeaPart(2,2), Boat::Orientation::LEFT,NULL, Boat::Orientation::RIGHT, Boat::Color::BLUE) };
	b->initBoats(boats, 4);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard53() { //top right bot left
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(1);
	board[0][2] = SeaPart(1);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2,1), Boat::Orientation::RIGHT, Boat::Color::RED) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard54() { //top right bot left
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
		Boat(b->getSeaPart(0,2), Boat::Orientation::TOP, b->getSeaPart(1,2), Boat::Orientation::BOT, Boat::Color::GREEN) };
	b->initBoats(boats, 2);
	return b;
}

Board* BoardFactory::createBoard55() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(0);
	board[0][1] = SeaPart(4);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(1);
	board[1][2] = SeaPart(5);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(5);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::RED),
		Boat(b->getSeaPart(0,1), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,0), Boat::Orientation::LEFT, b->getSeaPart(2,1), Boat::Orientation::RIGHT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard56() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(5);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(1);
	board[1][0] = SeaPart(3);
	board[1][1] = SeaPart(3);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(4);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,2), Boat::Orientation::LEFT, NULL, Boat::Orientation::RIGHT, Boat::Color::RED),
		Boat(b->getSeaPart(0,2), Boat::Orientation::TOP, b->getSeaPart(1,2), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,1), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::GREEN) };
	b->initBoats(boats, 3);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard57() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(2);
	board[0][2] = SeaPart(3);
	board[1][0] = SeaPart(1);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(4);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::YELLOW),
		Boat(b->getSeaPart(0,2), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2,1), Boat::Orientation::BOT, Boat::Color::GREEN),
		Boat(b->getSeaPart(2,2), Boat::Orientation::TOP, NULL, Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 4);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard58() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(2);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(4);
	board[1][2] = SeaPart(2);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,1), Boat::Orientation::LEFT, b->getSeaPart(0,2), Boat::Orientation::RIGHT, Boat::Color::YELLOW),
		Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1,0), Boat::Orientation::BOT, Boat::Color::BLUE),
		Boat(b->getSeaPart(1,1), Boat::Orientation::TOP, b->getSeaPart(2,1), Boat::Orientation::BOT, Boat::Color::RED) };
	b->initBoats(boats, 4);
	b->setIdentity();
	return b;
}

Board* BoardFactory::createBoard59() { //top right bot left 
	SeaPart board[3][3];
	board[0][0] = SeaPart(4);
	board[0][1] = SeaPart(5);
	board[0][2] = SeaPart(4);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(3);
	board[2][0] = SeaPart(3);
	board[2][1] = SeaPart(3);
	board[2][2] = SeaPart(3);

	Board* b = new Board(board);
	b->initSeaPart();
	Boat boats[4] = { Boat(b->getSeaPart(0,0), Boat::Orientation::BOT, NULL, Boat::Orientation::TOP, Boat::Color::GREEN),
		Boat(b->getSeaPart(0,0), Boat::Orientation::TOP, b->getSeaPart(1,0), Boat::Orientation::BOT, Boat::Color::RED),
		Boat(b->getSeaPart(1,1), Boat::Orientation::LEFT, b->getSeaPart(1,2), Boat::Orientation::RIGHT, Boat::Color::BLUE),
		Boat(b->getSeaPart(2,0), Boat::Orientation::RIGHT, NULL, Boat::Orientation::LEFT, Boat::Color::YELLOW) };
	b->initBoats(boats, 4);
	b->setIdentity();
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
	b->setIdentity();
	return b;
}
