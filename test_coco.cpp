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
//#include <cstdio>


/*
IMPORTANT :
	Il faut include que les fichiers .hpp MAIS lors de la compilation, il faut mettre "g++ test.cpp media.cpp ..." --> faire un makefile
	Pour le moment on facilite les choses en intégrant les .cpp --> A CHANGER !!
*/

#include "mediatheque.hpp"
#include "livre.hpp"
#include "revues.hpp"
#include "cd.hpp"
#include "vhs.hpp"
#include "dvd.hpp"
#include "resNumerique.hpp"
#include "peinture.hpp"
#include "media.hpp"
#include "ressources.hpp"
#include "utilisateurs.hpp"
#include "client.hpp"
#include "admin.hpp"


#include "media.cpp"
#include "livre.cpp"
#include "revues.cpp"
#include "cd.cpp"
#include "vhs.cpp"
#include "dvd.cpp"
#include "resNumerique.cpp"
#include "peinture.cpp"
#include "ressources.cpp"
#include "utilisateurs.cpp"
#include "client.cpp"
#include "admin.cpp"


/*test ressource*/

/*int main(){
	ressources *res = new ressources();
	res->load("cd.txt");
	res->load("revues.txt");
	res->load("livre.txt");
	res->load ("vhs.txt");
	res->load("dvd.txt");
	res->load("resNumerique.txt");
	res->load("peinture.txt");
	//res->list();
	//res->reset();
	//res->list();
	res->save("save.txt");
	utilisateurs *uti = new utilisateurs("utilisateurs.txt");
	delete res;
	exit(EXIT_SUCCESS);
}*/

int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}