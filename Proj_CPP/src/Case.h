#pragma once
#include "GraphicPrimitives.h"

class Case
{
public:
	Case();
	~Case();
	Case(int nb_Lignes_, std::vector<Case *>* caseI_, float red_, float green_, float blue__);

	// Accesseurs
	int getNbDeLignes();
	void setNbDeLignes(int nbDeLignes_);
	int getIncrement();
	void setIncrement(float increment_);

	// Methodes 
	void draw();

private:
	std::vector<Case *>* caseI;
	int nb_Lignes;
	float increment;
	float red;
	float green;
	float blue;
};

// Complet