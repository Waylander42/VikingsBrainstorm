#include "stdafx.h"
#include <cmath> 
#include <iostream>
#include "Board.h"
#include "Constantes.h"


Board::Board()
{
	board[0][0] = SeaPart(0, 1, 1, 0);
	board[0][1] = SeaPart(0, 1, 1, 0);
	board[0][2] = SeaPart(1, 0, 1, 0);
	board[1][0] = SeaPart(0, 1, 0, 1);
	board[1][1] = SeaPart(0, 1, 1, 0);
	board[1][2] = SeaPart(0, 1, 1, 0);
	board[2][0] = SeaPart(0, 0, 1, 1);
	board[2][1] = SeaPart(0, 0, 1, 1);
	board[2][2] = SeaPart(0, 1, 0, 1);
}

Board::Board(SeaPart _board[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[j][i] = _board[j][i];
		}
	}
	
}

Board::~Board()
{
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


	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			std::cout << grid[x][y] << ' ';
		}
		std::cout << "\n";
	}
}
