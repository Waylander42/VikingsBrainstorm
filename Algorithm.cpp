#include "stdafx.h"
#include "Algorithm.h"


Algorithm::Algorithm(Board* _board, unsigned long _endBoard):board(_board), endBoard(_endBoard)
{
}

Algorithm::Algorithm() : Algorithm(NULL, 0)
{
}


Algorithm::~Algorithm()
{
}

std::list<Step*> Algorithm::getResult() {
	return result;
}
