#pragma once
#include <iostream>

namespace CBT {

	template<typename T>
	class CNode
	{
	public:
		enum Color { RED, BLACK };

		CNode(T, Color);
		CNode(T, Color, CNode<T>*);
		CNode(T, Color, CNode<T>*, CNode<T>*, CNode<T>*);
		~CNode();
		Color getColor();
		void setColor(Color);
		T getValue();
		CNode<T>* getFather();
		CNode<T>* getLeft();
		CNode<T>* getRight();
		CNode<T>* getOncle();
		CNode<T>* getGrandFather();

		void setFather(CNode<T>*);
		void setLeft(CNode<T>*);
		void setRight(CNode<T>*);
		void print();

	private:
		Color color;
		T value;
		CNode<T>* right;
		CNode<T>* left;
		CNode<T>* father;
	};

	template<typename T>
	CNode<T>::CNode(T _value, Color _color): CNode<T>(_value, _color, NULL, NULL, NULL) {

	}

	template<typename T>
	CNode<T>::CNode(T _value, Color _color, CNode<T>* _father) : CNode<T>(_value, _color, _father, NULL, NULL) {

	}

	template<typename T>
	CNode<T>::CNode(T _value, Color _color, CNode<T>* _father, CNode<T>* _left, CNode<T>* _right) : value(_value), color(_color), father(_father), left(_left), right(_right) {

	}

	template<typename T>
	CNode<T>::~CNode() {
		if (left != NULL) {
			delete left;
		}
		if (right != NULL) {
			delete right;
		}
	}

	template<typename T>
	typename CNode<T>::Color CNode<T>::getColor() {
		return color;
	}

	template<typename T>
	void CNode<T>::setColor(Color _color) {
		color = _color;
	}

	template<typename T>
	T CNode<T>::getValue() {
		return value;
	}

	template<typename T>
	CNode<T>* CNode<T>::getFather() {
		return father;
	}

	template<typename T>
	CNode<T>* CNode<T>::getLeft() {
		return left;
	}

	template<typename T>
	CNode<T>* CNode<T>::getRight() {
		return right;
	}

	template<typename T>
	CNode<T>* CNode<T>::getOncle() {
		if (father->getFather()->getLeft() == father) {
			return father->getFather()->getRight();
		}
		else if (father->getFather()->getRight() == father) {
			return father->getFather()->getLeft();
		}
		return NULL;
	}

	template<typename T>
	CNode<T>* CNode<T>::getGrandFather() {
		return father->getFather();
	}

	template<typename T>
	void CNode<T>::setFather(CNode<T>* _father) {
		father = _father;
	}

	template<typename T>
	void CNode<T>::setLeft(CNode<T>* _left) {
		left = _left;
	}

	template<typename T>
	void CNode<T>::setRight(CNode<T>* _right) {
		right = _right;
	}

	template<typename T>
	void CNode<T>::print() {
		std::cout << value;
	}
}
