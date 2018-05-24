#include "stdafx.h"
#include "ParcoursEnLargeurTrie.h"
#include "SearchTree.h"
#include <iostream>


ParcoursEnLargeurTrie::ParcoursEnLargeurTrie(Board* _board, unsigned int _endBoard) :Algorithm(_board, _endBoard)
{
}


ParcoursEnLargeurTrie::~ParcoursEnLargeurTrie()
{
	while (frontier.size() != 0) {
		if (frontier.back() != NULL) {
			delete frontier.back();
		}
		explored.pop_back();
	}
	explored.clear();
}

void ParcoursEnLargeurTrie::launch() {
	if (board->getBoatsLocation() == endBoard)
	{
		return;
	}
	SearchTree tree = SearchTree(new Node(board));
	frontier.push_back(tree.getRoot());
	explored.push_back(tree.getRoot()->getBoard()->getIdentity());
	nodeAdress.push_back(tree.getRoot());
	while (!frontier.empty())
	{
		Node* father = frontier.front();
		frontier.pop_front();
		std::list<Step> stepList = father->getBoard()->getListOfStep();
		for (std::list<Step>::const_iterator it = stepList.begin(); it != stepList.end(); ++it) {
			Board childBoard = Board(*(father->getBoard()));
			childBoard.doStep(*it);
			if (!boardInExplored(&childBoard)) {
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

bool ParcoursEnLargeurTrie::boardInExplored(Board* board) {
	std::list<unsigned int>::const_iterator itEnd = explored.end();
	for (std::list<unsigned int>::const_iterator it = explored.begin(); it != itEnd; ++it) {
		if (board->getIdentity() <= (unsigned int)(*it)) {
			if (board->getIdentity() == (unsigned int)(*it)) {
				return true;
			}
			else {
				explored.insert(it, board->getIdentity());
				return false;
			}
		}
	}
	return false;
}