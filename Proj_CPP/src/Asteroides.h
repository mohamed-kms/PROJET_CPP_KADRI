#pragma once
#include <iostream>
#include "GraphicPrimitives.h"
#include "BreedsOwn.h"
#include <string>

class Asteroides: public BreedsOwn
{
public:
	Asteroides();
	~Asteroides();
	Asteroides(int nb_vies_, int vitesse_, int nb_Lignes_, std::vector<Asteroides *>* asteroides_, int id_, unsigned long start_, float red_ = 1.0, float green_ = 1.0, float blue_ = 0.0);
	
	// Accesseurs
	int getVies();
	void setVies(int vies_);
	std::vector<Asteroides *>* getAsteroides();
	void perteDeVie();
	unsigned long getStart();
	void setStart(unsigned long start_);

	// Methodes
	void draw();
	void tick();

private:
	int nb_vies;
	float red;
	float green;
	float blue;
	std::string stringVie = std::to_string(nb_vies);
	std::vector<Asteroides *>* asteroides;
	bool collisionAvecVaisseau = false;
	unsigned long start;
};

// Complet