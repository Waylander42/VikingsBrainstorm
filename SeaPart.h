#pragma once
class SeaPart
{
public:
	SeaPart();
	SeaPart(int);
	~SeaPart();


	int getTop() const; //Récupère la composante Top de la SeaPart
	int getBot() const; //Récupère la composante Bot de la SeaPart
	int getLeft() const; //Récupère la composante Left de la SeaPart
	int getRight() const; //Récupère la composante Right de la SeaPart

	void rotateLeft(); //Fait faire un déplacement gauche à la SeaPart
	void rotateRight(); //Fait faire un déplacement droit à la SeaPart
	void rotateHalf(); //Fait faire un demi-tour à la SeaPart

	int getIdentity() const; //Retourne l'identité de la SeaPart
	int getPosition() const; //Retourne la position de la SeaPart (0 à 8)

	void init(int); //Donne une position à la SeaPart

private :
	int identity;
	int position;
};

