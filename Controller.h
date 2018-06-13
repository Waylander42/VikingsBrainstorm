#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "View.h"
#include "Constantes.h"
#include "BoardFactory.h"
#include "EndBoardFactory.h"
#include "IA.h"





class Controller
{
public:
	Controller(Board *, unsigned int *, int);
	~Controller();

	void setView(View *);

	void control();

	void setCounter(int);
	void setSelected(int);
	void setStepNumber(int);
	void setnAlgoUI(int);

private:

	int counter;
	int selected;
	int stepNumber;
	int nAlgoUI;
	std::list<Step*> stepsList;

	Board * board;
	unsigned int* endboard;
	Algorithm * algo;
	View * view;
};

