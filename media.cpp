#include "media.hpp"

media::media(){
	id = 0;
	titre = "Aucun";
    auteur = "Inconnu";
    type = "Indéfini";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = 0;
}

media::media(int _id, std::string _titre, std::string _auteur, std::string _type, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt){
	id = _id;
	titre = _titre;
	auteur = _auteur;
	type = _type;
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

void media::setType (std::string _type){
	type = _type;
}

std::string media::getType (){
	return type;
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

std::string media::int2str(int nbr)
{
	std::stringstream ss;
	ss << nbr;
	return ss.str();
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

std::string media::infoToSave(){
	std::string str = int2str(getId()) + ';' + getTitre() + ';' + getAuteur() + ';' + getType() + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';' + int2str(getIdClient());
	return str;
}