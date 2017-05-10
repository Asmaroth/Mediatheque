#include "peinture.hpp"

peinture::peinture()
{
	hauteur = 0;
	longueur = 0;
	id = '0';
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
    type = "peinture";
}

peinture::peinture(int _hauteur, int _longueur,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt)
{
	hauteur = _hauteur;
	longueur = _longueur;
	id = _id;
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
	type = "peinture";
}

peinture::~peinture(){}

void peinture::setHauteur (int _hauteur)
{
	hauteur = _hauteur;
}

int peinture::getHauteur ()
{
	return hauteur;
}

void peinture::setLongueur (int _longueur)
{
	longueur = _longueur;
}

int peinture::getLongueur ()
{
	return longueur;
}

void peinture::info ()
{
	std::cout << "Cette peinture est de " << getHauteur() << " m de hauteur et " << getLongueur() << "m de longueur." << std::endl;
}

std::string peinture::infoToSave(){
    std::string str = getId() + ';' + getTitre() + ';' + getAuteur()  + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';' /*+ int2str(getIdClient()) + ';'*/ + int2str(getHauteur()) + ';' + int2str(getLongueur());
    return str;
}