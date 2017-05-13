#include "admin.hpp"

admin::admin(){
	id = "200";
    nom = "Inconnu";
    prenom = "Inconnu";
    initTableau(resReservee, LIMITE_RESERVATION);
    resRendue;
    initTableau(resEmpruntee, LIMITE_EMPRUNT);
    initTableau(dateEmprunt, LIMITE_EMPRUNT);
    mdp = "aaaaaaaa"; //8 a
}

/*admin::admin(int _id, std::string _nom, std::string _prenom, std::string *_resReservee, media *_resRendue, std::string _resEmpruntee, int *_dateEmprunt, std::string _mdp, std::string _mdp){
	id = _id
    nom = _nom;
    prenom = _prenom;
    initTableau(resReservee, LIMITE_RESERVATION);
    initTableau(resEmpruntee, LIMITE_EMPRUNT);
    initTableau(dateEmprunt, LIMITE_EMPRUNT);
    mdp = "aaaaaaaa"; //8 a
}*/

admin::~admin(){}

void admin::setMdp(std::string _mdp){
	mdp = _mdp;
}

std::string admin::getMdp(){
	return mdp;
}

void admin::info(){
	std::cout << "(" << id << ") ADMIN " << nom << " " << prenom << std::endl;
}


void reset ();