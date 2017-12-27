#pragma once
#include <iostream>
#include "GraphicPrimitives.h"
#include "Case.h"
#include "Missile.h"
#include "Launcher.h"

class Vaisseaux
{
public:
	Vaisseaux();
	~Vaisseaux();
	Vaisseaux(int xcor_, int ycor_, int vitesse, int puissance_, int frequenceTir_, int id_, std::string typeVaisseau_, std::vector<Case *>* caseI_, std::vector<Missile*>* missiles_, std::vector<Asteroides*>* asteroides_, std::vector<Vaisseaux*>* vaisseaux_, std::vector<Launcher*>* launcher_, unsigned long start_);

	// Accesseurs
	int getXcor();
	int getYcor();
	int getVitesse();
	int getPuissance();
	int getFrequenceDeTir();
	std::vector<float> x;
	std::vector<float> y;
	int nbTicks = 0;
	// Methodes
	void draw();
	void tick();
	void spawnMissileHere();
	unsigned long getStart();
	void setStart(unsigned long start_);

private:
	int xcor;
	int ycor;
	int vitesse;
	int puissance;
	int id;
	int frequenceTir;
	float red;
	float green;
	float blue; 
	bool correspondanceVaisseau = false;
	bool partieEnCours;
	std::string typeVaisseau;
	std::vector<Case *>* caseI;
	std::vector<Missile *>* missiles;
	std::vector<Asteroides *>* asteroides;
	std::vector<Vaisseaux *>* vaisseaux;
	std::vector<Launcher *>* launcher;
	unsigned long start;

};
