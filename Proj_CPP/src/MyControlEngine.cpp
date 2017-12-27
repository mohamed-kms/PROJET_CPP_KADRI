#include "MyControlEngine.h"
#include "MyGameEngine.h"

int nombreDeMissiles = 0;

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	width = glutGet(GLUT_WINDOW_WIDTH) / 2;
	height = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	mouseXcor = ((x - width) / (float)width);
	mouseYcor = ((y - height) / (float)height);

	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		(*launcher)[0]->setMsgFinDeLaPartie(false);
		// Gestion Niveau: derouler selection Niveau
		if (((mouseXcor < 0.55f) || (mouseXcor > 0.75f)) || ((mouseYcor > -0.75f) || (mouseYcor < -0.35f))) {
			(*launcher)[0]->setDeroulerNiveau(false);
		}

		// Choix du Niveau
		if ((mouseXcor < 0.75f) && (mouseXcor > 0.55f) && (mouseYcor > -0.35f) && (mouseYcor < 0.24f)) {
			(*launcher)[0]->setDeroulerNiveau(!((*launcher)[0]->getDeroulerNiveau()));
		}
		for (int i = 0; i < 5; i++) {
			if (i < 3) {
				nombreDeMissiles = 25;
			}
			else
			{
				nombreDeMissiles = 50;
			}
			if ((((mouseXcor < 0.75f) && (mouseXcor > 0.55f) && (mouseYcor < -0.15f + 0.07f * i) && (mouseYcor > -0.25f + 0.07f * i)) && ((*launcher)[0]->getDeroulerNiveau())) && (((*launcher)[0]->getArgent() + (*launcher)[0]->nb_AlbatorA * 25 + (*launcher)[0]->nb_FreetleDjinA * 50 + (*launcher)[0]->nb_HalaMadridA * 125) >= ((i * 10) + nombreDeMissiles))) {
				(*vaisseaux).clear();
				(*asteroides).clear();
				(*launcher)[0]->setPartieEnCours(false);
				(*launcher)[0]->resetNiveauChoisi();
				(*launcher)[0]->setNiveauChoisi(i, true);
				for (int j = 0; j < 10; j++) {
					(*damier)[0]->setNbLignes((*launcher)[0]->getNiveau() + 1);
					(*caseI)[j]->setNbDeLignes((*launcher)[0]->getNiveau() + 1);
				}
			}
		}

		{

		}
		// Gestion Disponibilite Vaisseaux
		if ((mouseXcor < -0.5f) || (mouseXcor > -0.1f * (*damier)[0]->getNbColonnes()) || (mouseYcor < 0.1f) || (mouseYcor <= 0.1 * (*damier)[0]->getNbLignes())) {
			(*launcher)[0]->setPlusDeVaisseaux(false);
		}

		// Gestion de la boutique
		// Achat Albator
		if ((mouseXcor > -0.96f) && (mouseXcor < -0.92f) && (mouseYcor < -0.35f) && (mouseYcor > -0.38f)) {
			if ((*launcher)[0]->nb_AlbatorA > 0) {
				(*launcher)[0]->nb_AlbatorA--;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() + 25);
			}
		}
		else if ((mouseXcor > -0.85f) && (mouseXcor < -0.82f) && (mouseYcor < -0.35f) && (mouseYcor > -0.38f)) {
			if ((*launcher)[0]->getArgent() >= 25) {
				(*launcher)[0]->nb_AlbatorA++;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() - 25);
			}
		}


		// Achat FreetleDjin
		if ((mouseXcor > -0.96f) && (mouseXcor < -0.92f) && (mouseYcor < 0.0f) && (mouseYcor > -0.03f)) {
			if ((*launcher)[0]->nb_FreetleDjinA > 0) {
				(*launcher)[0]->nb_FreetleDjinA--;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() + 50);
			}
		}
		else if ((mouseXcor > -0.85f) && (mouseXcor < -0.82f) && (mouseYcor < 0.0f) && (mouseYcor > -0.03f)) {
			if ((*launcher)[0]->getArgent() >= 50) {
				(*launcher)[0]->nb_FreetleDjinA++;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() - 50);
			}
		}

		// Achat Hala Madrid
		if ((mouseXcor > -0.96f) && (mouseXcor < -0.92f) && (mouseYcor < 0.35f) && (mouseYcor > 0.32f)) {
			if ((*launcher)[0]->nb_HalaMadridA > 0) {
				(*launcher)[0]->nb_HalaMadridA--;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() + 125);
			}
		}
		else if ((mouseXcor > -0.85f) && (mouseXcor < -0.82f) && (mouseYcor < 0.35f) && (mouseYcor > 0.32f)) {
			if ((*launcher)[0]->getArgent() >= 125) {
				(*launcher)[0]->nb_HalaMadridA++;
				(*launcher)[0]->setArgent((*launcher)[0]->getArgent() - 125);
			}
		}

		// Choix Vaisseau
		if ((mouseXcor >= -0.5f) && (mouseXcor <= -0.4f) && (mouseYcor >= -0.65f) && (mouseYcor <= -0.45f)) {
			if (!isAlbator) {
				lockAlbator(true);
				lockFreetleDjin(false);
				lockHalaMadrid(false);
			}
			else {
				(*launcher)[0]->setIsAlbator(false); isAlbator = false;
			}
		}

		if ((mouseXcor >= -0.3f) && (mouseXcor <= -0.2f) && (mouseYcor >= -0.65f) && (mouseYcor <= -0.45f)) {
			if (!isFreetleDjin) {
				lockAlbator(false);
				lockFreetleDjin(true);
				lockHalaMadrid(false);
			}
			else {
				(*launcher)[0]->setIsFreetleDjin(false); isFreetleDjin = false;
			}
		}

		if ((mouseXcor >= -0.1f) && (mouseXcor <= 0.0f) && (mouseYcor >= -0.65f) && (mouseYcor <= -0.45f)) {
			if (!isHalaMadrid) {
				lockAlbator(false);
				lockFreetleDjin(false);
				lockHalaMadrid(true);
			}
			else {
				(*launcher)[0]->setIsHalaMadrid(false); isHalaMadrid = false;
			}
		}

		// Pose sur le Damier
		for (int i = 0; i < (*damier)[0]->getNbColonnes(); i++) {
			for (int j = 0; j < (*damier)[0]->getNbLignes(); j++) {
				if ((mouseXcor >= -0.5f + 0.1f * i) && (mouseXcor <= -0.4f + 0.1f*i) && (mouseYcor >= -0.1f + 0.2f *j) && (mouseYcor <= 0.1f + 0.2f *j)) {
					float xB = -0.7f + 0.1f * i; float xH = -0.6f + 0.1f * i;
					float yB = -0.1f - 0.2f * j; float yH = 0.1f - 0.2f * j;
					// Checker si la partie est lancée ou pas et s'il n'y a pas deja de vaisseau sur notre case
					if ((!(*launcher)[0]->getPartieEnCours()) && (!(*launcher)[0]->vaisseauSurLaCase[i][j])) {
						// Checker disponibilité du vaisseau
						if (((*launcher)[0]->nb_AlbatorA > 0) && ((*launcher)[0]->nb_AlbatorA > (*launcher)[0]->nb_AlbatorP) && isAlbator) {
							vaisseaux->push_back(new Vaisseaux(i, j, 10, 1, 5, vaisseaux->size(), "Albator", caseI, missiles, asteroides, vaisseaux, launcher, start));
							(*vaisseaux)[0]->setStart(start);
							(*launcher)[0]->nb_AlbatorP++;
							(*launcher)[0]->ligneOccupee[j] = true;
							(*launcher)[0]->vaisseauSurLaCase[i][j] = true;
						}
						else if (((*launcher)[0]->nb_FreetleDjinA > 0) && ((*launcher)[0]->nb_FreetleDjinA > (*launcher)[0]->nb_FreetleDjinP) && isFreetleDjin) {
							vaisseaux->push_back(new Vaisseaux(i, j, 12, 3, 6, vaisseaux->size(), "FreetleDjin", caseI, missiles, asteroides, vaisseaux, launcher, start));
							(*vaisseaux)[0]->setStart(start);
							(*launcher)[0]->nb_FreetleDjinP++;
							(*launcher)[0]->ligneOccupee[j] = true;
							(*launcher)[0]->vaisseauSurLaCase[i][j] = true;
						}
						else if (((*launcher)[0]->nb_HalaMadridA > 0) && ((*launcher)[0]->nb_HalaMadridA > (*launcher)[0]->nb_HalaMadridP) && isHalaMadrid) {
							vaisseaux->push_back(new Vaisseaux(i, j, 15, 5, 8, vaisseaux->size(), "HalaMadrid", caseI, missiles, asteroides, vaisseaux, launcher, start));
							(*vaisseaux)[0]->setStart(start);
							(*launcher)[0]->nb_HalaMadridP++;
							(*launcher)[0]->ligneOccupee[j] = true;
							(*launcher)[0]->vaisseauSurLaCase[i][j] = true;
						}	// S'il n'a plus de vaisseau d'un type
						else if (!isAlbator && !isFreetleDjin && !isHalaMadrid) {
							(*launcher)[0]->setStringPlusDeVaisseaux("Selectionnez un vaisseau a poser");
							(*launcher)[0]->setPlusDeVaisseaux(true);
						}	// S'il n'a plus le vaisseau qu'il a selectionné
						else if (((*launcher)[0]->nb_AlbatorA == (*launcher)[0]->nb_AlbatorP && isAlbator) || ((*launcher)[0]->nb_FreetleDjinA == (*launcher)[0]->nb_FreetleDjinP && isFreetleDjin) || ((*launcher)[0]->nb_HalaMadridA == (*launcher)[0]->nb_HalaMadridP && isHalaMadrid)) {
							(*launcher)[0]->setStringPlusDeVaisseaux("Rendez-vous a la boutique pour vous approvisionner en vaisseaux");
							(*launcher)[0]->setPlusDeVaisseaux(true);
						}	// Retirer un vaisseau deja sur une case
					}
					else if ((*launcher)[0]->vaisseauSurLaCase[i][j]) {
						//
					}
				}
			}
		}

		// Lancer la partie
		if ((mouseXcor >= 0.0f) && (mouseXcor <= 0.2f) && (mouseYcor >= -0.4f) && (mouseYcor <= -0.25f)) {
			bool okCbon = (*launcher)[0]->getPartieEnCours();
			if ((!okCbon) && (((*launcher)[0]->nb_AlbatorP != 0) || ((*launcher)[0]->nb_FreetleDjinP != 0) || ((*launcher)[0]->nb_HalaMadridP != 0))) {
				(*launcher)[0]->setPartieEnCours(!okCbon);
			}
			else if (okCbon) {
				(*launcher)[0]->setPartieEnCours(!okCbon);
				(*missiles)[0]->setFinDeLaPartie(true);
				for (int i = 0; i < (*asteroides).size(); i++) {
					(*asteroides).erase(std::find((*asteroides).begin(), (*asteroides).end(), (*asteroides)[i]));
				}
			}
		}
	}
}

void MyControlEngine::lockAlbator(bool lock_)
{
	if (!lock_) {
		isAlbator = false;
		(*launcher)[0]->setIsAlbator(false);
	}
	else {
		isAlbator = true;
		(*launcher)[0]->setIsAlbator(true);
	}
}
void MyControlEngine::lockFreetleDjin(bool lock_)
{
	if (!lock_) {
		isFreetleDjin = false;
		(*launcher)[0]->setIsFreetleDjin(false);
	}
	else {
		isFreetleDjin = true;
		(*launcher)[0]->setIsFreetleDjin(true);
	}
}
void MyControlEngine::lockHalaMadrid(bool lock_)
{
	if (!lock_) {
		isHalaMadrid = false;
		(*launcher)[0]->setIsHalaMadrid(false);
	}
	else {
		isHalaMadrid = true;
		(*launcher)[0]->setIsHalaMadrid(true);
	}
}