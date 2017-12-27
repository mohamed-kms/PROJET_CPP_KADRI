#include "Vaisseaux.h"

Vaisseaux::Vaisseaux()
{
}

Vaisseaux::~Vaisseaux()
{
}

Vaisseaux::Vaisseaux(int xcor_, int ycor_, int vitesse_, int puissance_, int frequenceTir_, int id_, std::string typeVaisseau_, std::vector<Case*>* caseI_, std::vector<Missile*>* missiles_, std::vector<Asteroides*>* asteroides_, std::vector<Vaisseaux*>* vaisseaux_, std::vector<Launcher*>* launcher_, unsigned long start_) :
	xcor(xcor_), ycor(ycor_), vitesse(vitesse_), puissance(puissance_), frequenceTir(frequenceTir_), id(id_), typeVaisseau(typeVaisseau_), caseI(caseI_), missiles(missiles_), launcher(launcher_), asteroides(asteroides_), vaisseaux(vaisseaux_), start(start_)
{
	float x_tmp = -0.5f + 0.1f * xcor_;
	float y_tmp = -0.1f - 0.2f * ycor_;
	x.push_back(x_tmp);
	y.push_back(y_tmp);
	x_tmp = x_tmp + 0.1f;
	y_tmp += 0.1f;
	x.push_back(x_tmp);
	y.push_back(y_tmp);
	x_tmp = -0.5f + 0.1f * xcor_;
	y_tmp = -0.1f - 0.2f * ycor_ + 0.2;
	x.push_back(x_tmp);
	y.push_back(y_tmp);
}

int Vaisseaux::getXcor()
{
	return xcor;
}

int Vaisseaux::getYcor()
{
	return ycor;
}

int Vaisseaux::getVitesse()
{
	return vitesse;
}

int Vaisseaux::getPuissance()
{
	return puissance;
}

int Vaisseaux::getFrequenceDeTir()
{
	return frequenceTir;
}

bool ouaisCbon = true;
void Vaisseaux::draw()
{
	if (typeVaisseau == "Albator") {
		GraphicPrimitives::drawFillTriangle2D(x[0], y[0], x[1], y[1], x[2], y[2], 0,0,1);
	}
	else if (typeVaisseau == "HalaMadrid") {
		GraphicPrimitives::drawFillTriangle2D(x[0], y[0], x[1], y[1], x[2], y[2], 1, 1, 1);
	}
	else
	{
		GraphicPrimitives::drawFillTriangle2D(x[0], y[0], x[1], y[1], x[2], y[2], 1,0,0);
	}
}

void Vaisseaux::tick()
{
	// Creation des asteroides
	if ((*launcher)[0]->getAsteroidesCree()) {
		if (((*launcher)[0]->getNiveau() <= 2) && (ouaisCbon)) {
			asteroides->push_back(new Asteroides(5, 2, (*caseI)[0]->getNbDeLignes(), asteroides, asteroides->size(), 1, 1, 1, 1));
			//(*asteroides)[0]->setStart(1);
			(*launcher)[0]->nbAsteroides++;
			ouaisCbon = false;
		}
		if ((nbTicks % 1000 == 0) && ((*launcher)[0]->nbAsteroides < 5)){//(((*launcher)[0]->getNiveau() + 1) * 2))) {
			asteroides->push_back(new Asteroides(5, 2, (*caseI)[0]->getNbDeLignes(), asteroides, asteroides->size(), 1, 1, 1, 1));
			//(*asteroides)[0]->setStart(1);
			(*launcher)[0]->nbAsteroides++;
		}
	}
	nbTicks++;
	if ((*launcher)[0]->getPartieEnCours()) {
		if (nbTicks % (1500 / frequenceTir) == 0) {
			spawnMissileHere();
		}
	}
	for (int i = 0; i < asteroides->size(); i++) {
		if (y[1] == (*asteroides)[i]->getY()) {
			if (x[1] > (*asteroides)[i]->getX()) {
				(*missiles)[0]->setFinDeLaPartie(true);
				(*launcher)[0]->setStringMsgFinDeLaPartie("Game Over!");
				(*launcher)[0]->setMsgFinDeLaPartie(true);
			}
		}
	}
	if ((*missiles)[0]->getFinDeLaPartie()) {
		(*vaisseaux).clear();
		(*launcher)[0]->setPartieEnCours(false);
		(*missiles)[0]->setFinDeLaPartie(false);
	}
}

void Vaisseaux::spawnMissileHere()
{
	missiles->push_back(new Missile(x[0] + 0.1f, y[0] + 0.1f, vitesse, puissance, typeVaisseau, missiles, caseI, asteroides, launcher, missiles->size(), start, 1.0, 0.0, 0.0));
}

unsigned long Vaisseaux::getStart()
{
	return start;
}

void Vaisseaux::setStart(unsigned long start_)
{
	start = start_;
}

// Complet;