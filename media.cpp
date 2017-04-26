#include "media.hpp"

media::media(){
	id = 0;
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
}

media::media(int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt){
	id = _id;
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
}

media::~media(){};

void media::reserver(){
	disponible = 0;
}

void media::emprunter(){
	disponible = 1;
}

void media::rendre(){
	disponible = 3;
}

void media::setId(int _id){
	id = _id;
}

int media::getId(){
	return id;
}

void media::setTitre (std::string _titre){
	titre = _titre;
}

std::string media::getTitre (){
	return titre;
}

void media::setAuteur (std::string _auteur){
	auteur = _auteur;
}

std::string media::getAuteur (){
	return auteur;
}

void media::setAnnee (int _annee){
	annee = _annee;
}

int media::getAnnee (){
	return annee;
}

void media::setDisponible (int _disponible){
	disponible = _disponible;
}

int media::getDisponible (){
	return disponible;
}

void media::setDureeEmprunt (int _dureeEmprunt){
	dureeEmprunt = _dureeEmprunt;
}

int media::getDureeEmprunt (){
	return dureeEmprunt;
}

void media::setDateEmprunt (int _dateEmprunt){
	dateEmprunt = _dateEmprunt;
}

int media::getDateEmprunt (){
	return dateEmprunt;
}

void media::setIdClient(int _idClient){
	idClient = _idClient;
}

int media::getIdClient(){
	return idClient;
}

void media::info(){
	std::string str;
	if (disponible == 0)
		str = "réservé";
	else if (disponible == 1)
		str = "emprunté";
	else if (disponible == 2)
		str = "indisponible";
	else
		str = "disponible";
	std::cout << "(" << id << ") " << titre << ", de " << auteur << " est paru en " << annee << ". Il est actuellement " << str << "." << std::endl;
}

void media::infoAdmin(){
	std::cout << "Ce media a été emprunté par (" << idClient << ") le " << dateEmprunt << " pour une durée maximale de " << dureeEmprunt << ".\n" << std::endl;	
	info();
}