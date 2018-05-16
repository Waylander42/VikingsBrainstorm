#include "stdafx.h"
#include "ParcoursEnLargeur.h"
#include "SearchTree.h"


ParcoursEnLargeur::ParcoursEnLargeur(Board* _board, unsigned int _endBoard):Algorithm(_board, _endBoard)
{
}


ParcoursEnLargeur::~ParcoursEnLargeur()
{
}

void ParcoursEnLargeur::launch() {
	if (board->getBoatsLocation() == endBoard)
	{
		return;
	}
	SearchTree tree = SearchTree(new Node(board));
	frontier.push_back(tree.getRoot());
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
					steps.push_back(&(Step)(*it));
					result = steps;
					return;
				}
				else {
					Node* child = new Node(&childBoard, &(Step)(*it), father, father->getDepth());
					frontier.push_back(child);
				}
			}
		}
	}
}

bool ParcoursEnLargeur::boardInFrontierOrExplored(Board* board) {
	for (std::list<unsigned int>::const_iterator it = explored.begin(); it != explored.end(); ++it) {
		if (board->getIdentity() == *it) {
			return true;
		}
	}
	for (std::list<Node*>::const_iterator it = frontier.begin(); it != frontier.end(); ++it) {
		if (board->getIdentity() == (*it)->getBoard()->getIdentity()) {
			return true;
		}
	}
	return false;
}