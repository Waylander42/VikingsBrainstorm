#include "stdafx.h"
#include <cmath> 
#include <iostream>
#include "Board.h"
#include "Constantes.h"


Board::Board():nbBoats(0)
{
	board[0][0] = SeaPart(0, 0, 0, 0);
	board[0][1] = SeaPart(0, 0, 0, 0);
	board[0][2] = SeaPart(0, 0, 0, 0);
	board[1][0] = SeaPart(0, 0, 0, 0);
	board[1][1] = SeaPart(0, 0, 0, 0);
	board[1][2] = SeaPart(0, 0, 0, 0);
	board[2][0] = SeaPart(0, 0, 0, 0);
	board[2][1] = SeaPart(0, 0, 0, 0);
	board[2][2] = SeaPart(0, 0, 0, 0);
	
}

Board::Board(SeaPart _board[3][3]):board{ { _board[0][0], _board[0][1], _board[0][2] },{ _board[1][0],	_board[1][1], _board[1][2] },{ _board[2][0], _board[2][1], _board[2][2] } }, nbBoats(0)
{
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = _board[i][j];
		}
	}*/
}

Board::~Board()
{
}

int Board::getIdentity() {
	int boardID = board[0][0].getIdentity() + board[0][1].getIdentity() * 6 + board[0][2].getIdentity() * 36
		+ board[1][0].getIdentity() * 216 + board[1][1].getIdentity() * 1296 + board[1][2].getIdentity() * 7776
		+ board[2][0].getIdentity() * 46656 + board[2][1].getIdentity() * 279936 + board[2][2].getIdentity() * 1679616;
	int boatsID = 0;
	for (int i = 0; i < nbBoats; i++) {
		boatsID = boats[i].getIdentity();
	}
	int ID = boardID + boatsID*10077696;
	return ID;
}

void Board::setBoats(Boat _boats[4], int _nbBoats) {
	boats[0] = _boats[0];
	boats[1] = _boats[1];
	boats[2] = _boats[2];
	boats[3] = _boats[3];
	nbBoats = _nbBoats;
}

SeaPart* Board::getSeaPart(int x, int y) {
	return &board[x][y];
}

bool Board::canRotate(int x, int y) {
	for (int i = 0; i < nbBoats; i++) {
		if (boats[i].getPart1() == &board[x][y] || boats[i].getPart2() == &board[x][y] ) {
			break;
		}
		return false;
	}
	if (y > 0) {
		if (board[x][y - 1].getRight() != 0) {
			return false;
		}
	}
	if (y < 2) {
		if (board[x][y + 1].getLeft() != 0) {
			return false;
		}
	}
	if (x > 0) {
		if (board[x - 1][y].getBot() != 0) {
			return false;
		}
	}
	if (x < 2) {
		if (board[x + 1][y].getTop() != 0) {
			return false;
		}
	}
	return true;
}


bool Board::rotateRight(int x, int y) {
	if (!canRotate(x, y)) {
		return false;
	}
	board[x][y].rotateRight();
	for (int i = 0; i < nbBoats; i++) {
		Boat::Orientation orientation;
		bool breaker = true;
		if (boats[i].getPart1() == &board[x][y]) {
			orientation = boats[i].getOrientation1();
			breaker = false;
		}
		else if (boats[i].getPart2() == &board[x][y]) {
			orientation = boats[i].getOrientation2();
			breaker = false;
		}
		if (!breaker) {
			SeaPart* part1 = &board[x][y];
			SeaPart* part2;
			switch (orientation) {
			case Boat::Orientation::TOP: if (y < 2) { // alors part 2 est à gauche
				part2 = &board[x][y + 1];
			}
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::LEFT, part2, Boat::Orientation::RIGHT);
										 break;
			case Boat::Orientation::RIGHT: if (x < 2) { // alors part 2 est en bas
				part2 = &board[x + 1][y];
			}
										   else {
											   part2 = NULL;
										   }
										   boats[i].rotate(part1, Boat::Orientation::BOT, part2, Boat::Orientation::TOP);
										   break;
			case Boat::Orientation::BOT: if (y > 0) { // alors part 2 est à droite
				part2 = &board[x][y - 1];
			}
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::RIGHT, part2, Boat::Orientation::LEFT);
										 break;
			case Boat::Orientation::LEFT: if (x > 0) { // alors part 2 est en haut
				part2 = &board[x - 1][y];
			}
										  else {
											  part2 = NULL;
										  }
										  boats[i].rotate(part1, Boat::Orientation::TOP, part2, Boat::Orientation::BOT);
										  break;
			}
		}
	}
	setBoatsIdentity();
	return true;
}

bool Board::rotateLeft(int x, int y) {
	if (!canRotate(x, y)) {
		return false;
	}
	board[x][y].rotateRight();
	for (int i = 0; i < nbBoats; i++) {
		Boat::Orientation orientation;
		bool breaker = true;
		if (boats[i].getPart1() == &board[x][y]) {
			orientation = boats[i].getOrientation1();
			breaker = false;
		}
		else if (boats[i].getPart2() == &board[x][y]) {
			orientation = boats[i].getOrientation2();
			breaker = false;
		}
		if (!breaker) {
			SeaPart* part1 = &board[x][y];
			SeaPart* part2;
			switch (orientation) {
			case Boat::Orientation::TOP: if (y > 0) { // alors part 2 est à droite
				part2 = &board[x][y - 1];
			}
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::RIGHT, part2, Boat::Orientation::LEFT);
										 break;
			case Boat::Orientation::RIGHT: if (x < 2) { // alors part 2 est en bas
				part2 = &board[x + 1][y];
			}
										   else {
											   part2 = NULL;
										   }
										   boats[i].rotate(part1, Boat::Orientation::BOT, part2, Boat::Orientation::TOP);
										   break;
			case Boat::Orientation::BOT: if (y < 2) { // alors part 2 est à gauche
				part2 = &board[x][y + 1];
			}
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::LEFT, part2, Boat::Orientation::RIGHT);
										 break;
			case Boat::Orientation::LEFT: if (x > 0) { // alors part 2 est en haut
				part2 = &board[x - 1][y];
			}
										  else {
											  part2 = NULL;
										  }
										  boats[i].rotate(part1, Boat::Orientation::TOP, part2, Boat::Orientation::BOT);
										  break;
			}
		}
	}
	setBoatsIdentity();
	return true;
}

std::list<Step> Board::getListOfStep() {
	std::list<Step> list = std::list<Step>();
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (canRotate(x, y)) {
				list.push_back(Step(x, y, Step::Rotation::LEFT));
				list.push_back(Step(x, y, Step::Rotation::RIGHT));
				list.push_back(Step(x, y, Step::Rotation::HALF));
			}
		}
	}
	return list;
}

void Board::setBoatsIdentity() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {

		}
	}
	int identity = -1;
	for (int i = 0; i < 3; i++) {        //verification sur la gauche du plateau
		if (board[i][0].getLeft() == 0) {
			identity += 1;
			for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
				if ((boats[j].getPart1() == &board[i][0] && boats[j].getOrientation1() == Boat::Orientation::LEFT) || (boats[j].getPart2() == &board[i][0] && boats[j].getOrientation2() == Boat::Orientation::LEFT)) {
					boats[j].setIdentity(identity);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {        //verification sur la droite du plateau
		if (board[i][2].getRight() == 0) {
			identity += 1;
			for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
				if ((boats[j].getPart1() == &board[i][2] && boats[j].getOrientation1() == Boat::Orientation::RIGHT) || (boats[j].getPart2() == &board[i][2] && boats[j].getOrientation2() == Boat::Orientation::RIGHT)) {
					boats[j].setIdentity(identity);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {        //verification sur le haut du plateau
		if (board[0][i].getTop() == 0) {
			identity += 1;
			for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
				if ((boats[j].getPart1() == &board[0][i] && boats[j].getOrientation1() == Boat::Orientation::TOP) || (boats[j].getPart2() == &board[0][i] && boats[j].getOrientation2() == Boat::Orientation::TOP)) {
					boats[j].setIdentity(identity);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {        //verification sur le bas du plateau
		if (board[2][i].getBot() == 0) {
			identity += 1;
			for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
				if ((boats[j].getPart1() == &board[2][i] && boats[j].getOrientation1() == Boat::Orientation::BOT) || (boats[j].getPart2() == &board[2][i] && boats[j].getOrientation2() == Boat::Orientation::BOT)) {
					boats[j].setIdentity(identity);
				}
			}
		}
	}
	//verification des positions interieur

	//pièce [1][0]
	//on regarde en haut
	if (board[1][0].getTop() == 0 && board[0][0].getBot() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][0] && boats[j].getOrientation1() == Boat::Orientation::TOP) || (boats[j].getPart2() == &board[1][0] && boats[j].getOrientation2() == Boat::Orientation::TOP)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde en bas
	if (board[1][0].getBot() == 0 && board[2][0].getTop() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][0] && boats[j].getOrientation1() == Boat::Orientation::BOT) || (boats[j].getPart2() == &board[1][0] && boats[j].getOrientation2() == Boat::Orientation::BOT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde à droite
	if (board[1][0].getRight() == 0 && board[1][1].getLeft() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][0] && boats[j].getOrientation1() == Boat::Orientation::RIGHT) || (boats[j].getPart2() == &board[1][0] && boats[j].getOrientation2() == Boat::Orientation::RIGHT)) {
				boats[j].setIdentity(identity);
			}
		}
	}

	//pièce [0][1]
	//on regarde à gauche
	if (board[0][1].getLeft() == 0 && board[0][0].getRight() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[0][1] && boats[j].getOrientation1() == Boat::Orientation::LEFT) || (boats[j].getPart2() == &board[0][1] && boats[j].getOrientation2() == Boat::Orientation::LEFT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde à droite
	if (board[0][1].getRight() == 0 && board[0][2].getLeft() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[0][1] && boats[j].getOrientation1() == Boat::Orientation::RIGHT) || (boats[j].getPart2() == &board[0][1] && boats[j].getOrientation2() == Boat::Orientation::RIGHT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde en bas
	if (board[0][1].getBot() == 0 && board[1][1].getTop() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[0][1] && boats[j].getOrientation1() == Boat::Orientation::BOT) || (boats[j].getPart2() == &board[0][1] && boats[j].getOrientation2() == Boat::Orientation::BOT)) {
				boats[j].setIdentity(identity);
			}
		}
	}

	//pièce [2][1]
	//on regarde à gauche
	if (board[2][1].getLeft() == 0 && board[2][0].getRight() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[2][1] && boats[j].getOrientation1() == Boat::Orientation::LEFT) || (boats[j].getPart2() == &board[2][1] && boats[j].getOrientation2() == Boat::Orientation::LEFT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde à droite
	if (board[2][1].getRight() == 0 && board[2][2].getLeft() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[2][1] && boats[j].getOrientation1() == Boat::Orientation::RIGHT) || (boats[j].getPart2() == &board[2][1] && boats[j].getOrientation2() == Boat::Orientation::RIGHT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde en haut
	if (board[2][1].getTop() == 0 && board[1][1].getBot() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[2][1] && boats[j].getOrientation1() == Boat::Orientation::TOP) || (boats[j].getPart2() == &board[2][1] && boats[j].getOrientation2() == Boat::Orientation::TOP)) {
				boats[j].setIdentity(identity);
			}
		}
	}

	//pièce [1][2]
	//on regarde en haut
	if (board[1][2].getTop() == 0 && board[0][2].getBot() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][2] && boats[j].getOrientation1() == Boat::Orientation::TOP) || (boats[j].getPart2() == &board[1][2] && boats[j].getOrientation2() == Boat::Orientation::TOP)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde en bas
	if (board[1][2].getBot() == 0 && board[2][2].getTop() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][2] && boats[j].getOrientation1() == Boat::Orientation::BOT) || (boats[j].getPart2() == &board[1][2] && boats[j].getOrientation2() == Boat::Orientation::BOT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
	//on regarde à gauche
	if (board[1][2].getLeft() == 0 && board[1][1].getRight() == 0) {
		identity += 1;
		for (int j = 0; j < nbBoats; j++) {  //on regarde si il y a un bateau dans le trou
			if ((boats[j].getPart1() == &board[1][2] && boats[j].getOrientation1() == Boat::Orientation::LEFT) || (boats[j].getPart2() == &board[1][2] && boats[j].getOrientation2() == Boat::Orientation::LEFT)) {
				boats[j].setIdentity(identity);
			}
		}
	}
}

void Board::print() {
	char grid[GRID_SIZE][GRID_SIZE];
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			grid[x][y] = ' ';
			if (y == 0 || y == GRID_SIZE - 1) {
				grid[x][y] = '|';
			}
			if (x == 0 || x == GRID_SIZE - 1) {
				grid[x][y] = '=';
			}
		}
	}
	int cursor = 0;
	int x = 1;
	int y = 1;
	for (int part = 0; part < NB_SEAPART; part++) {
		for (int i = 0; i < 05; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == j) {
					grid[x + i][y + j] = 'O';
				}
				else if (i + j == 4) {
					grid[x + i][y + j] = 'O';
				}
			}
		}
		if (x < GRID_SIZE - 7) {
			x += 5;
		}
		else {
			x = 1;
			y += 5;
		}

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int centerX = i * 5 + 3;
			int centerY = j * 5 + 3;
			if (board[i][j].getTop() == 1) {
				grid[centerX - 1][centerY] = 'O';
				grid[centerX - 2][centerY] = 'O';
				grid[centerX - 2][centerY - 1] = 'O';
				grid[centerX - 2][centerY + 1] = 'O';
			}
			if (board[i][j].getRight() == 1) {
				grid[centerX][centerY + 1] = 'O';
				grid[centerX][centerY + 2] = 'O';
				grid[centerX + 1][centerY + 2] = 'O';
				grid[centerX - 1][centerY + 2] = 'O';
			}
			if (board[i][j].getBot() == 1) {
				grid[centerX + 1][centerY] = 'O';
				grid[centerX + 2][centerY] = 'O';
				grid[centerX + 2][centerY - 1] = 'O';
				grid[centerX + 2][centerY + 1] = 'O';
			}
			if (board[i][j].getLeft() == 1) {
				grid[centerX][centerY - 1] = 'O';
				grid[centerX][centerY - 2] = 'O';
				grid[centerX + 1][centerY - 2] = 'O';
				grid[centerX - 1][centerY - 2] = 'O';
			}
		}
	}

	for (int i = 0; i < nbBoats; i++) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				int centerX = x * 5 + 3;
				int centerY = y * 5 + 3;
				Boat::Orientation orientation;
				bool breaker = true;
				if (boats[i].getPart1() == &board[x][y]) {
					orientation = boats[i].getOrientation1();
					breaker = false;
				}
				else if (boats[i].getPart2() == &board[x][y]) {
					orientation = boats[i].getOrientation2();
					breaker = false;
				}
				if (!breaker) {
					switch (orientation) {
					case Boat::Orientation::TOP: grid[centerX + 1][centerY] = boats[i].getColor();
						grid[centerX + 2][centerY] = boats[i].getColor();
						grid[centerX + 2][centerY - 1] = boats[i].getColor();
						grid[centerX + 2][centerY + 1] = boats[i].getColor();
						break;
					case Boat::Orientation::LEFT: grid[centerX][centerY + 1] = boats[i].getColor();
						grid[centerX][centerY + 2] = boats[i].getColor();
						grid[centerX + 1][centerY + 2] = boats[i].getColor();
						grid[centerX - 1][centerY + 2] = boats[i].getColor();
						break;
					case Boat::Orientation::BOT: grid[centerX - 1][centerY] = boats[i].getColor();
						grid[centerX - 2][centerY] = boats[i].getColor();
						grid[centerX - 2][centerY - 1] = boats[i].getColor();
						grid[centerX - 2][centerY + 1] = boats[i].getColor();
						break;
					case Boat::Orientation::RIGHT: grid[centerX][centerY - 1] = boats[i].getColor();
						grid[centerX][centerY - 2] = boats[i].getColor();
						grid[centerX + 1][centerY - 2] = boats[i].getColor();
						grid[centerX - 1][centerY - 2] = boats[i].getColor();
						break;
					}
				}
			}
		}
	}

	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			std::cout << grid[x][y] << ' ';
		}
		std::cout << "\n";
	}

}