#include <iostream>
#include "DessineToi.h"

DessineToi::DessineToi()
{
}

DessineToi::DessineToi(float red_, float green_, float blue_, float x_, float y_, float size_) :
	red(red_), green(green_), blue(blue_), x(x_), y(y_), size(size_)
{
	pushBack(x_, size_, x);
	pushBack(y_, size_, y);
	center();
}

DessineToi::DessineToi(float red_, float green_, float blue_) :red(red_), green(green_), blue(blue_)
{
}

float DessineToi::getRedCompo()
{
	return red;
}

float DessineToi::getGreenCompo()
{
	return green;
}

float DessineToi::getBlueCompo()
{
	return blue;
}

float DessineToi::getXcor()
{
	return xcor;
}

float DessineToi::getYcor()
{
	return ycor;
}

void DessineToi::setXcor(float xcor_)
{
	xcor = xcor_;
	x.clear();
	pushBack(xcor_, size, x);
}

void DessineToi::setYcor(float ycor_)
{
	xcor = ycor_;
	y.clear();
	pushBack(ycor_, size, y);
}

void DessineToi::modifierCouleur(float red_, float green_, float blue_)
{
	red = red_;
	green = green_;
	blue = blue_;
}

void DessineToi::pushBack(float input, float size_, std::vector<float> vector)
{
	vector.push_back(input);
	vector.push_back(input - size_);
	vector.push_back(input + size_);
}


// Complet


