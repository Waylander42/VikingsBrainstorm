#pragma once
class SeaPart
{
public:
	SeaPart();
	SeaPart(int,int);
	~SeaPart();

	int getTop() const;
	int getBot() const;
	int getLeft() const;
	int getRight() const;
	void rotateLeft();
	void rotateRight();
	void rotateHalf();
	int getIdentity() const;
	int getPosition() const;

private :
	int identity;
	int position;
};

