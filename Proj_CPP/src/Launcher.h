#pragma once
#include "Case.h"
#include "BreedsOwn.h"
#include "Asteroides.h"
#include "GraphicPrimitives.h"
#include <string>
#include "strsafe.h"

class Launcher
{
public:
	Launcher();
	~Launcher();

	bool vaisseauSurLaCase[10][10] = { { false} };
	bool ligneOccupee[10] = { false };
	int nbAsteroides = 0;

	int nb_AlbatorA = 0;
	int nb_FreetleDjinA = 0;
	int nb_HalaMadridA = 0;

	int nb_AlbatorP = 0;
	int nb_FreetleDjinP = 0;
	int nb_HalaMadridP = 0;

	int difference = 0;

	// Accesseur
	int getNiveau();
	void setNiveau(int niveau_);
	int getArgent();
	void setArgent(int argent_);
	int getScore();
	void setScore(int score_);
	bool getPartieEnCours();
	void setPartieEnCours(bool partieState_);
	bool getLancementAsteroides();
	void setLancementAsteroides(bool lancer_);
	bool getDeroulerNiveau();
	void setDeroulerNiveau(bool derouler_);
	bool* getNiveauChoisi();
	void setNiveauChoisi(int i, bool niveau_);
	bool getIsAlbator();
	void setIsAlbator(bool isAlbator_);
	bool getIsFreetleDjin();
	void setIsFreetleDjin(bool isFreetleDjin_);
	bool getIsHalaMadrid();
	void setIsHalaMadrid(bool isHalaMadrid_);
	bool getAsteroidesCree();
	void setAsteroidesCree(bool ast_);
	std::string getChangement();
	void setChangement(std::string change_);
	bool getMsgFinDeLaPartie();
	void setMsgFinDeLaPartie(bool msg_);
	std::string getStringMsgFinDeLaPartie();
	void setStringMsgFinDeLaPartie(std::string string_);
	bool getPlusDeVaisseaux();
	void setPlusDeVaisseaux(bool v_);
	std::string getStringPlusDeVaisseaux();
	std::string setStringPlusDeVaisseaux(std::string string_);

	// Meilleur score

	// Methodes 
	void draw();
	void ticks();
	void resetVaisseauSurCase();
	void resetNiveauChoisi();
private:
	bool partieEnCours;
	std::string partieState = "START";
	int niveau = 0;
	int argent;
	int score;
	bool isAlbator = false;
	bool isFreetleDjin = false;
	bool isHalaMadrid = false;
	bool lancementAsteroides = false;
	bool plusDeVaisseaux = false;
	bool msgFinDeLaPartie = false;
	bool asteroidesCree = false;
	std::string stringMsgFinDeLaPartie = "msg";
	std::string changement = "";
	std::string stringPlusDeVaisseaux = "Rendez-vous a la boutique pour vous approvisionner en vaisseaux";

	bool deroulerNiveau = false;
	bool niveauChoisi[5] = { false };

	BreedsOwn *breedsOwn = new BreedsOwn(1.0f, 1.0f, 1, 1, 1, 1, 1);
};
