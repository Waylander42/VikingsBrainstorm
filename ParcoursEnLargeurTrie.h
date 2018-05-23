#pragma once
#include "Algorithm.h"
#include "Node.h"

class ParcoursEnLargeurTrie : public Algorithm
{
public:
	ParcoursEnLargeurTrie(Board*, unsigned int);
	~ParcoursEnLargeurTrie();
	void launch();


private:
	bool boardInFrontierOrExplored(Board*);

	std::list<Node*> frontier;
	std::list<unsigned int> explored;
};

