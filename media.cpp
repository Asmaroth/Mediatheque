#include "media.hpp"

media::media(){
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    stock = 0;
    dureeEmprunt = -1;
    dateEmprunt = -1;
}

media::media(std::string _titre, std::string _auteur, int _annee, int _disponible, int _stock, int _dureeEmprunt, int _dateEmprunt){
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	stock = _stock;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
}

media::~media(){};

void media::reserver(){
	disponible = 0;
}

void media::emprunter(){
	disponible = 1;
	stock--;
}

void media::rendre(){
	disponible = 3;
	stock++;
}