#include <vector>
#include <iostream>	// std::cout
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream> //file stream
#include <ostream>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <string>	//std::string   std::to_string
#include <stdlib.h>


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

#include "livre.hpp"
#include "revues.hpp"
#include "cd.hpp"
#include "vhs.hpp"
#include "dvd.hpp"
#include "resNumerique.hpp"
#include "peinture.hpp"
#include "media.hpp"
#include "ressources.hpp"


#include "media.cpp"
#include "livre.cpp"
#include "revues.cpp"
#include "cd.cpp"
#include "vhs.cpp"
#include "dvd.cpp"
#include "resNumerique.cpp"
#include "peinture.cpp"
#include "ressources.cpp"



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

//test revue
/*int main(){
	revues *rev = new revues();
	rev->setCollection("Milles et une nuits");
	rev->setTitre("Les aventures de Don Quichote");
	rev->infoAdmin();
	delete rev;
	exit(EXIT_SUCCESS);
}*/

/*test ressource*/

int main(){
	ressources *res = new ressources();
	res->load("cd.txt");
	res->load("revues.txt");
	res->load("livre.txt");
	res->load ("vhs.txt");
	res->load("dvd.txt");
	res->load("resNumerique.txt");
	res->load("peinture.txt");
	//res->reset();
	//res->save("save.txt");
	delete res;
	exit(EXIT_SUCCESS);
}