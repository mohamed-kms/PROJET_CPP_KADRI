#pragma once
#include <iostream>
#include "GraphicPrimitives.h"
#include "Case.h"

class Damier {
private:
	int nb_lignes;
	int nb_colonnes;
	std::vector<Case *>* caseI;
	std::vector<Damier *>* damierI;

public:
	Damier();
	~Damier();
	Damier(int nb_ligne_, int nb_colonne_, std::vector<Damier *>* damierI_, std::vector<Case *>* caseI_);

	// Accesseurs
	int getNbLignes();
	void setNbLignes(int nb_Lignes_);
	int getNbColonnes();
	void setNbColonnes(int nb_Colonnes_);
	std::vector<Case*>* getCase();
	std::vector<Damier *>* getDamier();

	// Methodes
	void draw();
	
	
};

// Complet