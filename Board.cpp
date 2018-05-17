#include "stdafx.h"
#include <cmath> 
#include <iostream>
#include "Board.h"
#include "Constantes.h"


Board::Board():nbBoats(0)
{
	board[0][0] = SeaPart(0);
	board[0][1] = SeaPart(0);
	board[0][2] = SeaPart(0);
	board[1][0] = SeaPart(0);
	board[1][1] = SeaPart(0);
	board[1][2] = SeaPart(0);
	board[2][0] = SeaPart(0);
	board[2][1] = SeaPart(0);
	board[2][2] = SeaPart(0);
	
}

Board::Board(SeaPart _board[3][3]):board{ { _board[0][0], _board[0][1], _board[0][2] },
										{ _board[1][0],	_board[1][1], _board[1][2] },
										{ _board[2][0], _board[2][1], _board[2][2] } }, nbBoats(0)
{
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = _board[i][j];
		}
	}*/
}

Board::Board(Board const& b):nbBoats(b.nbBoats), board{ { b.board[0][0], b.board[0][1], b.board[0][2] },
														{ b.board[1][0], b.board[1][1], b.board[1][2] },
														{ b.board[2][0], b.board[2][1], b.board[2][2] } }

{	
	for (int i = 0; i < 4; i++) {
		SeaPart* part1 = NULL;
		SeaPart* part2 = NULL;
		if (b.boats[i].getPart1() != NULL) {
			part1 = this->getSeapartWithId(b.boats[i].getPart1()->getPosition());
		}
		if (b.boats[i].getPart2() != NULL) {
			part2 = this->getSeapartWithId(b.boats[i].getPart2()->getPosition());
		}
		boats[i] = Boat(part1, b.boats[i].getOrientation1(), part2, b.boats[i].getOrientation2(), b.boats[i].getColor());
	}
	setBoatsIdentity();
}

Board::~Board()
{
}

//retourne l'emplacement du bateau. L'emplacement du bateau est un entier entre 0 et 23
unsigned int Board::getLocation(int _pos, int _ori) {
	if (_ori == Boat::Orientation::BOT) {
		return 4 * (_pos / 3) + _pos;
	}
	else if (_ori == Boat::Orientation::TOP) {
		return 4 * (_pos / 3) + _pos + 7;
	}
	else if (_ori == Boat::Orientation::RIGHT) {
		return 4 * (_pos / 3) + _pos + 3;
	}
	else {
		return 4 * (_pos / 3) + _pos + 4;
	}
}

//retourne un entier qui décrit de façon unique la position d'un bateau en fonction de sa couleur
unsigned int Board::getBoatLocation(int i) {
	unsigned int res = 0;
	char color = boats[i].getColorChar();
	int pos = boats[i].getPart1()->getPosition();
	int orientation = boats[i].getOrientation1();
	res = getLocation(pos, orientation);
	switch (color) {
	case 'R': return res * 1;
	case 'G': return res * 24;
	case 'B': return res * 576;
	case 'Y': return res * 13824;
	}
}

//retourne un entier qui décrit de façon unique la position des bateaux
unsigned int Board::getBoatsLocation() {
	unsigned int res = 0;
	for (int i = 0; i < nbBoats; i++) {
		res += getBoatLocation(i);
	}
	return res;
}


unsigned int Board::getIdentity() {
	unsigned int boardID = board[0][0].getIdentity() + board[0][1].getIdentity() * 6 + board[0][2].getIdentity() * 36
		+ board[1][0].getIdentity() * 216 + board[1][1].getIdentity() * 1296 + board[1][2].getIdentity() * 7776
		+ board[2][0].getIdentity() * 46656 + board[2][1].getIdentity() * 279936 + board[2][2].getIdentity() * 1679616;
	unsigned int boatsID = 0;
	for (int i = 0; i < nbBoats; i++) {
		boatsID += boats[i].getIdentity();
	}
	unsigned int ID = boardID + boatsID*10077696;
	return ID;
}

void Board::initBoats(Boat _boats[4], int _nbBoats) {
	boats[0] = _boats[0];
	boats[1] = _boats[1];
	boats[2] = _boats[2];
	boats[3] = _boats[3];
	nbBoats = _nbBoats;
}

void Board::initSeaPart() {
	int count = 0;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			board[x][y].init(count);
			count++;
		}
	}
}

SeaPart* Board::getSeaPart(int x, int y) {
	return &board[x][y];
}

SeaPart * Board::getSeapartWithId(int i)
{
	SeaPart* part = NULL;
	switch (i) {
	case 0: return part = &board[0][0];
		break;
	case 1: return part = &board[0][1];
		break;
	case 2: return part = &board[0][2];
		break;
	case 3: return part = &board[1][0];
		break;
	case 4: return part = &board[1][1];
		break;
	case 5: return part = &board[1][2];
		break;
	case 6: return part = &board[2][0];
		break;
	case 7: return part = &board[2][1];
		break;
	case 8: return part = &board[2][2];
		break;
	}
	return part;
}

bool Board::canRotate(int x, int y) {
	int breaker = true;
	for (int i = 0; i < nbBoats; i++) {
		if (boats[i].getPart1() == getSeaPart(x,y) || boats[i].getPart2() == getSeaPart(x, y)) {  //si il y a un bateau qui touche la pièce, alors on peut tourner
			breaker = false;
			break;
		}
	}
	if (breaker) {
		return false;
	}
	if (y > 0) {
		if (board[x][y - 1].getRight() != 0) { //si la pièce à gauche possède un trou à droite
			return false;
		}
	}
	if (y < 2) {
		if (board[x][y + 1].getLeft() != 0) { //si la pièce à droite possède un trou à gauche
			return false;
		}
	}
	if (x > 0) {
		if (board[x - 1][y].getBot() != 0) { //si la pièce en haut possède un trou en bas
			return false;
		}
	}
	if (x < 2) {
		if (board[x + 1][y].getTop() != 0) { //si la pièce en bas possède un trou en haut
			return false;
		}
	}
	return true;
}


bool Board::rotateLeft(int x, int y) {
	if (!canRotate(x, y)) {
		return false;
	}
	board[x][y].rotateLeft();
	for (int i = 0; i < nbBoats; i++) {
		Boat::Orientation orientation;
		bool breaker = true;
		if (boats[i].getPart1() == getSeaPart(x,y)) {
			orientation = boats[i].getOrientation1();
			breaker = false;
		}
		else if (boats[i].getPart2() == getSeaPart(x, y)) {
			orientation = boats[i].getOrientation2();
			breaker = false;
		}
		if (!breaker) {  //si le bateau est à coté de la partie qui tourne, on tourne le bateau
			SeaPart* part1 = getSeaPart(x, y);
			SeaPart* part2;
			switch (orientation) {
			case Boat::Orientation::TOP: if (y < 2) { // alors part 2 est à droite
											 part2 = getSeaPart(x, y + 1);
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
										   boats[i].rotate(part1, Boat::Orientation::BOT, part2, Boat::Orientation::TOP);
										   break;
			case Boat::Orientation::BOT: if (y > 0) { // alors part 2 est à gauche
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
										  boats[i].rotate(part1, Boat::Orientation::TOP, part2, Boat::Orientation::BOT);
										  break;
			}
		}
	}
	setBoatsIdentity();  //on met à jour l'identité des bateaux
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
		if (!breaker) {  //si le bateau est à coté de la partie qui tourne, on tourne le bateau
			SeaPart* part1 = &board[x][y];
			SeaPart* part2;
			switch (orientation) {
			case Boat::Orientation::TOP: if (y > 0) { // alors part 2 est à gauche
											 part2 = &board[x][y - 1];
										 }
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::RIGHT, part2, Boat::Orientation::LEFT);
										 break;
			case Boat::Orientation::RIGHT: if (x > 0) { // alors part 2 est en haut
											   part2 = &board[x - 1][y];
										   }
										   else {
											   part2 = NULL;
										   }
										   boats[i].rotate(part1, Boat::Orientation::BOT, part2, Boat::Orientation::TOP);
										   break;
			case Boat::Orientation::BOT: if (y < 2) { // alors part 2 est à droite
											 part2 = &board[x][y + 1];
										 }
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::LEFT, part2, Boat::Orientation::RIGHT);
										 break;
			case Boat::Orientation::LEFT: if (x < 2) { // alors part 2 est en bas
											  part2 = &board[x + 1][y];
										  }
										  else {
											  part2 = NULL;
										  }
										  boats[i].rotate(part1, Boat::Orientation::TOP, part2, Boat::Orientation::BOT);
										  break;
			}
		}
	}
	setBoatsIdentity();  //on met à jour l'identité des bateaux
	return true;
}

bool Board::rotateHalf(int x, int y) {
	if (!canRotate(x, y)) {
		return false;
	}
	board[x][y].rotateHalf();
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
		if (!breaker) {  //si le bateau est à coté de la partie qui tourne, on tourne le bateau
			SeaPart* part1 = &board[x][y];
			SeaPart* part2;
			switch (orientation) {
			case Boat::Orientation::TOP: if (x > 0) { // alors part 2 est en haut
											 part2 = &board[x - 1][y];
										 }
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::BOT, part2, Boat::Orientation::TOP);
										 break;
			case Boat::Orientation::RIGHT: if (y < 2) { // alors part 2 est à droite
											   part2 = &board[x][y + 1];
										   }
										   else {
											   part2 = NULL;
										   }
										   boats[i].rotate(part1, Boat::Orientation::LEFT, part2, Boat::Orientation::RIGHT);
										   break;
			case Boat::Orientation::BOT: if (x < 2) { // alors part 2 est en bas
											 part2 = &board[x + 1][y];
										 }
										 else {
											 part2 = NULL;
										 }
										 boats[i].rotate(part1, Boat::Orientation::TOP, part2, Boat::Orientation::BOT);
										 break;
			case Boat::Orientation::LEFT: if (y > 0) { // alors part 2 est à gauche
											  part2 = &board[x][y - 1];
										  }
										  else {
											  part2 = NULL;
										  }
										  boats[i].rotate(part1, Boat::Orientation::RIGHT, part2, Boat::Orientation::LEFT);
										  break;
			}
		}
	}
	setBoatsIdentity();  //on met à jour l'identité des bateaux
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

bool Board::doStep(Step step) {
	if (!canRotate(step.getX(), step.getY())) {
		return false;
	}
	switch (step.getRotation()) {
		case Step::Rotation::LEFT: rotateLeft(step.getX(), step.getY());
			break;
		case Step::Rotation::RIGHT : rotateRight(step.getX(), step.getY());
			break;
		case Step::Rotation::HALF : rotateHalf(step.getX(), step.getY());
			break;
	}
	return true;
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

void Board::print(unsigned int endBoard) {
	char grid[GRID_SIZE][GRID_SIZE];
	//dessine le coutour de la grille
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
	//dessine les diagonales qui sont quoiqu'il arrive plaines
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

	//dessine les sea part
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

	//dessine les bateaux
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
					case Boat::Orientation::TOP: //grid[centerX + 1][centerY] = boats[i].getColor();
						grid[centerX + 2][centerY] = boats[i].getColorChar();
						//grid[centerX + 2][centerY - 1] = boats[i].getColor();
						//grid[centerX + 2][centerY + 1] = boats[i].getColor();
						break;
					case Boat::Orientation::LEFT: //grid[centerX][centerY + 1] = boats[i].getColor();
						grid[centerX][centerY + 2] = boats[i].getColorChar();
						//grid[centerX + 1][centerY + 2] = boats[i].getColor();
						//grid[centerX - 1][centerY + 2] = boats[i].getColor();
						break;
					case Boat::Orientation::BOT: //grid[centerX - 1][centerY] = boats[i].getColor();
						grid[centerX - 2][centerY] = boats[i].getColorChar();
						//grid[centerX - 2][centerY - 1] = boats[i].getColor();
						//grid[centerX - 2][centerY + 1] = boats[i].getColor();
						break;
					case Boat::Orientation::RIGHT: //grid[centerX][centerY - 1] = boats[i].getColor();
						grid[centerX][centerY - 2] = boats[i].getColorChar();
						//grid[centerX + 1][centerY - 2] = boats[i].getColor();
						//grid[centerX - 1][centerY - 2] = boats[i].getColor();
						break;
					}
				}
			}
		}
	}
	int yellow = endBoard / 13824;
	int reste = endBoard % 13824;
	int blue = reste / 576;
	reste = reste % 576;
	int green = reste / 24;
	int red = reste % 24;
	//dessine la zone d'arrivé des bateaux
	for (int i = 0; i < nbBoats; i++) {
		switch (boats[i].getColorChar())
		{
		case 'R': drawBoatArrival(red, &grid[0][0], 'R');
			break;
		case 'G': drawBoatArrival(green, &grid[0][0], 'G');
			break;
		case 'B': drawBoatArrival(blue, &grid[0][0], 'B');
			break;
		case 'Y': drawBoatArrival(yellow, &grid[0][0], 'Y');
			break;
		}
	}

	//affiche la grille
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			std::cout << grid[x][y] << ' ';
		}
		std::cout << "\n";
	}

}

void Board::drawBoatArrival(int position, char* grid, char color) {
	switch (position)
	{
	case 0: grid[0 * 17 + 2] = color; grid[0 * 17 + 3] = color; grid[0 * 17 + 4] = color;
		break;
	case 1: grid[0 * 17 + 7] = color; grid[0 * 17 + 8] = color; grid[0 * 17 + 9] = color;
		break;
	case 2: grid[0 * 17 + 12] = color; grid[0 * 17 + 13] = color; grid[0 * 17 + 14] = color;
		break;
	case 3: grid[2 * 17 + 0] = color; grid[3 * 17 + 0] = color; grid[4 * 17 + 0] = color;
		break;
	case 10: grid[7 * 17 + 0] = color; grid[8 * 17 + 0] = color; grid[9 * 17 + 0] = color;
		break;
	case 17: grid[12 * 17 + 0] = color; grid[13 * 17 + 0] = color; grid[14 * 17 + 0] = color;
		break;
	case 6: grid[2 * 17 + 16] = color; grid[3 * 17 + 16] = color; grid[4 * 17 + 16] = color;
		break;
	case 13: grid[7 * 17 + 16] = color; grid[8 * 17 + 16] = color; grid[9 * 17 + 16] = color;
		break;
	case 20: grid[12 * 17 + 16] = color; grid[13 * 17 + 16] = color; grid[14 * 17 + 16] = color;
		break;
	case 21: grid[16*17 + 2] = color; grid[16 * 17 + 3] = color; grid[16 * 17 + 4] = color;
		break;
	case 22: grid[16 * 17 + 7] = color; grid[16 * 17 + 8] = color; grid[16 * 17 + 9] = color;
		break;
	case 23: grid[16 * 17 + 12] = color; grid[16 * 17 + 13] = color; grid[16 * 17 + 14] = color;
		break;
	}
}