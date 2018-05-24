#include "stdafx.h"
#include "ParcoursEnLargeur.h"
#include "SearchTree.h"
#include <iostream>


ParcoursEnLargeur::ParcoursEnLargeur(Board* _board, unsigned int _endBoard):Algorithm(_board, _endBoard)
{
}


ParcoursEnLargeur::~ParcoursEnLargeur()
{
	while (frontier.size() != 0) {
		if (frontier.back() != NULL) {
			delete frontier.back();
		}
		explored.pop_back();
	}
	explored.clear();
}

void ParcoursEnLargeur::launch() {
	if (board->getBoatsLocation() == endBoard)
	{
		return;
	}
	SearchTree tree = SearchTree(new Node(board));
	frontier.push_back(tree.getRoot());
	nodeAdress.push_back(tree.getRoot());
	while (!frontier.empty())
	{
		Node* father = frontier.front();
		frontier.pop_front();
		explored.push_back(father->getBoard()->getIdentity());
		std::list<Step> stepList = father->getBoard()->getListOfStep();
		for (std::list<Step>::const_iterator it = stepList.begin(); it != stepList.end(); ++it) {
			Board childBoard = Board(*(father->getBoard()));
			childBoard.doStep(*it);
			if (!boardInFrontierOrExplored(&childBoard)) {
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

bool ParcoursEnLargeur::boardInFrontierOrExplored(Board* board) {
	std::list<unsigned int>::const_iterator exploredEnd = explored.end();
	for (std::list<unsigned int>::const_iterator it = explored.begin(); it != exploredEnd; ++it) {
		if (board->getIdentity() == (unsigned int)(*it) ) {
			return true;
		}
	}
	std::list<Node*>::const_iterator frontierEnd = frontier.end();
	for (std::list<Node*>::const_iterator it = frontier.begin(); it != frontierEnd; ++it) {
		if (board->getIdentity() == (*it)->getBoard()->getIdentity()) {
			return true;
		}
	}
	return false;
}