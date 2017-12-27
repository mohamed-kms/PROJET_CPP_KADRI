#include "Case.h"

Case::Case()
{
}

Case::~Case()
{
}

Case::Case(int nb_Lignes_, std::vector<Case*>* caseI_, float red_ = 1.0, float green_ = 1.0, float blue__ = 1.0) :
	nb_Lignes(nb_Lignes_), caseI(caseI_), red(red_), green(green_), blue(blue__)
{
	increment = 0.1f * (caseI->size() % 10);
}

int Case::getNbDeLignes()
{
	return nb_Lignes;
}

void Case::setNbDeLignes(int nb_Lignes_)
{
	nb_Lignes = nb_Lignes_;
}

int Case::getIncrement()
{
	return increment;
}

void Case::setIncrement(float increment_)
{
	increment = increment_;
}

void Case::draw()
{
	for (int i = 0; i < nb_Lignes; i++) {
		GraphicPrimitives::drawOutlinedRect2D(-0.5f + increment, -0.1f -0.2 * i, 0.1f, 0.2f, red, green, blue);
	}
}

// Complet