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
#include "livre.cpp"
#include "revues.cpp"
#include "ressources.cpp"
#include "utilisateurs.cpp"
//#include "client.cpp"
//#include "admin.cpp"

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

/*test revue
int main(){
	revues *lvr = new revues();
	lvr->setCollection("Milles et une nuits");
	lvr->setTitre("Les aventures de Don Quichote");
	lvr->infoAdmin();
	delete lvr;
	exit(EXIT_SUCCESS);
}*/

/*test ressource*/

/*int main(){
	/*ressources *res = new ressources();
	res->load("livre.txt");
	//res->reset();
	//res->list();
	//res->save("save.txt");
	delete res;
	exit(EXIT_SUCCESS);
}*/



/*test utilisateurs*/

int main(){
	utilisateurs *uti = new utilisateurs("utilisateurs.txt");
	delete uti;
	exit(EXIT_SUCCESS);
}