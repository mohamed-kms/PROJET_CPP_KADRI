#include <iostream>

#include "Engine.h"
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "Papillon.h"
#include "Damier.h"
#include "Case.h"

int main(int argc, char* argv[]){
    Engine e(argc,argv);
    
	std::vector<Damier *> damier;
	std::vector<Case *> caseI;
	std::vector<Vaisseaux *> vaisseaux;
	std::vector<Missile *> missiles;
	std::vector<Asteroides *> asteroides;
	std::vector<Launcher *> launcher;
	unsigned long start;
	start = GetTickCount();
    
    GraphicEngineBase* ge = new MyGraphicEngine(&damier, &caseI, &vaisseaux, &missiles, &asteroides, &launcher, start);
    GameEngineBase* gme = new MyGameEngine(&damier, &caseI, &vaisseaux, &missiles, &asteroides, &launcher, start);
    ControlEngineBase* ce = new MyControlEngine(&damier, &caseI, &vaisseaux, &missiles, &asteroides, &launcher, start);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
