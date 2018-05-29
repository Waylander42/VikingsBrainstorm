#pragma once
#include "Algorithm.h"
#include "Node.h"
#include "BinaryTree.h"

class BinaryTreeAlgo : public Algorithm
{
public:
	BinaryTreeAlgo(Board*, unsigned int);
	~BinaryTreeAlgo();
	void launch();

private:
	bool boardInExplored(Board*);

	std::list<Node*> frontier;
	CBT::BinaryTree<unsigned int> explored;
};

