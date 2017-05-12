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
	std::cout << "Numero identifiant : ";
	std::cin >> idClient;
	int id = uti->verifIdClient(idClient);
	while(id == 0 && idClient.compare("0") != 0){
		std::cout << "Numero d'identifiant incorrect, merci de reessayer ou de rentrer '0' pour quitter : ";
		std::cin >> idClient;
		id = uti->verifIdClient(idClient);
	}
	if (idClient.compare("0") == 0){
		return 0;
	}
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

















void infoRessource(ressources *res, int userIsClient){
	std::string idRessource;
	int idMedia;
	std::cout << "Merci d'entrer un Numero identifiant de media pour des informations specifiques. Un ID incorrect ou '1' affiche des informations generales sur l'ensemble des medias. Entrer '0' pour quitter." << std::endl;
	std::cin >> idRessource;
	while(idRessource.compare("0") != 0){
		if(userIsClient)
			res->checkVersion();
		idMedia = res->verifIdMedia(idRessource);
		if (idRessource.compare("1") == 0 || idMedia == 0){
			res->info();
			res->list();
		}
		else if(idMedia != 0){
			res->info(idMedia - 1);
		}
		std::cout << "\nEntrer Numero identifiant pour des informations specifiques ou '1' pour des informations generales sur tous les medias. Entrer '0' pour quitter." << std::endl;
		std::cin >> idRessource;
	}
}
















void recherche(ressources *res, int userIsClient){
	int typeRecherche;
	int flagRecherche = 0;
	std::string strSearch;
	std::cout << "Quel type de recherche souhaitez vous effectuer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
	std::cin >> typeRecherche;
	while(typeRecherche != 5){
		while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4){
			std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
			std::cin >> typeRecherche;
		}
		if(typeRecherche == 1){
			std::cout << "Recherche generale.\nMot a rechercher : ";
			std::cin >> strSearch;
			/*if(userIsClient)
				res->checkVersion();*/
			res->rechercheGene(strSearch);
		}
		else if(typeRecherche == 2){
			std::cout << "Recherche par type. Veuillez entrer le type a chercher :\n\t(1) Livre\n\t(2) Revue\n\t(3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
			std::cin >> typeRecherche;
			while(typeRecherche != 8){
				while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4 && typeRecherche != 5 && typeRecherche != 6 && typeRecherche != 7){
					std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Livre\n\t(2) Revue\n\t(3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
				if(typeRecherche == 1){
					std::cout << "Recherche parmi les livres.\nMot a rechercher : ";
				}
				else if(typeRecherche == 2){
					std::cout << "Recherche parmi les revues.\nMot a rechercher : ";
				}
				else if(typeRecherche == 3){
					std::cout << "Recherche parmi les VHS.\nMot a rechercher : ";
				}
				else if(typeRecherche == 4){
					std::cout << "Recherche parmi les DVD.\nMot a rechercher : ";
				}
				else if(typeRecherche == 5){
					std::cout << "Recherche parmi les CD.\nMot a rechercher : ";
				}
				else if(typeRecherche == 6){
					std::cout << "Recherche parmi les sessources numeriques.\nMot a rechercher : ";
				}
				else if(typeRecherche == 7){
					std::cout << "Recherche parmi les peintures.\nMot a rechercher : ";
				}
				std::cin >> strSearch;
				if(userIsClient)
					res->checkVersion();
				res->rechercheType(strSearch, typeRecherche);
				break;
			}
		}
		else if(typeRecherche == 3){

			std::cout << "Recherche par champ. Veuillez entrer le type a chercher :\n\t(1) ID\n\t(2) Titre\n\t(3) Auteur\n\t(4) Annee de parution\n\t(5) Quitter" << std::endl;
			std::cin >> typeRecherche;
			while(typeRecherche != 5){
				while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4){
					std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) ID\n\t(2) Titre\n\t(3) Auteur\n\t(4) Annee de parution\n\t(5) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
				if(typeRecherche == 1){
					std::cout << "Recherche sur les ID.\nID a rechercher : ";
				}
				else if(typeRecherche == 2){
					std::cout << "Recherche sur les titres.\nTitre a rechercher : ";
				}
				else if(typeRecherche == 3){
					std::cout << "Recherche sur les auteurs.\nNom a rechercher : ";
				}
				else if(typeRecherche == 4){
					std::cout << "Recherche sur les annees de parution.\nAnnee a rechercher : ";
				}
				std::cin >> strSearch;
				if(userIsClient)
					res->checkVersion();
				res->rechercheChamp(strSearch, typeRecherche);
				break;
			}
		}
		else if(typeRecherche == 4){
			infoRessource(res, userIsClient);
			//std::cout << "Quel type de recherche souhaitez vous effectuer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
			//std::cin >> typeRecherche;
			flagRecherche = 1;
		}
		if(typeRecherche != 4 && flagRecherche == 0){
			std::cout << "Resultats de la recherche : " << std::endl;
			/*if(userIsClient)
				res->checkVersion();*/
			res->list();
			std::cout << "Quelle action realiser :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
			std::cin >> typeRecherche;
			while(typeRecherche != 5){
				while(typeRecherche != 1 && typeRecherche != 2 && typeRecherche != 3 && typeRecherche != 4){
						std::cout << "Entree incorrecte, merci de reessayer :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
						std::cin >> typeRecherche;
				}
				if(typeRecherche == 1){
					std::cout << "Recherche sur les resultats trouves." << std::endl;
					break;
				}
				else if(typeRecherche == 2){
					std::cout << "Nouvelle recherche" << std::endl;
					if(userIsClient)
						res->checkVersion();
					res->clear();
					break;
				}
				else if(typeRecherche == 3){
					std::string saveName;
					std::cout << "Sauvegarde des resultats. Merci d'entrer un nom de fichier de sauvegarde : ";
					std::cin >> saveName;
					res->save(saveName.c_str());
					std::cout << "Quelle action realiser :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
				else if(typeRecherche == 4){
					infoRessource(res,userIsClient);
					std::cout << "Quelle action realiser :\n\t(1) Recherche sur les resultats trouves\n\t(2) Nouvelle recherche\n\t(3) Sauvegarder les resultats\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
					std::cin >> typeRecherche;
				}
			}
			if(userIsClient)
				res->checkVersion();
			res->clear();
		}
		if(typeRecherche != 5){
			std::cout << "Quel type de recherche souhaitez vous effectuer :\n\t(1) Recherche generale\n\t(2) Recherche par type\n\t(3) Recherche par champ\n\t(4) Information sur les medias\n\t(5) Quitter" << std::endl;
			std::cin >> typeRecherche;
			flagRecherche = 0;
		}
		else{
			if(userIsClient)
				res->checkVersion();
			res->clear();
		}
	}
	std::cout << "Fin de la recherche.\n" << std::endl;
	if(userIsClient)
		res->checkVersion();
	res->clear();
}

















void reservation(int idClient, ressources *res, utilisateurs *uti, int userIsClient){
	std::string id2res;
	std::string id1;
	std::string id2;
	int idMed;

	std::cout << "Identifier le media a reserver : ";
	std::cin >> id2res;
	if(userIsClient)
		res->checkVersion();
	idMed = res->verifIdMedia(id2res);
	while(idMed == 0 && id2res.compare("quitter") != 0){
		std::cout << "Entree incorrecte, merci de reessayer ou de rentrer 'quitter' pour revenir au menu precedent. Identifier le media a reserver : ";
		std::cin >> id2res;
		if(userIsClient)
			res->checkVersion();
		idMed = res->verifIdMedia(id2res);
	}
	if(idMed > 0){
		idMed = idMed - 1;
		if(id2res.compare("quitter") != 0){
			std::stringstream idResReservee(uti->getResReservee(idClient));
			getline(idResReservee, id1, '(');
			getline(idResReservee, id1, ')');
			getline(idResReservee, id2, '(');
			getline(idResReservee, id2, ')');
			if(id1.compare("0") == 0){
				uti->reservation(idClient, res->infoPrincipales(idMed), 0);
				res->reservation(uti->getIdClient(idClient), idMed, 0);
				std::cout << "Media reserve. position 1\n" << std::endl;
			}
			else if(id2.compare("0") == 0){
				uti->reservation(idClient, res->infoPrincipales(idMed), 1);
				res->reservation(uti->getIdClient(idClient), idMed, 0);
				std::cout << "Media reserve. position 2\n" << std::endl;
			}
			else{
				std::cout << "La limite maximale de media pouvant etre reservee est atteinte. Merci d'annuler une reservation avant d'en faire une autre." << std::endl;
			}
		}
	}
	else{
		std::cout << "Le media n'est pas disponible actuellement.\n" << std::endl;
	}
}






void annulerReservation(int idClient, ressources *res, utilisateurs *uti, int userIsClient){
	std::string id2deres;
	std::string id1;
	std::string id2;
	int idMed;

	std::cout << "Identifier le media a anuler la reservation ou entrer 'quitter' : " << uti->getResReservee(idClient) << std::endl;
	std::cin >> id2deres;
	if(userIsClient)
		res->checkVersion();
	std::stringstream idResReservee(uti->getResReservee(idClient));
	getline(idResReservee, id1, '(');
	getline(idResReservee, id1, ')');
	getline(idResReservee, id2, '(');
	getline(idResReservee, id2, ')');
	while(id2deres.compare(id1) != 0 && id2deres.compare(id2) != 0 && id2deres.compare("quitter") != 0){
		std::cout << "Entree incorrecte, merci de reessayer. Identifier le media a anuler la reservation ou entrer 'quitter' : " << uti->getResReservee(idClient) << std::endl;
		std::cin >> id2deres;
	}
	idMed = res->verifIdMedia(id2deres) - 1;
	if(id2deres.compare(id1) == 0){
		uti->reservation(idClient, "(0)aucun", 0);
		res->reservation("0", idMed, 3);
		std::cout << "Media dereserve.\n" << std::endl;
	}
	else if(id2deres.compare(id2) == 0){
		uti->reservation(idClient, "(0)aucun", 1);
		res->reservation("0", idMed, 3);
		std::cout << "Media dereserve.\n" << std::endl;
	}
	else
		std::cout << "Abandon de la procedure de dereservation de media.\n" << std::endl;
}




















int main(){
	mediatheque *mediath = new mediatheque("ENSEIRB-MATMECA");
	ressources *res = new ressources();
	res->reload();
	utilisateurs *uti = new utilisateurs("utilisateurs.txt");


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
			std::string idUti;
			if(id<0)
				idUti = uti->getAdminNbr(-id-1);
			else
				idUti = uti->getAdminNbr(id-1);
			int choix;
			int idMed;
			int idUser;
			std::string id2Delete;
			std::string id2Modify;
			std::string decision;
			std::string idClient;
			std::string id2act;
			std::string resEmpruntees;
			if (id < 0){ //droits admin
				id = -id - 1;
				std::cout << "Authentification reussie (compte Administrateur)." << std::endl
						  << "Bonjour " << uti->getAdmin(id) << ", quelle action souhaitez vous realiser :\n\t(1) modification utilisateur\n\t(2) modification ressource\n\t(3) emprunt\n\t(4) reservation\n\t(5) retour\n\t(6) info client\n\t(7) info ressource\n\t(8) recherche\n\t(9) quitter" << std::endl;
				std::cin >> choix;
				while(choix != 9){
					while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 7 && choix != 8){
						std::cout << "Choix incorrect, merci de reessayer :\n\t(1) modification utilisateur\n\t(2) modification ressource\n\t(3) emprunt\n\t(4) reservation\n\t(5) retour\n\t(6) info client\n\t(7) info ressource\n\t(8) recherche\n\t(9) quitter" << std::endl;
						std::cin >> choix;
					}
					if(choix == 1){
						//modification utilisateur
						std::cout << "Que souhaitez-vous faire :\n\t(1) Ajout d'un utilisateur\n\t(2) Suppression d'un utilisateur\n\t(3) Modification des donnees d'un utilisateur\n\t(4) quitter" << std::endl;
						std::cin >> choix;
						while(choix != 4){
							while(choix != 1 && choix != 2 && choix != 3){
								std::cout << "Entree incorrecte, merci de reessayer. Que souhaitez-vous faire :\n\t(1) Ajout d'un utilisateur\n\t(2) Suppression d'un utilisateur\n\t(3) Modification des donnees d'un utilisateur\n\t(4) quitter" << std::endl;
								std::cin >> choix;
							}
							if(choix == 1){
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
								int typeSupp;
								int id2suppr;
								std::string decision ;
								std::string client2suppr ;
								std::string str;
								std::cout << "Procedure de supression d'un utilisateur. Rentrez l'identifiant de l'utilisateur a supprimer : ";
								std::cin >> client2suppr;
								id2suppr = uti->verifIdClient(client2suppr);
								while( id2suppr == 0 || client2suppr.compare("quitter") == 0)
								{
									std::cout << "Entree incorrecte, merci de réssayer ou de rentrer 'quitter' pour annuler la procedure. Procedure de supression d'un utilisateur. Rentrez l'identifiant de l'utilisateur a supprimer : ";
									std::cin >> client2suppr;
									id2suppr = uti->verifIdClient(client2suppr);
								}
								if (id2suppr > 0 )
								{
									id2suppr = id2suppr - 1 ;
									std::cout << "Voulez vous vraiment supprimer le client suivant (o/n) : " << std::endl;
									uti->infoClient(id2suppr);
									std::cin >> decision ;
									while( decision.compare("o") != 0 && decision.compare("n") != 0 )
									{
										std::cout << "Entree incorrecte, merci de réssayer. Voulez vous vraiment supprimer le client suivant (o/n) : " << std::endl;
										std::cin >> decision ;
									}
									if( decision.compare("o") == 0)
									{
										std::cout << "Client en cours de suppression..." << std::endl;
										uti->deleteClient(id2suppr, client2suppr);
									}
									else 
									{
										std::cout << "Abandon de la procedure de suppression du client.\n" << std::endl;
									}
								}
								else 
								{
									id2suppr = -id2suppr - 1 ;
									std::cout << "Voulez vous vraiment supprimer l'administrateur suivant (o/n) : " << std::endl;
									uti->infoClient(uti->getIdUtilisateur(client2suppr));
									std::cin >> decision ;
									while( decision.compare("o") != 0 && decision.compare("n") != 0 )
									{
										std::cout << "Entree incorrecte, merci de réssayer. Voulez vous vraiment supprimer l'administrateur suivant (o/n) : " << std::endl;
										std::cin >> decision ;
									}
									if( decision.compare("o") == 0)
									{
										std::cout << "Administrateur en cours de suppression..." << std::endl;
										uti->deleteAdmin(id2suppr, client2suppr,idUti);
									}
									else 
									{
										std::cout << "Abandon de la procedure de suppression de l'administrateur.\n" << std::endl;
									}
								}



							}
							else if(choix == 3){

							}
							std::cout << "Que souhaitez-vous faire :\n\t(1) Ajout d'un utilisateur\n\t(2) Suppression d'un utilisateur\n\t(3) Modification des donnees d'un utilisateur\n\t(4) quitter" << std::endl;
							std::cin >> choix;
						}
					}
					else if(choix == 2){
						//modif ressource
						std::cout << "Modification de ressource. Souhaitez-vous :\n\t(1) Ajouter une ressource\n\t(2) Supprimer une ressource\n\t(3) Modifier une ressource\n\t(4) Formater la base de donnee\n\t(5) Quitter" << std::endl;
						std::cin >> choix;
						while(choix != 5){
							while(choix != 1 && choix != 2 && choix != 3 && choix != 4){
								std::cout << "Choix incorrect, merci de reessayer :\n\t(1) Ajouter une ressource\n\t(2) Supprimer une ressource\n\t(3) Modifier une ressource\n\t(4) Formater la base de donnee\n\t(5) Quitter" << std::endl;
								std::cin >> choix;
							}
							if(choix == 1){
								std::string newId;
								std::cout << "Ajout d'une ressource.\nQuel type de ressource souhaitez vous ajouter :\n\t(1) Livre\n\t(2) Revue\n\t(3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
								std::cin >> choix;
								while(choix != 8){
									while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 7){
										std::cout << "Entree incorrecte, quel type de ressource souhaitez vous ajouter :\n\t(1) Livre\n\t(2) Revue\n\t(3) VHS\n\t(4) DVD\n\t(5) CD\n\t(6) Ressource numerique\n\t(7) Peinture\n\t(8) Quitter" << std::endl;
										std::cin >> choix;
									}
									newId = res->addMedia(choix);
									std::cout << "Nouveau media cree. Son identifiant est : (" << newId << ")." << std::endl;
									choix = 8;
								}
							}
							else if(choix == 2){
								std::cout << "Suppression d'une ressource. Veuillez rentrer le numero d'identifiant de la ressource a supprimer : ";
								std::cin >> id2Delete;
								idMed = res->verifIdMedia(id2Delete);
								if(idMed != 0){
									std::cout << "Souhaitez vous vraiment supprimer la ressource suivante (o/n) : " << std::endl;
									res->info(idMed - 1);
									std::cin >> decision;
									while(decision.compare("o") != 0 && decision.compare("n") != 0){
										std::cout << "Entree incorrecte, merci de reessayer : Souhaitez vous vraiment supprimer la ressource suivante (o/n) : " << std::endl;
										res->info(idMed - 1);
									}
									if(decision.compare("o") == 0){
										res->deleteMedia(idMed, id2Delete);
										std::cout << "Ressource supprimee." << std::endl;
									}
									else if(decision.compare("n") == 0){
										std::cout << "Abandon de la suppression de media." << std::endl;
									}
								}
							}
							else if(choix == 3){
								std::cout << "Modification d'une ressource. Veuillez rentrer le numero d'identifiant de la ressource a supprimer : ";
								std::cin >> id2Modify;
								idMed = res->verifIdMedia(id2Modify);
								if(idMed != 0){
									std::cout << "Souhaitez vous vraiment smodifier la ressource suivante (o/n) : " << std::endl;
									res->info(idMed - 1);
									std::cin >> decision;
									while(decision.compare("o") != 0 && decision.compare("n") != 0){
										std::cout << "Entree incorrecte, merci de reessayer : Souhaitez vous vraiment modifier la ressource suivante (o/n) : " << std::endl;
										res->info(idMed - 1);
									}
									if(decision.compare("o") == 0){
										res->modifMedia(idMed, id2Modify);
										std::cout << "Ressource modifiee." << std::endl;
									}
									else if(decision.compare("n") == 0){
										std::cout << "Abandon de la modification de media." << std::endl;
									}
								}
							}
							else if(choix == 4){
								std::cout << "Souaitez-vous vraiment formater la base de donnee de la mediatheque ? Cette action est irreversible. (o/n) : ";
								std::cin >> decision;
								while(decision.compare("o") != 0 && decision.compare("n") != 0){
									std::cout << "Entree incorrecte, merci de reessayer : souaitez-vous vraiment formater la base de donnee de la mediatheque ? Cette action est irreversible. (o/n) : ";
									std::cin >> decision;
								}
								if(decision.compare("o") == 0){
									res->reset();
									std::cout << "La base de donnee a ete formate.\n" << std::endl;
								}
								else if(decision.compare("n") == 0){
									std::cout << "Abandon du formatage de la base de donnee.\n" << std::endl;
								}
							}
							std::cout << "Quelle action souhaitez vous realiser :\n\t(1) Ajouter une ressource\n\t(2) Supprimer une ressource\n\t(3) Modifier une ressource\n\t(4) Formater la base de donnee\n\t(5) Quitter" << std::endl;
							std::cin >> choix;
						}
					}
					else if(choix == 3){
						//emprunt
						int isAvailable;
						std::cout << "Procedure d'emprunt d'un media. Identifier le client : ";
						std::cin >> idClient;
						idUser = uti->verifIdClient(idClient);
						while(idUser <= 0 && idClient.compare("quitter") != 0){
							std::cout << "Id client incorrect, merci de reessayer ou de quitter en rentrant 'quitter' : ";
							std::cin >> idClient;
							idUser = uti->verifIdClient(idClient);
						}
						std::cout << "Id media a emprunter : ";
						std::cin >> id2act;
						idMed = res->verifIdMedia(id2act);
						while(idMed == 0 && id2act.compare("quitter") != 0){
							std::cout << "Id incorrect, merci de reessayer ou de quitter en rentrant 'quitter' : ";
							std::cin >> id2act;
							idMed = res->verifIdMedia(id2act);
						}
						isAvailable = res->verifDispo(idMed-1);
						if(isAvailable == -1){
							std::cout << "Le media demande est deja reserver. Merci de faire une autre demande ou d'annuler prealablement la reservation." << std::endl;
						}
						else if(isAvailable == -2){
							std::cout << "Le media demande est deja emprunte. Merci de faire une autre demande ou de retourner prealablement le media." << std::endl;
						}
						else if(isAvailable == -3){
							std::cout << "Le media demande est indisponible. Merci de faire une autre demande ou de rendre disponible prealablement le media." << std::endl;
						}
						else if(id2act.compare("quitter") == 0){
							std::cout << "Abandon de la procedure d'emprunt.\n" << std::endl;
						}
						else{
							int pos = uti->peutEmprunter(idUser-1);
							idMed = idMed - 1;
							if(pos != -1){
								std::cout << "Souhaitez vous vraiment emprunter le media suivant (o/n) :" << std::endl;
								res->info(idMed);
								std::cin >> decision;
								while(decision.compare("o") != 0 && decision.compare("n") != 0){
									std::cout << "Entree incorrecte, merci de reessayer : Souhaitez vous vraiment emprunter le media suivant (o/n) :" << std::endl;
									res->info(idMed);
									std::cin >> decision;
								}
								if(decision.compare("o") == 0){
									uti->emprunt(idUser-1, res->infoPrincipales(idMed), pos);
									res->reservation(idClient, idMed, 1);
									std::cout << "Media reserve.\n" << std::endl;
								}
								else if(decision.compare("n") == 0){
									std::cout << "Abandon de la procedure d'emprunt.\n" << std::endl;
								}
							}
						}
					}
					else if(choix == 4){
						//reservation
						std::cout << "Quelle action realiser :\n\t(1) reserver un media\n\t(2) annuler la reservation d'un media\n\t(3) quitter" << std::endl;
						std::cin >> choix;
						while(choix != 3){
							while(choix != 1 && choix != 2){
								std::cout << "Entree incorrecte, merci de reessayer. Quelle action realiser :\n\t(1) reserver un media\n\t(2) annuler la reservation d'un media\n\t(3) quitter" << std::endl;
								std::cin >> choix;
							}
							if(choix == 1){
								std::cout << "Procedure de reservation de media. Identifier le client : ";
								std::cin >> idClient;
								idUser = uti->verifIdClient(idClient);
								while(idUser <= 0 && idClient.compare("quitter") != 0){
									std::cout << "Id client incorrect, merci de reessayer ou de quitter en rentrant 'quitter' : ";
									std::cin >> idClient;
									idUser = uti->verifIdClient(idClient);
								}
								reservation(idUser-1, res, uti, 0);
							}
							else if(choix == 2){
								std::cout << "Procedure de dereservation de media. Identifier le client : ";
								std::cin >> idClient;
								idUser = uti->verifIdClient(idClient);
								while(idUser <= 0 && idClient.compare("quitter") != 0){
									std::cout << "Id client incorrect, merci de reessayer ou de quitter en rentrant 'quitter' : ";
									std::cin >> idClient;
									idUser = uti->verifIdClient(idClient);
								}
								annulerReservation(idUser-1, res, uti, 0);
							}
							std::cout << "Quelle action realiser :\n\t(1) reserver un media\n\t(2) annuler la reservation d'un media\n\t(3) quitter" << std::endl;
							std::cin >> choix;
						}
					}
					else if(choix == 5){
						//retour
						std::cout << "Procedure de retour de media. Identifier le client : ";
						std::cin >> idClient;
						idUser = uti->verifIdClient(idClient);
						while(idUser <= 0 && idClient.compare("quitter") != 0){
							std::cout << "Id client incorrect, merci de reessayer ou de quitter en rentrant 'quitter' : ";
							std::cin >> idClient;
							idUser = uti->verifIdClient(idClient);
						}
						idUser = idUser - 1;
						std::stringstream idResEmpruntee(uti->getResEmpruntee(idUser));
						std::string id1;
						std::string id2;
						getline(idResEmpruntee, id1, '(');
						getline(idResEmpruntee, id1, ')');
						getline(idResEmpruntee, id2, '(');
						getline(idResEmpruntee, id2, ')');
						std::cout << "Identifier la ressource a retourner : " << uti->getResEmpruntee(idUser) << std::endl;
						std::cin >> id2act;
						while(id2act.compare(id1) != 0 && id2act.compare(id2) != 0 && id2act.compare("quitter") != 0){
							std::cout << "Entree incorrecte, merci de reessayer.\nIdentifier la ressource a retourner ou annuler la demande en rentrant 'quitter' : " << uti->getResEmpruntee(idUser) << std::endl;
							std::cin >> id2act;
						}
						idMed = res->verifIdMedia(id2act) - 1;
						if(id2act.compare(id1) == 0){
							uti->retour(idUser, "(0)aucun", 0);
							uti->
							res->reservation("0", idMed, 3);
							std::cout << "Media retourne.\n" << std::endl;
						}
						else if(id2act.compare(id2) == 0){
							uti->emprunt(idUser, "(0)aucun", 1);
							res->reservation("0", idMed, 3);
							std::cout << "Media retourne.\n" << std::endl;
						}
						else if(id2act.compare("quitter") == 0){
							std::cout << "Abortion de la procedure de retour de media\n" << std::endl;
						}
					}
					else if(choix == 6){
						//info client
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
					else if(choix == 7){
						//info ressource
						infoRessource(res, 0);
					}
					else if(choix == 8){
						//recherche
						recherche(res, 0);
					}
					std::cout << "Quelle action souhaitez vous realiser :\n\t(1) modification utilisateur\n\t(2) modification ressource\n\t(3) emprunt\n\t(4) reservation\n\t(5) retour\n\t(6) info client\n\t(7) info ressource\n\t(8) recherche\n\t(9) quitter" << std::endl;
					std::cin >> choix;
				}
				std::cout << "Au revoir " << uti->getAdmin(id) << ".\n" << std::endl;
			}
			else if(id > 0){ //droits client
				id = id - 1;
				std::cout << "Authentification reussie (compte Client)." << std::endl
						  << "Bonjour " << uti->getClient(id) << ", quelle action souhaitez vous realiser :\n\t(1) reservation\n\t(2) infoperso\n\t(3) recherche\n\t(4)) quitter"  << std::endl;
				std::cin >> choix;
				while(choix != 4/*5*/){
					while(choix != 1 && choix != 2 && choix != 3 /*&& choix != 4*/){
						std::cout << "Choix incorrect, merci de reessayer :\n\t(1) reservation\n\t(2) infoperso\n\t(3) recherche\n\t(4) quitter" << std::endl;
						std::cin >> choix;
					}
					if(choix == 1){
						//reservation
						reservation(id, res, uti, 1);
					}
					else if(choix == 2){
						//infoperso
						res->checkVersion();
						uti->infoClient(id);
					}
					else if(choix == 3){
						//recherche
						recherche(res, 1);
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
			recherche(res, 1);
		}
		else{ //a enlever pour la version finale
			std::cout << "Erreur, ce cas ne devrait pas se produire." << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "Quelle action souhaitez vous realiser :\n\t(1) connexion\n\t(2) recherche\n\t(3) aide \n\t(4) quitter" << std::endl;
		std::cin >> action;
	}
	std::cout << "Fin du programme." << std::endl;
	res->effaceMemoire();
	uti->effaceMemoire();
	delete res;
	delete uti;
	exit(EXIT_SUCCESS);
}