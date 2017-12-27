#include "Asteroides.h"

Asteroides::Asteroides()
{
}

Asteroides::~Asteroides()
{
}

Asteroides::Asteroides(int nb_vies_, int vitesse_, int nb_Lignes_, std::vector<Asteroides*>* asteroides_, int id_, unsigned long start_, float red_, float green_, float blue_):
	BreedsOwn(-0.8f + 0.1 * 11, 0.0f -0.2f * (rand() % static_cast<int>(nb_Lignes_)), vitesse_, id_, nb_Lignes_, 2, start_), nb_vies(nb_vies_), asteroides(asteroides_), red(red_), green(green_), blue(blue_), start(start_)
{
}

int Asteroides::getVies()
{
	return nb_vies;
}

void Asteroides::setVies(int vies_)
{
	nb_vies = vies_;
}

std::vector<Asteroides*>* Asteroides::getAsteroides()
{
	return asteroides;
}

void Asteroides::perteDeVie()
{
	nb_vies--;
	stringVie = std::to_string(nb_vies);
}

unsigned long Asteroides::getStart()
{
	return start;
}


void Asteroides::setStart(unsigned long start_)
{
	start = start_;
}

void Asteroides::draw()
{
	GraphicPrimitives::drawFillPolygone2D(x, y, red, green, blue);
}

void Asteroides::tick()
{
	// Avant la collision avec un vaisseau, on continue a avancer jusqu'à atteindre la fin du damier
	if (!collisionAvecVaisseau) {
		// Si on y est pas encore, on avance
		if (x[0] > -0.5f) {
			for (int i = 0; i < (int)x.size(); i++) {
				x[i] -= 0.00025f;
			}
		}
		else {		// Asteroides hors champs
			(*asteroides).erase(std::find((*asteroides).begin(), (*asteroides).end(), this));
		}
	}
	else {		// On est rentré en collision avec un vaisseau, alors swap + pop
		(*asteroides).erase(std::find((*asteroides).begin(), (*asteroides).end(), this));
	}
}
