#include "MyGameEngine.h"

void MyGameEngine::idle(){
   /* for (int i = 0; i < paps->size(); i++) {
        (*paps)[i]->tick();
    }*/
	// Ticks Vaisseaux
	for (int i = 0; i < vaisseaux->size(); i++) {
		(*vaisseaux)[i]->tick();
	}

	// Ticks Missiles
	for (int i = 0; i < missiles->size(); i++) {
		(*missiles)[i]->tick();
	}
	
	// Ticks Asteroides
	for (int i = 0; i < asteroides->size(); i++) {
		(*asteroides)[i]->tick();
	}
}

// Complet