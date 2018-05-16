#pragma once
#include "Node.h"
class SearchTree
{
public:
	SearchTree(Node*);
	~SearchTree();
	Node* getRoot();

private:
	Node* root;
};

