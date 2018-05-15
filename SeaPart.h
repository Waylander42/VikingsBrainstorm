#pragma once
class SeaPart
{
public:
	SeaPart();
	SeaPart(int);
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
	int identity;
};

