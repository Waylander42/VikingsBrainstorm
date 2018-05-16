#include "stdafx.h"
#include "SeaPart.h"

SeaPart::SeaPart(int _identity):identity(_identity), position(0)
{
}

SeaPart::SeaPart() :SeaPart(0)
{
}

SeaPart::~SeaPart()
{
}

//Récupère la composante Top de la SeaPart
int SeaPart::getTop() const{
	int top = -1;
	switch (identity) {
	case 0: top = 0;
		break;
	case 1: top = 1;
		break;
	case 2: top = 1;
		break;
	case 3: top = 0;
		break;
	case 4: top = 0;
		break;
	case 5: top = 1;
		break;
	}
	return top;
}

//Récupère la composante Bot de la SeaPart
int SeaPart::getBot() const{
	int bot = -1;
	switch (identity) {
	case 0: bot = 1;
		break;
	case 1: bot = 0;
		break;
	case 2: bot = 0;
		break;
	case 3: bot = 1;
		break;
	case 4: bot = 0;
		break;
	case 5: bot = 1;
		break;
	}
	return bot;
}

//Récupère la composante Left de la SeaPart
int SeaPart::getLeft() const{
	int left = -1;
	switch (identity) {
	case 0: left = 1;
		break;
	case 1: left = 1;
		break;
	case 2: left = 0;
		break;
	case 3: left = 0;
		break;
	case 4: left = 1;
		break;
	case 5: left = 0;
		break;
	}
	return left;
}

//Récupère la composante Right de la SeaPart
int SeaPart::getRight() const{
	int right = -1;
	switch (identity) {
	case 0: right = 0;
		break;
	case 1: right = 0;
		break;
	case 2: right = 1;
		break;
	case 3: right = 1;
		break;
	case 4: right = 1;
		break;
	case 5: right = 0;
		break;
	}
	return right;
}

//Fait faire un déplacement droite à la SeaPart
void SeaPart::rotateRight() {
	if (identity < 4) {
		identity = (identity + 1) % 4;
	}
	else if (identity == 4) {
		identity = 5;
	}
	else {
		identity = 4;
	}
}

//Fait faire un déplacement gauche à la SeaPart
void SeaPart::rotateLeft() {
	if (identity < 4) {
		identity = (identity + 3) % 4;
	}
	else if (identity == 4) {
		identity = 5;
	}
	else {
		identity = 4;
	}
}

//Fait faire un demi-tour à la SeaPart
void SeaPart::rotateHalf() {
	if (identity < 4) {
		identity = (identity + 2) % 4;
	}
}

//Retourne l'identité de la SeaPart
int SeaPart::getIdentity() const{
	return identity;
}

//Retourne la position de la SeaPart
int SeaPart::getPosition() const{
	return position;
}

//Donne une position à la SeaPart
void SeaPart::init(int _position) {
	position = _position;
}