#include <iostream>
#include "Rectangle.h"

Rrectangle::Rrectangle()
{
}

Rrectangle::~Rrectangle()
{
}

Rrectangle::Rrectangle(float red_, float green_, float blue_, float x_, float y_, float width_, float height_) :
	DessineToi(red_, green_, blue_), x(x_), y(y_), width(width_), height(height_)
{
}

float Rrectangle::getX()
{
	return x;
}

float Rrectangle::getY()
{
	return y;
}

float Rrectangle::getWidth()
{
	return width;
}

float Rrectangle::getHeight()
{
	return width;
}

void Rrectangle::setX(float x_)
{
	x = x_;
}

void Rrectangle::setY(float y_)
{
	y = y_;
}

void Rrectangle::setWidth(float width_)
{
	width = width_;
}

void Rrectangle::setHeight(float height_)
{
	height = height_;
}

void Rrectangle::setRedCompo(float red_)
{
	(*this).red = red_;
}

void Rrectangle::setGreenCompo(float green_)
{
	(*this).green = green_;
}

void Rrectangle::setBlueCompo(float blue_)
{
	(*this).blue = blue_;
}

void Rrectangle::draw()
{
	GraphicPrimitives::drawFillRect2D(x, y, width, height, red, green, blue);
}

void Rrectangle::translate(float x_, float y_)
{
	x += x_;
	y += y_;
}

void Rrectangle::dessinerLigne(float red_, float green_, float blue_)
{
	GraphicPrimitives::drawFillRect2D(x, y, width, height, red_, green_, blue_);
	float tmp_x = x + (width - (width - (width * 20) / 100)) / 2;
	float tmp_y = y + (height - (height - (height * 20) / 100)) / 2;
	GraphicPrimitives::drawFillRect2D(tmp_x, tmp_y, (width - (width * 20) / 100), (height - (height * 20) / 100), red_, green_, blue_);
}

void Rrectangle::setBrillance(bool brillance_)
{
	brillance = brillance_;
}

// Complet
