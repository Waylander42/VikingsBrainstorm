#include "stdafx.h"
#include "EndBoardFactory.h"


EndBoardFactory::EndBoardFactory()
{
}


EndBoardFactory::~EndBoardFactory()
{
}

unsigned int EndBoardFactory::createEndBoard(int number) {
	switch (number) {
	case 1: return createEndBoard1();
	case 2: return createEndBoard2();
	case 3: return createEndBoard3();
	case 4: return createEndBoard4();
	case 5: return createEndBoard5();
	case 6: return createEndBoard6();
	case 7: return createEndBoard7();
	case 8: return createEndBoard8();
	case 9: return createEndBoard9();
	case 10: return createEndBoard10();
	case 11: return createEndBoard11();
	case 12: return createEndBoard12();
	case 13: return createEndBoard13();
	case 14: return createEndBoard14();
	case 15: return createEndBoard15();
	case 16: return createEndBoard16();
	case 17: return createEndBoard17();
	case 18: return createEndBoard18();
	case 19: return createEndBoard19();
	case 20: return createEndBoard20();
	case 30: return createEndBoard30();
	case 40: return createEndBoard40();
	case 50: return createEndBoard50();
	case 60: return createEndBoard60();
	default: NULL;
	}
}

unsigned int EndBoardFactory::createEndBoard1() {
	return 21 * 1 + 0 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard2() {
	return 0 * 1 + 20 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard3() {
	return 0 * 1 + 0 * 24 + 0 * 576 + 7 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard4() {
	return 17 * 1 + 0 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard5() {
	return 0 * 1 + 2 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard6() {
	return 1 * 1 + 2 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard7() {
	return 2 * 1 + 0 * 24 + 6 * 576 + 10 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard8() {
	return 0 * 1 + 0 * 24 + 3 * 576 + 13 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard9() {
	return 6 * 1 + 13 * 24 + 0 * 576 + 20 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard10() {
	return 0 * 1 + 23 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard11() {
	return 0 * 1 + 20 * 24 + 0 * 576 + 23 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard12() {
	return 1 * 1 + 3 * 24 + 23 * 576 + 10 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard13() {
	return 0 * 1 + 1 * 24 + 0 * 576 + 20 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard14() {
	return 1 * 1 + 0 * 24 + 10 * 576 + 23 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard15() {
	return 1 * 1 + 10 * 24 + 22 * 576 + 13 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard16() {
	return 1 * 1 + 3 * 24 + 6 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard17() {
	return 1 * 1 + 10 * 24 + 13 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard18() {
	return 0 * 1 + 0 * 24 + 13 * 576 + 21 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard19() {
	return 0 * 1 + 6 * 24 + 3 * 576 + 20 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard20() {
	return 0 * 1 + 2 * 24 + 0 * 576 + 0 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard30() {
	return 0 * 1 + 10 * 24 + 6 * 576 + 20 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard40() {
	return 3 * 1 + 13 * 24 + 23 * 576 + 22 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard50() {
	return 1 * 1 + 10 * 24 + 22 * 576 + 13 * 13824; //red, green, blue, yellow
}

unsigned int EndBoardFactory::createEndBoard60() {
	return 2 * 1 + 0 * 24 + 3 * 576 + 17 * 13824; //red, green, blue, yellow
}