#include "stdafx.h"
#include "Algorithm.h"


Algorithm::Algorithm(Board* _board, unsigned int _endBoard):board(_board), endBoard(_endBoard)
{
}

Algorithm::Algorithm() : Algorithm(NULL, 0)
{
}


Algorithm::~Algorithm()
{
	while (result.size() != 0) {
		if (result.back() != NULL) {
			delete result.back();
		}
		result.pop_back();
	}
	while (nodeAdress.size() != 0) {
		if (nodeAdress.back() != NULL) {
			delete nodeAdress.back();
		}
		nodeAdress.pop_back();
	}

	result.clear();
	nodeAdress.clear();
}

std::list<Step*> Algorithm::getResult() {
	return result;
}
