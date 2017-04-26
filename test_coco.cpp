#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <ios>
#include <sstream>
#include <cstdlib>


/*
IMPORTANT :
	Il faut include que les fichiers .hpp MAIS lors de la compilation, il faut mettre "g++ test.cpp media.cpp ..." --> faire un makefile
	Pour le moment on facilite les choses en intégrant les .cpp --> A CHANGER !!
*/

/* Fichiers à inclure lorsque le makefile sera prêt
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"
#include "revue.hpp"
*/

//#include "mediatheque.cpp"
//#include "livre.cpp"
#include "revues.cpp"

/* test mediatheque
int main(){
	mediatheque *med = new mediatheque();
	med->info();
	med->setNom("ENSEIRB-MATMECA");
	med->info();
	delete med;
	exit(EXIT_SUCCESS);
}
*/

/*test livre*/
int main(){
	revues *lvr = new revues();
	lvr->setCollection("Milles et une nuits");
	lvr->setTitre("Les aventures de Don Quichote");
	lvr->infoAdmin();
	delete lvr;
	exit(EXIT_SUCCESS);
}