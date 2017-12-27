#include "BreedsOwn.h"

BreedsOwn::BreedsOwn()
{
}

BreedsOwn::~BreedsOwn()
{
}

BreedsOwn::BreedsOwn(float xcor_, float ycor_, int vitesse_, int id_, int cote_, int size_ = 1, unsigned long start_ = 1):
	xcor(xcor_), ycor(ycor_), vitesse(vitesse_ / 2), id(id_), start(start_)
{
	float xcor_tmp, xcor_tmp2, xcor_tmp3;
	x.push_back(xcor);
	xcor_tmp = xcor + 0.01f * size_;
	xcor_tmp2 = xcor_tmp;
	x.push_back(xcor_tmp);
	xcor_tmp = xcor_tmp + 0.03 * size_;
	xcor_tmp3 = xcor_tmp;
	x.push_back(xcor_tmp);
	xcor_tmp = xcor_tmp + 0.05 * size_;
	x.push_back(xcor_tmp);	
	x.push_back(xcor_tmp3);
	x.push_back(xcor_tmp2);

	float ycor_tmp;
	y.push_back(ycor);
	ycor_tmp = ycor + 0.025f * size_;
	y.push_back(ycor_tmp);
	y.push_back(ycor_tmp);
	y.push_back(ycor);
	ycor_tmp = ycor - 0.025f * size_;
	y.push_back(ycor_tmp);
	y.push_back(ycor_tmp);
}

float BreedsOwn::getX()
{
	return x[0];
}

void BreedsOwn::setX(float xcor_)
{
	x[0] = xcor_;
}

float BreedsOwn::getY()
{
	return y[0];
}

void BreedsOwn::setY(float ycor_)
{
	y[0] = ycor_;
}

int BreedsOwn::getVitesse()
{
	return vitesse;
}

void BreedsOwn::setVitesse(int vitesse_)
{
	vitesse = vitesse_;
}

unsigned long BreedsOwn::getStart()
{
	return start;
}

void BreedsOwn::getStart(unsigned long start_)
{
	start = start_;
}

int BreedsOwn::getID()
{
	return id;
}

void BreedsOwn::pushBack(float input, float size_, std::vector<float> vector)
{
	vector.push_back(input);
	vector.push_back(input - size_);
	vector.push_back(input + size_);
}

// Complet