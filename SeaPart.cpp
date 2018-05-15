#include "stdafx.h"
#include "SeaPart.h"

SeaPart::SeaPart(int _identity, int _position):identity(_identity), position(_position)
{
}

SeaPart::SeaPart() :SeaPart(0)
{
}

SeaPart::~SeaPart()
{
}

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

void SeaPart::rotateHalf() {
	if (identity < 4) {
		identity = (identity + 2) % 4;
	}
}

int SeaPart::getIdentity() const{
	return identity;
}

int SeaPart::getPosition() const{
	return position;
}