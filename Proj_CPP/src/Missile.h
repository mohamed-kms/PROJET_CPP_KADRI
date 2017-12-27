#pragma once
#include <iostream>
#include "BreedsOwn.h"
#include "Asteroides.h"
#include "Case.h"
#include "Launcher.h"

class Missile: public BreedsOwn
{
public:
	Missile();
	~Missile();
	Missile(float xcor_, float ycor_, int vitesse_, int puissance_, std::string typeVaisseau_, std::vector<Missile *>* missiles_, std::vector<Case *>* caseI_, std::vector<Asteroides *>* asteroides_, std::vector<Launcher *>* launcher_, int id_, unsigned long start_, float red_, float green_, float blue_);

	// Accesseurs
	int getPuissance();
	void setPuissance(int puissance_);
	bool getFinDeLaPartie();
	void setFinDeLaPartie(bool partieState_);
	std::vector<Asteroides *>* getAsteroides();
	void setAsteroides(std::vector<Asteroides *>* asteroides_);
	int getNbMissiles();
	void setNbMissiles(int nbMissiles_);
	bool affiche = false;

	// Methodes
	void draw();
	void tick();
	int compteurDeViesteroide = 0;
private:
	int puissance;
	std::string typeVaisseau;
	std::vector<Missile *>* missiles;
	std::vector<Case *>* caseI;
	std::vector<Asteroides *>* asteroides;
	std::vector<Launcher *>* launcher;
	bool finDeLaPartie = false;
	int nb_missiles = 0;
	
};

// Complet