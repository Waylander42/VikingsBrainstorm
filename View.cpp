#include "stdafx.h"
#include "View.h"
#include <list>

View::View(Board * _board, unsigned int* _endboard, Algorithm * _algo) : algo(_algo), board(_board), endboard(_endboard), selected(0), counter(0), stepNumber(0),
screen(IMG_Load("img/fondScreen.png")),
fondimg(IMG_Load("img/fond.png")),
piece0(IMG_Load("img/piece0.png")),
piece1(IMG_Load("img/piece1.png")),
piece2(IMG_Load("img/piece2.png")),
piece3(IMG_Load("img/piece3.png")),
piece4(IMG_Load("img/piece4.png")),
piece5(IMG_Load("img/piece5.png")),
bbh(IMG_Load("img/bbh.png")),
bbv(IMG_Load("img/bbv.png")),
bgh(IMG_Load("img/bgh.png")),
bgv(IMG_Load("img/bgv.png")),
brh(IMG_Load("img/brh.png")),
brv(IMG_Load("img/brv.png")),
byh(IMG_Load("img/byh.png")),
byv(IMG_Load("img/byv.png"))
{
	fondUI.x = 0; fondUI.y = 0; fondUI.h = 830; fondUI.w = 730;
	nGrid.x = 50; nGrid.y = 25; nGrid.h = 30; nGrid.w = 200;
	nAlgo.x = 300; nAlgo.y = 25; nAlgo.h = 30; nAlgo.w = 400;
	fond.x = 0; fond.y = 100; fond.h = 730; fond.w = 730;
	topleft.x = 50; topleft.y = 150; topleft.h = 250; topleft.w = 250;
	top.x = 239; top.y = 150; top.h = 250; top.w = 250;
	topright.x = 428; topright.y = 150; topright.h = 250; topright.w = 250;
	midleft.x = 50; midleft.y = 339; midleft.h = 250; midleft.w = 250;
	mid.x = 239; mid.y = 339; mid.h = 250; mid.w = 250;
	midright.x = 428; midright.y = 339; midright.h = 250; midright.w = 250;
	botleft.x = 50; botleft.y = 528; botleft.h = 250; botleft.w = 250;
	bot.x = 239; bot.y = 528; bot.h = 250; bot.w = 250;
	botright.x = 428; botright.y = 528; botright.h = 250; botright.w = 250;
}

View::~View() {
}

bool View::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
	{
		printf("SDL / SDL_TTF could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Vikings Brainstorm Solver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			font = TTF_OpenFont("angelina.ttf", 300);
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);

				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	refreshBoard();
	return success;
}

void View::refreshBoard() {
	SDL_BlitScaled(screen, NULL, gScreenSurface, &fondUI);
	SDL_BlitScaled(fondimg, NULL, gScreenSurface, &fond);
	std::string s = "Grille : " + std::to_string(counter);
	std::string s2 = "Algorithme : " + ALGOS[nAlgoUI];
	textGrid = TTF_RenderText_Blended(font, s.c_str() , black);
	textAlgo = TTF_RenderText_Blended(font, s2.c_str(), black);
	SDL_BlitScaled(textGrid, NULL, gScreenSurface, &nGrid);
	SDL_BlitScaled(textAlgo, NULL, gScreenSurface, &nAlgo);

	//Draw Seaparts
	board->print(*endboard);
	std::list<int> identities;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			identities.push_back(board->getSeaPart(i, j)->getIdentity());
		}
	}
	loadPiece(identities.front(), &topleft);
	identities.pop_front();
	loadPiece(identities.front(), &top);
	identities.pop_front();
	loadPiece(identities.front(), &topright);
	identities.pop_front();
	loadPiece(identities.front(), &midleft);
	identities.pop_front();
	loadPiece(identities.front(), &mid);
	identities.pop_front();
	loadPiece(identities.front(), &midright);
	identities.pop_front();
	loadPiece(identities.front(), &botleft);
	identities.pop_front();
	loadPiece(identities.front(), &bot);
	identities.pop_front();
	loadPiece(identities.front(), &botright);
	identities.pop_front();

	SDL_UpdateWindowSurface(gWindow);
}

void View::loadPiece(int id, SDL_Rect* rect) {
	SDL_Surface * piece = NULL;
	switch (id) {
	case 0:
		piece = piece0;
		break;
	case 1:
		piece = piece1;
		break;
	case 2:
		piece = piece2;
		break;
	case 3:		
		piece = piece3;
		break;
	case 4:
		piece = piece4;
		break;
	case 5: 
		piece = piece5;
		break;
	}
	SDL_BlitScaled(piece, NULL, gScreenSurface, rect);
}
	
/*void View::loadBoat() {
	unsigned int id = Board::getBoatsLocation();
}*/

void View::setCounter(int _counter) {
	counter = _counter;
}
void View::setSelected(int _selected) {
	selected = _selected;
}
void View::setStepNumber(int _stepNumber) {
	stepNumber = _stepNumber;
}