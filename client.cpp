#include "client.hpp"


void client::initTableau(std::string *tab, int taille){ //utile ??
	for (int i = 0 ; i < taille ; i++)
		tab[i] = "Aucun";
}

/*void client::initTableau(int tab, int taille){ //utile ??
	for (int i = 0 ; i < taille ; i++)
		tab[i] = 0;
}*/

client::client(){
	id = "100";
    nom = "Inconnu";
    prenom = "Inconnu";
    initTableau(resReservee, LIMITE_RESERVATION);
    initTableau(resEmpruntee, LIMITE_EMPRUNT);
    initTableau(dateEmprunt, LIMITE_EMPRUNT);
}

/*client::client(std::string _id, std::string _nom, std::string _prenom, std::string *_resReservee, media *_resRendue, std::string *_resEmpruntee, int *_dateEmprunt){
	std::string str;
	std::stringstream ss1(_resReservee);
	std::stringstream ss2(_resRendue);
	std::stringstream ss3(_resEmpruntee);
	std::stringstream ss4(_dateEmprunt);
	int i = 0;
	id = _id;
    nom = _nom;
    prenom = _prenom;
    while(getline(ss1, str, ','))
    	resReservee[i++] = str;
    i = 0;
    while(getline(ss2, str, ','))
    	resRendue.push_back(str);
    while(getline(ss3, str, ','))
    	resEmpruntee[i++] = str;
    i = 0;
    while(getline(ss4, str, ','))
    	dateEmprunt[i++] = str;
}*/

client::~client(){}

void client::setId(std::string _id){
	id = _id;
}

std::string client::getId (){
	return id;
}

void client::setNom(std::string _nom){
	nom = _nom;
}

std::string client::getNom (){
	return nom;
}

void client::setPrenom(std::string _prenom){
	prenom = _prenom;
}

std::string client::getPrenom(){
	return prenom;
}

void client::setResReservee (std::string _resReservee, int _idResReservee){
	resReservee[_idResReservee] = _resReservee;
}

std::string client::getResReservee (){
	std::string str;
	for (int i = 0 ; i < LIMITE_RESERVATION ; i++){
		str = str + resReservee[i];
		if (i + 1 < LIMITE_RESERVATION)
			str = str + ", ";
	}
	return str;
}

std::string client::getResReservee (int _idResReservee){
	return resReservee[_idResReservee];
}

void client::setResRendue (media *_resRendue){
	resRendue.push_back(_resRendue);
}

std::string client::getResRendue (){
	std::string str;
	for(int i = 0 ; i < resRendue.size() ; i++)
		str = str + ", (" + resRendue[i]->getId() + ") " + resRendue[i]->getTitre();
	str = str + ".";
	return str;
}

std::string client::getResRendue (int _idResRendue){
	return "(" + resRendue[_idResRendue]->getId() + ") " + resRendue[_idResRendue]->getTitre();
}

void client::setResEmpruntee (std::string _resEmpruntee, int _idResEmpruntee){
	resEmpruntee[_idResEmpruntee] = _resEmpruntee;
}

std::string client::getResEmpruntee (){
	std::string str;
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		str = str + resEmpruntee[i];
		if (i + 1 < LIMITE_EMPRUNT)
			str = str + ", ";
		else
			str = str + ".";
	}
	return str;
}

std::string client::getResEmpruntee (int _idResEmpruntee){
	return resEmpruntee[_idResEmpruntee];
}

void client::setDateEmprunt (std::string _dateEmprunt, int _idDateEmprunt){
	dateEmprunt[_idDateEmprunt] = _dateEmprunt;
}

std::string client::getDateEmprunt (){
	std::string str;
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		str = str + dateEmprunt[i];
		if (i + 1 < LIMITE_EMPRUNT)
			str = str + ", ";
	}
	return str;
}

std::string client::getDateEmprunt (int _idDateEmprunt){
	return dateEmprunt[_idDateEmprunt];
}

void client::info (){
	std::cout << "(" << id << ") " << nom << " " << prenom << " a :\n\temprunte : " << getResEmpruntee() << "\n\tle : " << getDateEmprunt() << "\n\trendu : " << getResRendue() << "\n\treserve : " << getResReservee() << std::endl;
}

//void client::bye (); //devrait etre implémenté dans le main.cpp ?

//void client::load (std::string _file);
