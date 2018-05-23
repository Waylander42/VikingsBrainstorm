#include "stdafx.h"
#include "SearchTree.h"
#include <iostream>

SearchTree::SearchTree(Node* _root):root(_root)
{
}


SearchTree::~SearchTree()
{
	//delete root;
}

Node* SearchTree::getRoot() {
	return root;
}
