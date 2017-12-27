#include "Launcher.h"

Launcher::Launcher():partieEnCours(false), argent(75)
{
	resetVaisseauSurCase();
	resetNiveauChoisi();
}

Launcher::~Launcher()
{
}

int Launcher::getNiveau()
{
	return niveau;
}

void Launcher::setNiveau(int niveau_)
{
	niveau = niveau_;
}

int Launcher::getArgent()
{
	return argent;
}

void Launcher::setArgent(int argent_)
{
	argent = argent_;
}

int Launcher::getScore()
{
	return score;
}

void Launcher::setScore(int score_)
{
	score = score_;
}

bool Launcher::getPartieEnCours()
{
	return partieEnCours;
}

void Launcher::setPartieEnCours(bool partieState_)
{
	partieEnCours = partieState_;
	if (partieEnCours) {
		partieState = "En Cours..."; 
		setLancementAsteroides(true); 
		setAsteroidesCree(true);
		score = 0; setChangement("");
	}
	else {
		partieState = "START"; resetNiveauChoisi(); resetVaisseauSurCase();
		nb_AlbatorP = 0; nb_FreetleDjinP = 0; nb_HalaMadridP = 0;
		nbAsteroides = 0; setAsteroidesCree(false);
	}
}

bool Launcher::getLancementAsteroides()
{
	return lancementAsteroides;
}

void Launcher::setLancementAsteroides(bool lancer_)
{
	lancementAsteroides = lancer_;
}

bool Launcher::getDeroulerNiveau()
{
	return deroulerNiveau;
}

void Launcher::setDeroulerNiveau(bool derouler_)
{
	deroulerNiveau = derouler_;
}

bool * Launcher::getNiveauChoisi()
{
	return niveauChoisi;
}

void Launcher::setNiveauChoisi(int i, bool niveau_)
{
	niveauChoisi[i] = niveau;
	niveau = i;
}
bool Launcher::getIsAlbator()
{
	return isAlbator;
}
void Launcher::setIsAlbator(bool isAlbator_)
{
	isAlbator = isAlbator_;
}
bool Launcher::getIsFreetleDjin()
{
	return isFreetleDjin;
}
void Launcher::setIsFreetleDjin(bool isFreetleDjin_)
{
	isFreetleDjin = isFreetleDjin_;
}
bool Launcher::getIsHalaMadrid()
{
	return isHalaMadrid;
}
void Launcher::setIsHalaMadrid(bool isHalaMadrid_)
{
	isHalaMadrid = isHalaMadrid_;
}
bool Launcher::getAsteroidesCree()
{
	return asteroidesCree;
}
void Launcher::setAsteroidesCree(bool ast_)
{
	asteroidesCree = ast_;
}
std::string Launcher::getChangement()
{
	return changement;
}
void Launcher::setChangement(std::string change_)
{
	changement = change_;
}
bool Launcher::getMsgFinDeLaPartie()
{
	return msgFinDeLaPartie;
}
void Launcher::setMsgFinDeLaPartie(bool msg_)
{
	msgFinDeLaPartie = msg_;
}
std::string Launcher::getStringMsgFinDeLaPartie()
{
	return stringMsgFinDeLaPartie;
}

void Launcher::setStringMsgFinDeLaPartie(std::string string_)
{
	stringMsgFinDeLaPartie = string_;
}

bool Launcher::getPlusDeVaisseaux()
{
	return plusDeVaisseaux;
}

void Launcher::setPlusDeVaisseaux(bool v_)
{
	plusDeVaisseaux = v_;
}

std::string Launcher::getStringPlusDeVaisseaux()
{
	return stringPlusDeVaisseaux;
}

std::string Launcher::setStringPlusDeVaisseaux(std::string string_)
{
	return stringPlusDeVaisseaux = string_;
}


int nbm2 = 0;
void Launcher::draw()
{
	char * boutique = new char[8];
	boutique = _strdup("Boutique");
	//boutique { 'B', 'o', 'u', 't', 'i', 'q', 'u', 'e', '\0' };
	GraphicPrimitives::drawText2D(boutique, -0.9f, 0.7f, 1.0, 0.0, 0.0);

	// START
	char * start = new char[8];
	start = _strdup("Start");
	GraphicPrimitives::drawFillRect2D(0.0f, 0.25f, 0.2f, 0.150f, 0.5, 0.5, 0.5);
	GraphicPrimitives::drawText2D(start, 0.05f, 0.30f, 0, 0.5, 0.5);

	//Menu de Bienvenu
	char * Bienvenu = new char[250];
	Bienvenu = _strdup("Hey! Bienvenu dans le jeux Vaisseaux VS. Asteroides. Rendez vous dans la boutique pour acheter des vaisseaux");
	GraphicPrimitives::drawText2D(Bienvenu, -0.5, 0.95, 1, 1, 0);
	Bienvenu = _strdup("Apres avoir achete des vaisseaux, choissisez votre niveau, placez vos vaisseaux, et sauvez la planette de cette invasion");
	GraphicPrimitives::drawText2D(Bienvenu, -0.5, 0.90, 1, 1, 0);
	Bienvenu = _strdup("Attention! nous avons un budget a respecter");
	GraphicPrimitives::drawText2D(Bienvenu, 0.0, 0.85, 1, 0, 0);
	// Choix du Niveau
	char * Difficulte = new char[7];
	Difficulte = _strdup("Niveau");
	GraphicPrimitives::drawOutlinedRect2D(0.55f, 0.25f, 0.2f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(Difficulte, 0.60f, 0.269f, 1.0f, 1.0f, 1.0f, 1.0f);
	if (deroulerNiveau) {
		for (int i = 0; i < 5; i++) {
			if (i < 3) { nbm2 = 25; }
			else if (i >= 3) { nbm2 = 50; }
			else {nbm2 = 50;}
			if ((argent + nb_AlbatorA * 25 + nb_FreetleDjinA * 50 + nb_HalaMadridA * 125) >= ((i * 10) + nbm2)) {
				GraphicPrimitives::drawOutlinedRect2D(0.55f, 0.15f - 0.07f * i, 0.2f, 0.07f, 1, 1, 1);
				GraphicPrimitives::drawText2D((char*)std::to_string(i).c_str(), 0.675f, 0.165f - 0.07f * i, 1, 1, 1);
				if (niveauChoisi[i]) {
					niveau = i;
					GraphicPrimitives::drawFillRect2D(0.55f, 0.15f - 0.07f * i, 0.2f, 0.07f, 1, 1, 1);
					GraphicPrimitives::drawText2D((char*)std::to_string(i).c_str(), 0.675f, 0.165f - 0.07f * i, 0, 0, 0);
				}
			}
		}
	}

	// Affichage Du SCORE ET DU MEILLEUR SCORE
	char * Score = new char[7];
	Score = _strdup("Score: ");
	GraphicPrimitives::drawText2D(Score, -0.5f, 0.70f, 0.5f, 0.5f, 1.0f);
	GraphicPrimitives::drawText2D((char*)std::to_string(score).c_str(), -0.4f, 0.70f, 0.5f, 0.5f, 0.5f);
	
	// Lancer la partie
	if (!partieEnCours) {
		GraphicPrimitives::drawFillRect2D(0.0f, 0.25f, 0.2f, 0.150f, 0.5, 0.5, 0.5);
		GraphicPrimitives::drawText2D((char*)partieState.c_str(), 0.05f, 0.30f, 0, 0.5, 0.5);
	}
	else
	{
		GraphicPrimitives::drawFillRect2D(0.0f, 0.25f, 0.2f, 0.150f, 0.5, 0.5, 0.0);
		GraphicPrimitives::drawText2D((char*)partieState.c_str(), 0.05f, 0.30f, 0, 0.5, 0.5);
	}

	// BOUTIQUE
	// Albator
	float x1, y1, x2, y2, x3;
	x1 = -0.95f; x2 = x1 + 0.1f; x3 = x1;
	y1 = 0.45f; y2 = y1 + 0.1f; float y3 = y3 = y1 + 0.2f;
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 0.0, 0.0, 1);
	GraphicPrimitives::drawOutlinedRect2D(-0.95f, 0.35f, 0.03f, 0.05f, 1, 1, 1);
	char * Moins = new char[2];
	Moins = _strdup("-");
	GraphicPrimitives::drawText2D(Moins, -0.94f, 0.36, 1, 1, 1);
	GraphicPrimitives::drawOutlinedRect2D(-0.85f, 0.35f, 0.03f, 0.05f, 1, 1, 1);
	char * Plus = new char[2];
	Plus = _strdup("+");
	GraphicPrimitives::drawText2D(Plus, -0.84f, 0.36, 1, 1, 1);
	char * Prix = new char[10];
	Prix = _strdup("Prix");
	GraphicPrimitives::drawText2D(Prix, -0.75, 0.5, 1, 1, 1);
	Prix = _strdup("25 fCFA");
	GraphicPrimitives::drawText2D(Prix, -0.75, 0.35, 1, 1, 0);

	//FreetleDjin
	x1 = -0.95f; x2 = x1 + 0.1f; x3 = x1;
	y1 = y1 - 0.35f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 1, 0.0, 0.0);
	GraphicPrimitives::drawOutlinedRect2D(-0.95f, 0.00f, 0.03f, 0.05f, 1, 1, 1);
	GraphicPrimitives::drawText2D(Moins, -0.94f, 0.01f, 1, 1, 1);
	GraphicPrimitives::drawOutlinedRect2D(-0.85f, 0.00f, 0.03f, 0.05f, 1, 1, 1);
	GraphicPrimitives::drawText2D(Plus, -0.84f, 0.01, 1, 1, 1);
	Prix = _strdup("50 fCFA");
	GraphicPrimitives::drawText2D(Prix, -0.75, 0.00, 1, 1, 0);

	//HalaMadrid
	x1 = -0.95f; x2 = x1 + 0.1f; x3 = x1;
	y1 = y1 - 0.35f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 1, 1, 1);
	GraphicPrimitives::drawOutlinedRect2D(-0.95f, -0.35f, 0.03f, 0.05f, 1, 1, 1);
	GraphicPrimitives::drawText2D(Moins, -0.94f, -0.34, 1, 1, 1);
	GraphicPrimitives::drawOutlinedRect2D(-0.85f, -0.35f, 0.03f, 0.05f, 1, 1, 1);
	GraphicPrimitives::drawText2D(Plus, -0.84f, -0.34, 1, 1, 1);
	Prix = _strdup("125 fCFA");
	GraphicPrimitives::drawText2D(Prix, -0.75, -0.35, 1, 1, 0);

	if ((!plusDeVaisseaux) && (!msgFinDeLaPartie)) {
		float x1, y1, x2, y2, x3;
		if (!isAlbator) {
			x1 = -0.5f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 0.0, 0, 1);
		}
		else {
			x1 = -0.5f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; float y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 0.11, 0.1, 0.1);
		}

		if (!isFreetleDjin) {
			x1 = -0.3f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 1,0,0);
		}
		else {
			x1 = -0.3f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 0.11, 0.1, 0.1);
		}

		if (!isHalaMadrid) {
			x1 = -0.1f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 1, 1, 1);
		}
		else {
			x1 = -0.1f; x2 = x1 + 0.1f; x3 = x1;
			y1 = 0.45f; y2 = y1 + 0.1f; y3 = y3 = y1 + 0.2f;
			GraphicPrimitives::drawFillTriangle2D(x1, y1, x2, y2, x3, y3, 0.11, 0.1, 0.1);

		}
	}

	// Nombre de Vaisseaux pouvant etre Posés
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_AlbatorA - nb_AlbatorP).c_str(), -0.38, 0.55, 1, 1, 1);
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_FreetleDjinA - nb_FreetleDjinP).c_str(), -0.18, 0.55, 1, 1, 1);
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_HalaMadridA - nb_HalaMadridP).c_str(), 0.02, 0.55, 1, 1, 1);
	// Nombre de Vaisseaux Achetés
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_AlbatorP).c_str(), -0.5, 0.40, 1, 1, 1);
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_FreetleDjinP).c_str(), -0.3, 0.40, 1, 1, 1);
	GraphicPrimitives::drawText2D((char*)std::to_string(nb_HalaMadridP).c_str(), -0.1, 0.40, 1, 1, 1);

	// Argent detenu
	char * Money = new char[2];
	Money = _strdup("Money in the bank :");
	GraphicPrimitives::drawText2D(Money, -0.25, 0.70, 0.5, 0.5, 1);
	GraphicPrimitives::drawText2D((char*)std::to_string(argent).c_str(), 0.0, 0.70, 1, 1, 1);
	Money = _strdup(" fCFA");
	GraphicPrimitives::drawText2D(Money, 0.05, 0.70, 1, 1, 1);


	if (msgFinDeLaPartie) {
		GraphicPrimitives::drawText2D((char*)getStringMsgFinDeLaPartie().c_str(), 0.3, 0.6, 1, 1, 1);
		GraphicPrimitives::drawText2D((char*)getChangement().c_str(), 0.3, 0.7, 1, 1, 1);
	}
	if (plusDeVaisseaux && (!msgFinDeLaPartie)) {
		GraphicPrimitives::drawText2D((char*)stringPlusDeVaisseaux.c_str(), 0.3, 0.6, 1, 1, 1);
	}
}

void Launcher::ticks()
{
}

void Launcher::resetVaisseauSurCase()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			vaisseauSurLaCase[i][j] = false;
		}
	}
}

void Launcher::resetNiveauChoisi()
{
	for (int i = 0; i < 5; i++) {
		niveauChoisi[i] = false;
		niveau = 0;
	}
}
