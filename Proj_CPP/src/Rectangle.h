#pragma once
#include <iostream>
#include "DessineToi.h"
#include "GraphicPrimitives.h"

class Rrectangle : public DessineToi
{
public:
	Rrectangle();
	~Rrectangle();
	Rrectangle(float red_, float green_, float blue_, float x_, float y_, float width_, float height_);

	// Accesseurs
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	void setX(float x_);
	void setY(float y_);
	void setWidth(float width_);
	void setHeight(float height_);
	void setRedCompo(float red_);
	void setGreenCompo(float green_);
	void setBlueCompo(float blue_);

	// Methodes
	void draw();
	void translate(float x_, float y_);
	void dessinerLigne(float red_, float green_, float blue_);
	void setBrillance(bool brillance_);

	// Complet


private:
	float x;
	float y;
	float width;
	float height;
	bool brillance;
};
