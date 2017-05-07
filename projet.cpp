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

void recherche(ressources *res){
	int typeRecherche;
	std::string strSearch;
	std::cout << "Quel type de recherche souhaitez vous effectuer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Quitter" << std::endl;
	std::cin >> typeRecherche;
	while(typeRecherche != 4){
		while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3){
			std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Quitter" << std::endl;
			std::cin >> typeRecherche;
		}
		if(typeRecherche == 1){
			std::cout << "Recherche generale.\nMot a rechercher : ";
			std::cin >> strSearch;
			res->rechercheGene(strSearch);
		}
		else if(typeRecherche == 2){
			std::cout << "Recherche par type. Veuillez entrer le type a chercher :\n\t(1) Livre\n\t(2) Revue\n\t (3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
			std::cin >> typeRecherche;
			while(typeRecherche != 8){
				while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4 && typeRecherche != 5 && typeRecherche != 6 && typeRecherche != 7){
					std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Livre\n\t(2) Revue\n\t (3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
				if(typeRecherche == 1){
					std::cout << "Recherche parmi les livres.\nMot a rechercher :";
				}
				else if(typeRecherche == 2){
					std::cout << "Recherche parmi les revues.\nMot a rechercher :";
				}
				else if(typeRecherche == 3){
					std::cout << "Recherche parmi les VHS.\nMot a rechercher :";
				}
				else if(typeRecherche == 4){
					std::cout << "Recherche parmi les DVD.\nMot a rechercher :";
				}
				else if(typeRecherche == 5){
					std::cout << "Recherche parmi les CD.\nMot a rechercher :";
				}
				else if(typeRecherche == 6){
					std::cout << "Recherche parmi les sessources numeriques.\nMot a rechercher :";
				}
				else if(typeRecherche == 7){
					std::cout << "Recherche parmi les peintures.\nMot a rechercher :";
				}
				std::cin >> strSearch;
				res->rechercheType(strSearch, typeRecherche);
				break;
			}
		}
		else if(typeRecherche == 3){

			std::cout << "Recherche par champ. Veuillez entrer le type a chercher :\n\t(1) ID\n\t(2) Titre\n\t (3) Auteur\n\t(4) Annee de parution\n\t(5) Quitter" << std::endl;
			std::cin >> typeRecherche;
			while(typeRecherche != 5){
				while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4){
					std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) ID\n\t(2) Titre\n\t (3) Auteur\n\t(4) Annee de parution\n\t(5) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
				if(typeRecherche == 1){
					std::cout << "Recherche sur les ID.\nID a rechercher :";
				}
				else if(typeRecherche == 2){
					std::cout << "Recherche sur les titres.\nTitre a rechercher :";
				}
				else if(typeRecherche == 3){
					std::cout << "Recherche sur les auteurs.\nNom a rechercher :";
				}
				else if(typeRecherche == 4){
					std::cout << "Recherche sur les annees de parution.\nAnnee a rechercher :";
				}
				std::cin >> strSearch;
				res->rechercheChamp(strSearch, typeRecherche);
				break;
			}
		}
		std::cout << "Resultats de la recherche : " << std::endl;
		res->list();
		std::cout << "Quelle action realiser :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Quitter" << std::endl;
		std::cin >> typeRecherche;
		while(typeRecherche != 4){
			while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4){
					std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Quitter" << std::endl;
					std::cin >> typeRecherche;
			}
			if(typeRecherche == 1){
				std::cout << "Recherche sur les resultats trouves." << std::endl;
				break;
			}
			else if(typeRecherche == 2){
				std::cout << "Nouvelle recherche" << std::endl;
				res->restore();
				break;
			}
			else if(typeRecherche == 3){
				std::string saveName;
				std::cout << "Sauvegarde des resultats. Merci d'entrer un nom de fichier de sauvegarde : ";
				std::cin >> saveName;
				res->save(saveName.c_str());
				std::cout << "Quelle action realiser :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Quitter" << std::endl;
				std::cin >> typeRecherche;
			}
		}
		if(typeRecherche != 4){
			std::cout << "Quel type de recherche souhaitez vous effectuer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Quitter" << std::endl;
			std::cin >> typeRecherche;
		}
		//else{
		//break;
		//}
	}
	std::cout << "Fin de la recherche.\n" << std::endl;
}


int main(){
	mediatheque *mediath = new mediatheque("ENSEIRB-MATMECA");

	ressources *res = new ressources();
	res->load("cd.txt");
	res->load("revues.txt");
	res->load("livre.txt");
	res->load("vhs.txt");
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
									std::cout << "Ajout du client confirme.\n" << std::endl; 
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
									std::cout << "Ajout de l'administrateur confirme.\n" << std::endl; 
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
						std::string idUtilisateur;
						int idUser;
						std::cout << "Merci d'entrer un N identifiant d'utilisateur pour des informations specifiques. Un ID incorrect ou '1' affiche des informations generales sur l'ensemble des utilisateurs. Entrer '0' pour quitter." << std::endl;
						std::cin >> idUtilisateur;
						while(idUtilisateur.compare("0") != 0){
							idUser = uti->verifIdClient(idUtilisateur);
							if (idUtilisateur.compare("1") == 0 || idUser == 0){
								uti->info();
							}
							else if(idUser != 0){
								uti->infoClient(uti->getIdUtilisateur(idUtilisateur));
							}
							std::cout << "Entrer N identifiant pour des informations specifiques ou '1' pour des informations generales sur tous les clients. Entrer '0' pour quitter." << std::endl;
							std::cin >> idUtilisateur;
						}
					}
					else if(choix == 6){
						//recherche
						recherche(res);
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
						recherche(res);
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
			recherche(res);
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