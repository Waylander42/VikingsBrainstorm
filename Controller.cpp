#include "stdafx.h"
#include "Controller.h"


Controller::Controller(Board * _board, unsigned int* _endboard, Algorithm * _algo) : algo(_algo), board(_board), endboard(_endboard), counter(1), selected(-1),stepNumber(0), nAlgoUI(2)
{
}


Controller::~Controller()
{
}

void Controller::setView(View * _view) {
	view = _view;
	view->setCounter(counter);
	view->setSelected(selected);
	view->setStepNumber(stepNumber);
}

void Controller::control() {


	//Start up SDL and create window
	if (!view->init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		std::list<Step*> stepsList;
		std::list<Step*> passedSteps;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				//User presses a key
				else if (e.type == SDL_KEYDOWN)
				{
					//Select surfaces based on key press
					switch (e.key.keysym.sym)
					{
						case SDLK_UP:
							if (selected == -1) {
								if (nAlgoUI == 2) setnAlgoUI(0);
								else setnAlgoUI(nAlgoUI + 1);
								view->refreshBoard();
							}
							break;

						case SDLK_DOWN:
							if (selected == -1) {
								if (nAlgoUI == 0) setnAlgoUI(2);
								else setnAlgoUI(nAlgoUI - 1);
								view->refreshBoard();
							}
							break;

						case SDLK_LEFT:
							if (selected != -1) {
								setStepNumber(stepNumber-1);
								if (passedSteps.front() != NULL) {
									board->doStep(*passedSteps.front());
								}
								stepsList.push_front(passedSteps.front());
								passedSteps.pop_front();
								view->refreshBoard();
							}
							else {
								if (counter == 1) {
									setCounter(60);
								}
								else {
									setCounter(counter-1);
								}
								Board* newBoard = BoardFactory::createBoard(counter);
								*board = Board(*newBoard);
								delete newBoard;
								*endboard = EndBoardFactory::createEndBoard(counter);
								view->refreshBoard();
							}
							break;

						case SDLK_RIGHT:
							if (selected != -1) {
								setStepNumber(stepNumber+1);
								if (stepsList.front() != NULL) {
									board->doStep(*stepsList.front());
								}
								passedSteps.push_front(stepsList.front());
								stepsList.pop_front();
								view->refreshBoard();
							}
							else {
								if (counter == 60) {
									setCounter(1);
								}
								else {
									setCounter(counter+1);
								}
								Board* newBoard = BoardFactory::createBoard(counter);
								*board = Board(*newBoard);
								delete newBoard;
								*endboard = EndBoardFactory::createEndBoard(counter);
								view->refreshBoard();
							}
							break;

						case SDLK_RETURN:
							if (selected == -1) {
								setSelected(counter);
								double timer = clock();
								algo->launch();
								view->setRealTime((double)clock()- timer);
								stepsList = algo->getResult();
							}
							break;

						case SDLK_BACKSPACE:
							setSelected(-1);
							view->setRealTime(0.0);
							break;

						case SDLK_ESCAPE:
							quit = true;
							break;

						default:
							break;
					}
				}
			}

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(gRenderer);

			//Update screen
			SDL_RenderPresent(gRenderer);
		}
	}
}

void Controller::setCounter(int _counter) {
	counter = _counter;
	view->setCounter(_counter);
}
void Controller::setSelected(int _selected) {
	selected = _selected;
	view->setSelected(_selected);
}
void Controller::setStepNumber(int _stepNumber) {
	stepNumber = _stepNumber;
	view->setStepNumber(_stepNumber);
}
void Controller::setnAlgoUI(int _nAlgoUI) {
	nAlgoUI = _nAlgoUI;
	view->setnAlgoUI(_nAlgoUI);
}