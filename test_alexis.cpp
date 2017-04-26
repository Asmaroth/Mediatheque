#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <vector>

//#include "ressources.cpp"
#include "livre.cpp"
//#include "revues.cpp"
//#include "cd.cpp"
//#include "dvd.cpp"
//#include "vhs.cpp"
//#include "peinture.cpp"
//#include "resNumerique.cpp"



int main()
{
	//ressources* Res = new ressources(2,"ta mere",9);


	//Res ->info();
	book->info();

	//delete Res;
	delete book;

	exit(EXIT_SUCCESS);

}