#include "stdafx.h"
#include "View.h"
#include <list>

View::View(Board * _board, unsigned int* _endboard, Algorithm * _algo) : algo(_algo), board(_board), endboard(_endboard), selected(0), counter(0), stepNumber(0), nAlgoUI(2),
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
	nGrid.x = 140; nGrid.y = 25; nGrid.h = 30; nGrid.w = 25;
	nAlgo.x = 350; nAlgo.y = 25; nAlgo.h = 30; nAlgo.w = 340;
	nTime.x = 300; nTime.y = 60; nTime.h = 30; nTime.w = 200;
	rectGrid.x = 40; rectGrid.y = 25; rectGrid.h = 30; rectGrid.w = 100;
	rectAlgo.x = 220; rectAlgo.y = 25; rectAlgo.h = 30; rectAlgo.w = 130;
	rectTime.x = 200; rectTime.y = 60; rectTime.h = 30; rectTime.w = 100;
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
			font = TTF_OpenFont("quicksand.otf", 300);
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
	std::string s = std::to_string(counter);
	std::string s2 = ALGOS[nAlgoUI];
	std::string s3 = "WIP"; //std::to_string(Player::getFinalTime()); //
	SDL_Surface* textGrid = TTF_RenderText_Blended(font, s.c_str() , black);
	SDL_Surface* textAlgo = TTF_RenderText_Blended(font, s2.c_str(), black);
	SDL_Surface* textTime = TTF_RenderText_Blended(font, s3.c_str(), black);
	SDL_Surface* textRectGrid = TTF_RenderText_Blended(font, "Grille : ", black);
	SDL_Surface* textRectAlgo = TTF_RenderText_Blended(font, "Algorithme : ", black);
	SDL_Surface* textRectTime = TTF_RenderText_Blended(font, "Temps : ", black);
	SDL_BlitScaled(textRectGrid, NULL, gScreenSurface, &rectGrid);
	SDL_BlitScaled(textRectAlgo, NULL, gScreenSurface, &rectAlgo);
	SDL_BlitScaled(textRectTime, NULL, gScreenSurface, &rectTime);
	SDL_BlitScaled(textGrid, NULL, gScreenSurface, &nGrid);
	SDL_BlitScaled(textAlgo, NULL, gScreenSurface, &nAlgo);
	SDL_BlitScaled(textTime, NULL, gScreenSurface, &nTime);
	SDL_FreeSurface(textGrid);
	SDL_FreeSurface(textAlgo);
	SDL_FreeSurface(textTime);
	SDL_FreeSurface(textRectGrid);
	SDL_FreeSurface(textRectAlgo);
	SDL_FreeSurface(textRectTime);

	//Draw Seaparts
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
	Boat* boats = board->getBoats();
	for (int i = 0; i < board->getNbBoats(); i++) {
		prepareBoat((boats + i)->getPart1()->getPosition(), (boats + i)->getOrientation1(), (boats + i)->getColor());
	}

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
	
void View::prepareBoat(int pos, int ori, Boat::Color color) {
	unsigned int location = board->getLocation(pos, ori);
	switch (location)
	{
	case 0 : loadBoat(92, 150, 66, 167, 'h', color);
		break;
	case 1: loadBoat(281, 150, 66, 167, 'h', color);
		break;
	case 2: loadBoat(470, 150, 66, 167, 'h', color);
		break;
	case 3: loadBoat(50, 192, 167, 66, 'v', color);
		break;
	case 4: loadBoat(236, 192, 167, 66, 'v', color);
		break;
	case 5: loadBoat(426, 192, 167, 66, 'v', color);
		break;
	case 6: loadBoat(614, 192, 167, 66, 'v', color);
		break;
	case 7: loadBoat(92, 336, 66, 167, 'h', color);
		break;
	case 8: loadBoat(281, 336, 66, 167, 'h', color);
		break;
	case 9: loadBoat(470, 336, 66, 167, 'h', color);
		break;
	case 10: loadBoat(50, 380, 167, 66, 'v', color);
		break;
	case 11: loadBoat(236, 380, 167, 66, 'v', color);
		break;
	case 12: loadBoat(426, 380, 167, 66, 'v', color);
		break;
	case 13: loadBoat(614, 380, 167, 66, 'v', color);
		break;
	case 14: loadBoat(92, 525, 66, 167, 'h', color);
		break;
	case 15: loadBoat(281, 525, 66, 167, 'h', color);
		break;
	case 16: loadBoat(470, 525, 66, 167, 'h', color);
		break;
	case 17: loadBoat(50, 571, 167, 66, 'v', color);
		break;
	case 18: loadBoat(236, 571, 167, 66, 'v', color);
		break;
	case 19: loadBoat(426, 571, 167, 66, 'v', color);
		break;
	case 20: loadBoat(614, 571, 167, 66, 'v', color);
		break;
	case 21: loadBoat(92, 714, 66, 167, 'h', color);
		break;
	case 22: loadBoat(281, 714, 66, 167, 'h', color);
		break;
	case 23: loadBoat(470, 714, 66, 167, 'h', color);
		break;
	}
}

void View::loadBoat(int x, int y, int h, int w, char orientation, Boat::Color color) {
	SDL_Surface * image = NULL;
	SDL_Rect* rect = NULL;
	switch (color)
	{
	case Boat::RED: bred.x = x; bred.y = y; bred.h = h; bred.w = w;
		rect = &bred;
		if (orientation == 'v') {
			image = brv;
		}
		else {
			image = brh;
		}
		break;
	case Boat::GREEN: bgreen.x = x; bgreen.y = y; bgreen.h = h; bgreen.w = w;
		rect = &bgreen;
		if (orientation == 'v') {
			image = bgv;
		}
		else {
			image = bgh;
		}
		break;
	case Boat::BLUE: bblue.x = x; bblue.y = y; bblue.h = h; bblue.w = w;
		rect = &bblue;
		if (orientation == 'v') {
			image = bbv;
		}
		else {
			image = bbh;
		}
		break;
	case Boat::YELLOW: byellow.x = x; byellow.y = y; byellow.h = h; byellow.w = w;
		rect = &byellow;
		if (orientation == 'v') {
			image = byv;
		}
		else {
			image = byh;
		}
		break;
	}
	SDL_BlitScaled(image, NULL, gScreenSurface, rect);
}

void View::setCounter(int _counter) {
	counter = _counter;
}
void View::setSelected(int _selected) {
	selected = _selected;
}
void View::setStepNumber(int _stepNumber) {
	stepNumber = _stepNumber;
}
void View::setnAlgoUI(int _nAlgoUI) {
	nAlgoUI = _nAlgoUI;
}