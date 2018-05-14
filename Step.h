#pragma once
class Step
{
public:
	enum Rotation { RIGHT, LEFT, HALF };
	Step();
	Step(int, int, Rotation);
	~Step();
	int getX();
	int getY();
	Rotation getRotation();
	void print() const;

private:
	int x;
	int y;
	Rotation rotation;
};

