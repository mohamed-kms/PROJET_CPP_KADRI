#pragma once
#include <iostream>
#include "GraphicPrimitives.h"

class BreedsOwn
{
public:
	BreedsOwn();
	~BreedsOwn();
	void pushBack(float input, float size_, std::vector<float> vector);
	BreedsOwn(float xcor_, float ycor_, int vitesse_, int id_, int cote_, int size_, unsigned long start_);

	// Accesseurs
	float getX();
	void setX(float xcor_);
	float getY();
	void setY(float ycor_);
	int getVitesse();
	void setVitesse(int vitesse_);
	unsigned long getStart();
	void getStart(unsigned long start_);
	int getID();
	std::vector<float> x;
	std::vector<float> y;

private:
	float xcor;
	float ycor;
	int vitesse;
	unsigned long start;
	int id;
};

// Complet
