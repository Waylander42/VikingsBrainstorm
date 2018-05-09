#pragma once
#include "SeaPart.h"

class Boat
{
public:
	enum Orientation { TOP, BOT, RIGHT, LEFT };

	Boat();
	Boat(SeaPart*, Orientation, SeaPart*, Orientation);
	~Boat();
	void rotate(SeaPart*, Orientation, SeaPart*, Orientation);
	SeaPart* getPart1();
	SeaPart* getPart2();
	Orientation getOrientation1();
	Orientation getOrientation2();

private:
	Orientation orientation1;
	SeaPart* part1;
	Orientation orientation2;
	SeaPart* part2;
};

