#include <iostream>
#include "Damier.h"
#include "Case.h"

Damier::Damier()
{
}

Damier::~Damier()
{
}

Damier::Damier(int nb_ligne_, int nb_colonne_, std::vector<Damier*>* damierI_, std::vector<Case*>* caseI_):
	nb_lignes(nb_ligne_), nb_colonnes(nb_colonne_), damierI(damierI_), caseI(caseI_)
{
	for (int i = 0; i < (int)nb_colonnes; i++) {
		caseI->push_back(new Case(nb_lignes, caseI, 1.0f, 1.0f, 1.0f));
	}
}


int Damier::getNbLignes()
{
	return nb_lignes;
}

void Damier::setNbLignes(int nb_Lignes_)
{
	nb_lignes = nb_Lignes_;
}

int Damier::getNbColonnes()
{
	return nb_colonnes;
}

void Damier::setNbColonnes(int nb_Colonnes_)
{
	nb_colonnes = nb_Colonnes_;
}

void Damier::draw()
{
	for (int i = 0; i < (int)caseI->size(); i++) {
		(*caseI)[i]->draw();
	}
}



std::vector<Case*>* Damier::getCase()
{
	return caseI;
}

std::vector<Damier*>* Damier::getDamier()
{
	return damierI;
}

// Complet