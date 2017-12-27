#include "Missile.h"

Missile::Missile()
{
}

Missile::~Missile()
{
}

Missile::Missile(float xcor_, float ycor_, int vitesse_, int puissance_, std::string typeVaisseau_, std::vector<Missile*>* missiles_, std::vector<Case*>* caseI_, std::vector<Asteroides*>* asteroides_, std::vector<Launcher*>* launcher_, int id_, unsigned long start_, float red_ = 1.0, float green_ = 0.0, float blue_ = 0.0) :
	BreedsOwn(xcor_, ycor_, vitesse_, id_, 4, 1, start_), puissance(puissance_), typeVaisseau(typeVaisseau_), missiles(missiles_), caseI(caseI_), asteroides(asteroides_), launcher(launcher_)
{
}

int Missile::getPuissance()
{
	return puissance;
}

void Missile::setPuissance(int puissance_)
{
	puissance = puissance_;
}

bool Missile::getFinDeLaPartie()
{
	return finDeLaPartie;
}

void Missile::setFinDeLaPartie(bool partieState_)
{
	finDeLaPartie = partieState_;
	(*asteroides).clear();
}

std::vector<Asteroides*>* Missile::getAsteroides()
{
	return asteroides;
}

void Missile::setAsteroides(std::vector<Asteroides*>* asteroides_)
{
	asteroides = asteroides_;
}

int Missile::getNbMissiles()
{
	return nb_missiles;
}

void Missile::setNbMissiles(int nbMissiles_)
{
	nb_missiles = nbMissiles_;
}

void Missile::draw()
{
	GraphicPrimitives::drawFillPolygone2D(x, y, 1.0, 0.0, 0.0);
	//GraphicPrimitives::drawFillRect2D(0.0, 0.0, 0.1, 0.1, 0,0,0);
}

unsigned int time;
std::string rewardsString = "";
void Missile::tick()
{	// Lancement du missile
	if ((*missiles)[0] != this) {
		for (int i = 0; i < (int)x.size(); i++) {
			x[i] += 0.0050f * getVitesse();
		}
	}

	if (asteroides->size() != 0) {		// Si on a des asteroides presents sur le damier
		for (int i = 0; i < asteroides->size(); i++) {		// Pour chaque asteroides 
			if ((*asteroides)[i]->getY() == y[0]){
				if ((*asteroides)[i]->getX() <= x[0]) {		 // Check Collision avec Asteroide de la meme ligne
					(*missiles).erase(std::find((*missiles).begin(), (*missiles).end(), this));	// swap + pop du missile
					// Affecter la vie de l'asteroide selon le type de vaisseau qui a tiré le missile
					if ((*asteroides)[i]->getVies() > 0) {
						if (typeVaisseau == "Albator") { compteurDeViesteroide = 1; }
						else if (typeVaisseau == "FreetleDjin") { compteurDeViesteroide = 2; }
						else if (typeVaisseau == "HalaMadrid") { compteurDeViesteroide = 3; }
						for (int j = 0; j < compteurDeViesteroide; j++) {
							if ((*asteroides)[i]->getVies() > 0) {
								(*asteroides)[i]->perteDeVie();
							}
						}
					}
					else {
						(*launcher)[0]->setScore((*launcher)[0]->getScore() + 10);
						(*asteroides).erase(std::find((*asteroides).begin(), (*asteroides).end(), (*asteroides)[i]));
						if (((*asteroides).size() == 0) && ((*launcher)[0]->nbAsteroides == ((*launcher)[0]->getNiveau() + 1) * 2)) {
							(*missiles)[0]->setFinDeLaPartie(true);
							(*launcher)[0]->setPartieEnCours(false);
							// Distribution de sous
							int changement = (*launcher)[0]->getNiveau();
							int rewards = (*launcher)[0]->getArgent();
							switch (changement) {
							case 0:
								(*launcher)[0]->setArgent(rewards + 25);
								rewardsString = "Niveau termine! Vous remportez 25 fCFA pour le niveau suivant !";
								break;
							case 1:
								(*launcher)[0]->setArgent(rewards + 40);
								rewardsString = "Niveau termine! Vous remportez 25 fCFA pour le niveau suivant !";
								break;
							case 2:
								(*launcher)[0]->setArgent(rewards + 50);
								rewardsString = "Niveau termine! Vous remportez 25 fCFA pour le niveau suivant !";
								break;
							case 3:
								(*launcher)[0]->setArgent(rewards + 75);
								rewardsString = "Niveau termine! Vous remportez 25 fCFA pour le niveau suivant !";
								break;
							case 4:
								(*launcher)[0]->setArgent(rewards + 150);
								rewardsString = "Niveau termine! Vous remportez 25 fCFA pour le niveau suivant !";
								break;
							}
							// Instanciation du nombre de missiles par niveau
							for (int j = 0; j < 5; j++) {
								if (j < 3) {
									nb_missiles = 25;
								}
								else {
									nb_missiles = 50;
								}
								// Acces au niveau suivant avec un certain nombre de pieces gagnées
								if (((*launcher)[0]->getArgent() + (*launcher)[0]->nb_AlbatorA * 25 + (*launcher)[0]->nb_FreetleDjinA * 50 + (*launcher)[0]->nb_HalaMadridA * 125) >= ((i * 10) + nb_missiles)) {
									std::string finNiveau = "";
									if (i > (*launcher)[0]->difference) {
										(*launcher)[0]->difference = i;
										finNiveau = "Niveau termine! Accedez au niveau suivant";
										if (!affiche) {
											(*launcher)[0]->setChangement(finNiveau);
										}
									}
								}
							}
							// Affichage de rewards
							(*launcher)[0]->setStringMsgFinDeLaPartie(rewardsString);
							(*launcher)[0]->setMsgFinDeLaPartie(true);
						}
					}
				}
			}
		}
		// Suppression des missiles hors Champs
		if (x[x.size() - 2] >= 0.5f) {
			// Time
			time = GetTickCount() - getStart();
			if (this != (*missiles)[0]) {
				(*missiles).erase(std::find((*missiles).begin(), (*missiles).end(), this));	// swap + pop du missile
			}
		}
	}
	else {
		// Suppression des missiles hors Champs
		if ((x[x.size() - 2] >= 0.5f)) {		// (x[x.size() - 2] >= 0.5f)
			// Time
			time = GetTickCount() - getStart();
			if (this != (*missiles)[0]) {
				(*missiles).erase(std::find((*missiles).begin(), (*missiles).end(), this));	// swap + pop du missile
			}
		}
	}
}

// Complet