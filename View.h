#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Board.h"
#include "Algorithm.h"
#include "Constantes.h"
#include <SDL_ttf.h>
#include "Player.h"

//The window we'll be rendering to
static SDL_Window* gWindow = NULL;

//The surface contained by the window
static SDL_Surface* gScreenSurface = NULL;

//The window renderer
static SDL_Renderer* gRenderer = NULL;

class View
{
	public:
		View(Board *, unsigned int *, Algorithm *);
		~View();

		//Starts up SDL and creates window
		bool init();
		void refreshBoard();

		void setCounter(int);
		void setSelected(int);
		void setStepNumber(int);
		void setnAlgoUI(int);
		void setRealTime(double);
		void setBoard(Board*);
		void setEndBoard(unsigned int*);

	private:
		Board* board;
		unsigned int* endboard;
		Algorithm* algo;

		int counter;
		int selected;
		int stepNumber;
		int nAlgoUI;
		double realTime;

		TTF_Font *font;
		SDL_Color black = {0, 0, 0};
		SDL_Color white = {255, 255, 255};

		SDL_Rect fondUI;
		SDL_Rect nGrid;
		SDL_Rect nAlgo;
		SDL_Rect nTime;
		SDL_Rect rectGrid;
		SDL_Rect rectAlgo;
		SDL_Rect rectTime;

		SDL_Rect fond;

		SDL_Rect topleft;
		SDL_Rect top;
		SDL_Rect topright;	
		SDL_Rect midleft;
		SDL_Rect mid; 
		SDL_Rect midright; 
		SDL_Rect botleft; 
		SDL_Rect bot;
		SDL_Rect botright; 

		SDL_Rect bblue;
		SDL_Rect bgreen;
		SDL_Rect bred;
		SDL_Rect byellow;

		SDL_Rect ablue;
		SDL_Rect agreen;
		SDL_Rect ared;
		SDL_Rect ayellow;

		SDL_Surface* screen;

		SDL_Surface* fondimg;

		SDL_Surface* piece0;
		SDL_Surface* piece1;
		SDL_Surface* piece2;
		SDL_Surface* piece3;
		SDL_Surface* piece4;
		SDL_Surface* piece5;

		SDL_Surface* bbh;
		SDL_Surface* bbv;
		SDL_Surface* bgh;
		SDL_Surface* bgv;
		SDL_Surface* brh;
		SDL_Surface* brv;
		SDL_Surface* byh;
		SDL_Surface* byv;

		SDL_Surface* arrivalBlue;
		SDL_Surface* arrivalGreen;
		SDL_Surface* arrivalRed;
		SDL_Surface* arrivalYellow;


		void loadPiece(int, SDL_Rect*);
		void prepareBoat(int, int, Boat::Color);
		void loadBoat(int, int, int, int, char, Boat::Color);
		void prepareArrival(unsigned int*, Boat::Color);
		void loadArrival(int, int, int, int, Boat::Color);

};


