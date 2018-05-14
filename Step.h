#pragma once
class Step
{
public:
	enum Rotation { RIGHT, LEFT, HALF };
	Step();
	Step(int, int, Rotation);
	~Step();
	void print() const;

private:
	int x;
	int y;
	Rotation rotation;
};

