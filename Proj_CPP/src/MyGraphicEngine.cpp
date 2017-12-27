#include <string>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
using namespace std;

void MyGraphicEngine::Draw() {
	if (ouaisCbon) {
		missiles->push_back(new Missile(1, 1, 1, 1, "", missiles, 0, asteroides, launcher, 0, 1, 0, 0, 0));
		launcher->push_back(new Launcher());
		damier->push_back(new Damier(0, 10, damier, caseI));
		ouaisCbon = false;
	}

	// Dessiner Launcher
	(*launcher)[0]->draw();

	// Dessiner le damier
	for (int i = 0; i < (int)damier->size(); i++) {
		(*damier)[i]->draw();
	}

	// Dessiner les vaisseaux
	for (int i = 0; i < (int)vaisseaux->size(); i++)
	{
		(*vaisseaux)[i]->draw();
	}

	// Dessiner les asteroides
	for (int i = 0; i < (int)asteroides->size(); i++) {
		(*asteroides)[i]->draw();
	}

	// Dessiner les missiles
	for (int i = 0; i < (int)missiles->size(); i++)
	{
		(*missiles)[i]->draw();
	}
}

// Complet