#pragma once
#include <SDL.h>
#include <string>

const int GRID_SIZE = 17;
const int NB_SEAPART = 9;
const int NB_MODEJEU = 2;
const int NB_ALGO = 3;
const std::string ALGOS[NB_ALGO] = { "Parcours en largeur", "Parcours en largeur trie", "Arbre binaire rouge noir" };
const int UI = 1; //1 = UI, 0 = Console 

const int SCREEN_WIDTH = 730;
const int SCREEN_HEIGHT = 830;

