#pragma once
#include <iostream>
#include <vector>

class DessineToi
{
public:
	DessineToi();
	virtual ~DessineToi() {};
	DessineToi(float red_, float green_, float blue_, float x_, float y_, float size_);
	DessineToi(float red_, float green_, float blue_);
	// Accesseurs
	float getRedCompo();
	float getGreenCompo();
	float getBlueCompo();
	float getXcor();
	float getYcor();

	void setXcor(float xcor_);
	void setYcor(float ycor_);
	virtual void setRedCompo(float red_) {};
	virtual void setGreenCompo(float green_) {};
	virtual void setBlueCompo(float blue_) {};
	virtual void setX(float x_) {};
	virtual void setY(float y_) {};
	virtual float getX() { return 0.0; };
	virtual float getY() { return 0.0; };
	void modifierCouleur(float red_, float green_, float blue_);

	///**********************///////
	virtual void setLabel(char* value) {};
	///**********************///////


	// Methodes
	virtual void draw() {};
	virtual void translate(float x_, float y_) {};
	virtual void rotate(float degre) {};
	virtual void center() {};
	void pushBack(float input, float size_, std::vector<float> vector);
protected:
	float red;
	float green;
	float blue;
	float xcor;
	float ycor;
	std::vector<float> x;
	std::vector<float> y;
	float size;

	// Complet
};
