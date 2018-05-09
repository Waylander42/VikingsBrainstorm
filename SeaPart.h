#pragma once
class SeaPart
{
public:
	SeaPart();
	SeaPart(int, int, int, int);
	~SeaPart();

	void rotateLeft();
	void rotateRight();
	int getIdentity();
	int getTop();
	int getBot();
	int getLeft();
	int getRight();

private :
	int top;
	int bot;
	int left;
	int right;
};

