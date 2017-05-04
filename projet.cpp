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
#include "mediatheque.hpp"
#include "media.hpp"
#include "livre.hpp"
#include "revue.hpp"
#include "cd.hpp"
#include "dvd.hpp"
#include "resNumerique.hpp"
#include "vhs.hpp"
#include "peinture.hpp"
*/

int main(){
	/*

	Creer la mediatheque, uploader les ressources et les clients

	*/



	std::cout 	<< "Bonjour et bienvenu dans le logiciel de gestion de ressources de la mediatheque " << "NOM_MEDIATHEQUE" << " . " << std::endl
				<< "Choisissez une action a realiser : connexion/inscription/aide/quitter" << std::endl;
	std::string action;
	std::cin >> action;
	while(action.compare("connexion") != 0 && action.compare("inscription") != 0 && action.compare("aide") != 0 && action.compare("quitter") != 0){
		std::cout << "Action incorrecte, merci de saisir une action parmi les suivantes : connexion/inscription/aide/quitter" << std::endl;
		std::cin >> action;
	}
	if(action.compare("connexion") == 0){
		std::string idClient;
		std::cout << "N° identifiant : ";
		std::cin >> idClient;
		while(/*!verifIdClient(idClient)*/1){
			std::cout << "Numéro d'identifiant incorrect, merci de reessayer : ";
			std::cin >> idClient;
		}
	}
	if(action.compare("inscription") == 0){

	}
	if(action.compare("aide") == 0){

	}
	if(action.compare("quitter") == 0){
		std::cout << "Au revoir." << std::endl;
		exit(EXIT_SUCCESS);
	}
	std::cout << "On a deja fait une bonne partie" << std::endl;
	exit(EXIT_SUCCESS);
}