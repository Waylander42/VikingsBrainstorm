#pragma once
#include "Algorithm.h"
#include "Node.h"

class ParcoursEnLargeur : public Algorithm
{
public:
	ParcoursEnLargeur(Board*, unsigned long);
	~ParcoursEnLargeur();
	void launch();


private:
	bool boardInFrontierOrExplored(Board*);

	std::list<Node*> frontier;
	std::list<unsigned long> explored;
};

