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

#include "mediatheque.cpp"
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

int connexion(utilisateurs *uti){
	std::string idClient;
	std::cout << "N° identifiant : ";
	std::cin >> idClient;
	int id = uti->verifIdClient(idClient);
	while(id == 0 && idClient.compare("0") != 0){
		std::cout << "Numéro d'identifiant incorrect, merci de reessayer ou de rentrer '0' pour quitter : ";
		std::cin >> idClient;
		id = uti->verifIdClient(idClient);
	}
	if (idClient.compare("0") == 0)
		return 0;
	else if(id < 0){
		std::string mdp;
		std::cout << "Mot de passe : ";
		std::cin >> mdp;
		while(uti->verifMdp(mdp, -id-1) == 0 && idClient.compare("quitter") != 0){
			std::cout << "Mot de passe incorrect, merci de reessayer (Mot de passe/quitter) : ";
			std::cin >> mdp;
		}
		if (mdp.compare("quitter") == 0)
			return 0;
	}
	return id;
}

void recherche(){


}


int main(){
	mediatheque *mediath = new mediatheque("ENSEIRB-MATMECA");

	ressources *res = new ressources();
	res->load("cd.txt");
	res->load("revues.txt");
	res->load("livre.txt");
	res->load ("vhs.txt");
	res->load("dvd.txt");
	res->load("resNumerique.txt");
	res->load("peinture.txt");

	utilisateurs *uti = new utilisateurs("utilisateurs.txt");
	/*

	Creer la mediatheque, uploader les ressources et les clients

	*/



	std::cout 	<< "Bonjour et bienvenu dans le logiciel de gestion de ressources de la mediatheque " << mediath->getNom() << " . " << std::endl
				<< "Choisissez une action a realiser :\n\t(1) connexion\n\t(2) recherche\n\t(3) aide \n\t(4) quitter" << std::endl;
	int action;
	std::cin >> action;
	while(action != 4){
		while(action != 1 && action != 2 && action != 3){
			std::cout << "Action incorrecte, merci de saisir une action parmi les suivantes :\n\t(1) connexion\n\t(2) recherche\n\t(3) aide \n\t(4) quitter" << std::endl;
			std::cin >> action;
		}
		if(action == 3){
			std::cout << "En mode non connecte, vous n'avez acces qu'a la recherche de media. Actuellement la mediatheque contient " << res->getNbrRessource() << " medias, dont des " << res->getTypeRessource() << std::endl
					  << "Pour plus d'information, merci de contacter un administrateur de la mediatheque.\n";/*Que souhaitez vous faire (connexion/recherche/aide/quitter) : ";
			std::cin >> action;
			/*while(action.compare("connexion") != 0 && action.compare("recherche") !=0 && action.compare("aide") != 0 && action.compare("quitter") != 0){
				std::cout << "Action incorrecte, merci de saisir une action parmi les suivantes : connexion/recherche/aide/quitter" << std::endl;
				std::cin >> action;
			}*/
		}
		else if(action == 1){
			int id = connexion(uti);
			int choix;
			if (id < 0){ //droits admin
				id = -id - 1;
				std::cout << "Authentification reussie (compte Administrateur)." << std::endl
						  << "Bonjour " << uti->getAdmin(id) << ", quelle action souhaitez vous realiser :\n\t(1) inscription\n\t(2) emprunt\n\t(3) reservation\n\t(4) retour\n\t(5) infoclient\n\t(6) recherche\n\t(7) quitter" << std::endl;
				std::cin >> choix;
				while(choix != 7){
					while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6){
						std::cout << "Choix incorrect, merci de reessayer :\n\t(1) inscription\n\t(2) emprunt\n\t(3) reservation\n\t(4) retour\n\t(5) infoclient\n\t(6) recherche\n\t(7) quitter" << std::endl;
						std::cin >> choix;
					}
					if(choix == 1){
						//inscription nouveau client ou administrateur
						int typeAjout;
						std::string str;
						std::cout << "Procedure d'ajout d'un utilisateur. Souhaitez vous :\n\t(1) ajouter un client\n\t(2) ajouter un administrateur\n\t(3) quitter" << std::endl;
						std::cin >> typeAjout;
						while(typeAjout != 3){
							while(typeAjout != 1 && typeAjout != 2){
								std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) ajouter un client\n\t(2) ajouter un administrateur\n\t(3) quitter" << std::endl;
								std::cin >> typeAjout;
							}
							if(typeAjout == 1){
								//ajout client
								client *clt = new client();
								std::cout << "Merci de rentrer les informations suivantes (en majuscule, sans espace ni caractere special) :\n\tNom : ";
								std::cin >> str;
								clt->setNom(str);
								std::cout <<"\tPrenom : ";
								std::cin >> str;
								clt->setPrenom(str);
								std::cout << "Confirmez vous l'enregistrement du client (y/n) : " << clt->getNom() << " " << clt->getPrenom() << ".\t";
								std::cin >> str;
								while(str.compare("y") != 0 && str.compare("n") != 0){
									std::cout << "Entree incorrecte, merci de reessayer (y/n) : ";
									std::cin >> str;
								}
								if(str.compare("y") == 0){
									uti->addClient(clt);
									//addUser(clt);
								}
								else if(str.compare("n") == 0){
									std::cout << "Client non confirme, abortion de la procedure d'ajout d'utilisateur.\n" << std::endl;
								}
								break;
							}
							else if(typeAjout == 2){
								//ajout admin
								admin *adm = new admin();
								std::cout << "Merci de rentrer les informations suivantes (en majuscule, sans espace ni caractere special) :\n\tNom : ";
								std::cin >> str;
								adm->setNom(str);
								std::cout <<"\tPrenom : ";
								std::cin >> str;
								adm->setPrenom(str);
								std::cout <<"\tMot de passe (8 caracteres) : ";
								std::cin >> str;
								while(str.size() != 8){
									std::cout << "Mot de passe incorrect. Merci de saisir un mot de passe a 8 caracteres : ";
									std::cin >> str;
								}
								adm->setMdp(str);
								std::cout << "Confirmez vous l'enregistrement de l'administrateur (y/n) : " << adm->getNom() << " " << adm->getPrenom() << ".\t";
								std::cin >> str;
								while(str.compare("y") != 0 && str.compare("n") != 0){
									std::cout << "Entree incorrecte, merci de reessayer (y/n) : ";
									std::cin >> str;
								}
								if(str.compare("y") == 0){
									uti->addAdmin(adm);
									//addUser(adm);
								}
								else if(str.compare("n") == 0){
									std::cout << "Client non confirme, abortion de la procedure d'ajout d'utilisateur.\n" << std::endl;
								}

								break;
							}
						}
						if(typeAjout == 3){
							//quitter
							std::cout << "Abortion de la procedure d'ajout d'utilisateur.\n" << std::endl;
						}
					}
					else if(choix == 2){
						//emprunt
					}
					else if(choix == 3){
						//reservation
					}
					else if(choix == 4){
						//retour
					}
					else if(choix == 5){
						//infoclient
					}
					else if(choix == 6){
						//recherche
					}
					std::cout << "Quelle action souhaitez vous realiser :\n\t(1) inscription\n\t(2) emprunt\n\t(3) reservation\n\t(4) retour\n\t(5) infoclient\n\t(6) recherche\n\t(7) quitter" << std::endl;
					std::cin >> choix;
				}
				std::cout << "Au revoir " << uti->getAdmin(id) << ".\n" << std::endl;
			}
			else if(id > 0){ //droits client
				id = id - 1;
				std::cout << "Authentification reussie (compte Client)." << std::endl
						  << "Bonjour " << uti->getClient(id) << ", quelle action souhaitez vous realiser :\n\t(1) reservation\n\t(2) infoperso\n\t(3) recherche\n\t(4) quitter"  << std::endl;
				//uti->infoClient(id);
				std::cin >> choix;
				while(choix != 4){
					while(choix != 1 && choix != 2 && choix != 3){
						std::cout << "Choix incorrect, merci de reessayer :\n\t(1) reservation\n\t(2) infoperso\n\t(3) recherche\n\t(4) quitter" << std::endl;
						std::cin >> choix;
					}
					if(choix == 1){
						//reservation
					}
					else if(choix == 2){
						//infoperso
						uti->infoClient(id);
					}
					else if(choix == 3){
						//recherche
					}
					std::cout << "Quelle action souhaitez vous realiser :\n\t(1) reservation\n\t(2) infoperso\n\t(3) recherche\n\t(4) quitter"  << std::endl;
					std::cin >> choix;
				}
				std::cout << "Au revoir " << uti->getClient(id) << ".\n" << std::endl;
			}
			else{
				std::cout << "Echec de l'authentification." << std::endl;
			}
		}
		else if(action == 2){
			recherche();
		}
		else{ //a enlever pour la version finale
			std::cout << "Erreur, ce cas ne devrait pas se produire." << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "Quelle action souhaitez vous realiser :\n\t(1) connexion\n\t(2) recherche\n\t(3) aide \n\t(4) quitter" << std::endl;
		std::cin >> action;
	}
	std::cout << "Fin du programme." << std::endl;
	exit(EXIT_SUCCESS);
}