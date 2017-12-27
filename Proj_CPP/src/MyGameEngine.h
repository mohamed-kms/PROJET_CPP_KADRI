#pragma once

#include "Engine.h"
#include "GameEngineBase.h"
#include "Papillon.h"
#include "Damier.h"
#include "Case.h"
#include "Vaisseaux.h"
#include "Missile.h"
#include "Asteroides.h"
#include "Launcher.h"

class MyGameEngine : public GameEngineBase {
private:
	std::vector<Damier *>* damier;
	std::vector<Case *>* caseI;
	std::vector<Vaisseaux *>* vaisseaux;
	std::vector<Missile *>* missiles;
	std::vector<Asteroides *>* asteroides;
	std::vector<Launcher *>* launcher;
	unsigned long start;
public:
    MyGameEngine(std::vector<Damier *>* damier_, std::vector<Case *>* caseI_, std::vector<Vaisseaux *>* vaisseaux_, std::vector<Missile *>* missiles_, std::vector<Asteroides *>* asteroides_, std::vector<Launcher *>* launcher_, unsigned long start_):
	damier(damier_), caseI(caseI_), vaisseaux(vaisseaux_), missiles(missiles_), asteroides(asteroides_), launcher(launcher_), start(start_){}
    virtual void idle();
};

// Complet