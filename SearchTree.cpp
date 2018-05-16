#include "stdafx.h"
#include "SearchTree.h"


SearchTree::SearchTree(Node* _root):root(_root)
{
}


SearchTree::~SearchTree()
{
}

Node* SearchTree::getRoot() {
	return root;
}
