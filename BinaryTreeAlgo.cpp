#include "stdafx.h"
#include "BinaryTreeAlgo.h"
#include "SearchTree.h"
#include "BinaryTree.h"
#include <iostream>


BinaryTreeAlgo::BinaryTreeAlgo(Board* _board, unsigned int _endBoard) :Algorithm(_board, _endBoard)
{
}


BinaryTreeAlgo::~BinaryTreeAlgo()
{
	frontier.clear();
}

void BinaryTreeAlgo::launch() {
	if (board->getBoatsLocation() == endBoard)
	{
		return;
	}
	SearchTree tree = SearchTree(new Node(board));
	frontier.push_back(tree.getRoot());
	explored.setRoot(tree.getRoot()->getBoard()->getIdentity());
	nodeAdress.push_back(tree.getRoot());
	while (!frontier.empty())
	{
		Node* father = frontier.front();
		frontier.pop_front();
		std::list<Step> stepList = father->getBoard()->getListOfStep();
		for (std::list<Step>::const_iterator it = stepList.begin(); it != stepList.end(); ++it) {
			Board childBoard = Board(*(father->getBoard()));
			childBoard.doStep(*it);
			if (boardInExplored(&childBoard)) {
				if (childBoard.getBoatsLocation() == endBoard) {
					std::list<Step*> steps = father->getStepsFromRacine();
					steps.push_back(new Step(*it));
					result = steps;
					return;
				}
				else {
					Node* child = new Node(&childBoard, *it, father, father->getDepth() + 1);
					frontier.push_back(child);
					nodeAdress.push_back(child);
				}
			}
		}
		stepList.clear();
	}
}

bool BinaryTreeAlgo::boardInExplored(Board* board) {
	return explored.insert(board->getIdentity());
}
