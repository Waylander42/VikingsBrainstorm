#pragma once
#include "SeaPart.h"

class Boat
{
public:
	enum Orientation { TOP, BOT, RIGHT, LEFT };
	static Orientation rotateRight(Orientation);
	static Orientation rotateLeft(Orientation);
	enum Color { RED, GREEN, BLUE, YELLOW };

	Boat();
	Boat(SeaPart*, Orientation, SeaPart*, Orientation, Color);
	Boat(Boat const&);
	~Boat();
	void rotate(SeaPart*, Orientation, SeaPart*, Orientation);
	SeaPart* getPart1();
	SeaPart* getPart2();
	Orientation getOrientation1();
	Orientation getOrientation2();
	void setIdentity(int);
	int getIdentity() const;
	char getColor() const;
	Boat &operator=(const Boat &);

private:
	Orientation orientation1;
	SeaPart* part1;
	Orientation orientation2;
	SeaPart* part2;
	Color color;
	int identity;
};

