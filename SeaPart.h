#pragma once
class SeaPart
{
public:
	SeaPart();
	SeaPart(int, int, int, int);
	~SeaPart();

	void rotateLeft();
	void rotateRight();
	void rotateHalf();
	int getIdentity();
	int getTop() const;
	int getBot() const;
	int getLeft() const;
	int getRight() const;

private :
	int top;
	int bot;
	int left;
	int right;
};

