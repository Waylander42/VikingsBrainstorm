#pragma once
#include "CNode.h"
#include <iostream>
#include <list>

namespace CBT {
	template<typename T>
	class BinaryTree
	{
	public:
		BinaryTree();
		BinaryTree(T);
		~BinaryTree();

		void setRoot(T value);
		bool insert(T);
		void print();

	private:
		CNode<T>* root;
		bool insertionRecursif(CNode<T>*, CNode<T>*);
		void insertionReparTree(CNode<T>*);
		void insertionCase1(CNode<T>*);
		void insertionCase2(CNode<T>*);
		void insertionCase3(CNode<T>*);
		void insertionCase4(CNode<T>*);
		void rotationLeft(CNode<T>*);
		void rotationRight(CNode<T>*);
	};

	template<typename T>
	BinaryTree<T>::BinaryTree(): root(NULL) {
	}

	template<typename T>
	BinaryTree<T>::BinaryTree(T value): root(new CNode<T>(value, CNode<T>::Color::BLACK)) {
	}

	template<typename T>
	BinaryTree<T>::~BinaryTree() {
		delete root;
	}

	template<typename T>
	void BinaryTree<T>::setRoot(T value) {
		if (root != NULL) {
			delete root;
		}
		root = new CNode<T>(value, CNode<T>::Color::BLACK);
	}

	template<typename T>
	bool BinaryTree<T>::insert(T value)
	{
		CNode<T>* node = new CNode<T>(value, CNode<T>::Color::RED);
		// insertion d'un nouveau noeud dans l'arbre
		if (insertionRecursif(root, node) == false) {
			return false;
		}

		// Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
		insertionReparTree(node);

		// recherche de la nouvelle racine à renvoyer
		root = node;
		while (root->getFather() != NULL) {
			root = root->getFather();
		}
		return true;
	}

	template<typename T>
	bool BinaryTree<T>::insertionRecursif(CNode<T>* root, CNode<T>* node) {
		if (root != NULL && node->getValue() == root->getValue()) {
			return false;
		}
		// descente récursive dans l'arbre jusqu'à atteindre une feuille
		if (root != NULL && node->getValue() < root->getValue()) {
			if (root->getLeft() != NULL) {
				return insertionRecursif(root->getLeft(), node);
			}
			else {
				root->setLeft(node);
			}
		}
		else if (root != NULL) {
			if (root->getRight() != NULL) {
				return insertionRecursif(root->getRight(), node);
			}
			else {
				root->setRight(node);
			}
		}

		node->setFather(root);
	}

	template<typename T>
	void BinaryTree<T>::insertionReparTree(CNode<T>* node)
	{
		if (node->getFather() == NULL) {
			insertionCase1(node);
		}
		else if (node->getFather()->getColor() == CNode<T>::Color::BLACK) {
			insertionCase2(node);
		}
		else if (node->getOncle() != NULL) {
			if (node->getOncle()->getColor() == CNode<T>::Color::RED) {
				insertionCase3(node);
			}
		}
		else {
			insertionCase4(node);
		}
	}

	template<typename T>
	void BinaryTree<T>::insertionCase1(CNode<T>* n)
	{
		if (n->getFather() == NULL)
			n->setColor(CNode<T>::Color::BLACK);
	}

	template<typename T>
	void BinaryTree<T>::insertionCase2(CNode<T>* n)
	{
		return; /* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
	}

	template<typename T>
	void BinaryTree<T>::insertionCase3(CNode<T>* n)
	{
		n->getFather()->setColor(CNode<T>::Color::BLACK);
		n->getOncle()->setColor(CNode<T>::Color::BLACK);
		n->getGrandFather()->setColor(CNode<T>::Color::RED);
		insertionReparTree(n->getGrandFather());
	}


	template<typename T>
	void BinaryTree<T>::insertionCase4(CNode<T>* n)
	{
		CNode<T>* p = n->getFather();
		CNode<T>* g = n->getGrandFather();

		if (g->getLeft() != NULL) {
			if (n == g->getLeft()->getRight()) {
				rotationLeft(p);
				n = n->getLeft();
			}
		}
		if (g->getRight() != NULL) {
			if (n == g->getRight()->getLeft()) {
				rotationRight(p);
				n = n->getRight();
			}
		}

		p = n->getFather();
		g = n->getGrandFather();

		if (n == p->getLeft()) {
			rotationRight(g);
		}
		else {
			rotationLeft(g);
		}
		p->setColor(CNode<T>::Color::BLACK);
		g->setColor(CNode<T>::Color::RED);
	}

	template<typename T>
	void BinaryTree<T>::rotationLeft(CNode<T>* n) {
		CNode<T>* y = n->getRight();
		n->setRight(y->getLeft());
		if (y->getLeft() != NULL) {
			y->getLeft()->setFather(n);// on ne change pas le parent de la sentinelle
		}
		y->setFather(n->getFather());
		if (n->getFather() == NULL) {
			root = y;
		}
		else {
			if (n->getFather()->getLeft() == n) {
				n->getFather()->setLeft(y);
			}
			else {
				n->getFather()->setRight(y);
			}
		}
		y->setLeft(n);
		n->setFather(y);
	}

	template<typename T>
	void BinaryTree<T>::rotationRight(CNode<T>* n) {
		CNode<T>* y = n->getLeft();
		n->setLeft(y->getRight());
		if (y->getRight() != NULL) {
			y->getRight()->setFather(n); // on ne change pas le parent de la sentinelle
		}
		y->setFather(n->getFather());
		if (n->getFather() == NULL) {
			root = y;
		}
		else {
			if (n->getFather()->getRight() == n) {
				n->getFather()->setRight(y);
			}
			else {
				n->getFather()->setLeft(y);
			}
		}
		y->setRight(n);
		n->setFather(y);
	}

	template<typename T>
	void BinaryTree<T>::print() {
		std::list<CNode<T>*> brother;
		std::list<CNode<T>*> sons;
		brother.push_back(root);
		while (brother.size() > 0) {
			while (brother.size() > 0) {
				if (brother.front() != NULL) {
					CNode<T>* node = brother.front();
					node->print();
					sons.push_back(node->getLeft());
					sons.push_back(node->getRight());
				}
				else {
					std::cout << "0";
				}
				brother.pop_front();
				std::cout << " ";
			}
			std::cout << std::endl;
			brother = sons;
			sons.clear();
		}
	}
}
