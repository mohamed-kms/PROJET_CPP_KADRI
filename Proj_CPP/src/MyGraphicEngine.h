#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Damier.h"
#include "Case.h"
#include "Vaisseaux.h"

class MyGraphicEngine : public GraphicEngineBase {
private:
    std::vector<Damier *>* damier;
	std::vector<Case *>* caseI;
	std::vector<Vaisseaux *>* vaisseaux;
	std::vector<Missile *>* missiles;
	std::vector<Asteroides *>* asteroides;
	std::vector<Launcher *>* launcher;
	unsigned long start;
	bool ouaisCbon = true;
    char* str;

public:
    
    MyGraphicEngine(std::vector<Damier *>* damier_, std::vector<Case *>* caseI_, std::vector<Vaisseaux *>* vaisseaux_,std::vector<Missile *>* missiles_, std::vector<Asteroides *>* asteroides_, std::vector<Launcher *>* launcher_, unsigned long start_):
        damier(damier_), caseI(caseI_), vaisseaux(vaisseaux_), missiles(missiles_), asteroides(asteroides_), launcher(launcher_), start(start_){}
    
    //float x1,x2, dx1, dx2;
    
    virtual void Draw();
    
};

// Complet