#include "resNumerique.hpp"


resNumerique::resNumerique()
{
	format = "inconnu";
	taille = 0;
	path = "inconnu";
	id = '0';
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
    type = "ressourcenumerique";
}

resNumerique::resNumerique( std::string _format, int _taille, std::string _path,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt)
{
	format = _format;
	taille = _taille;
	path = _path;
	id = _id;
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
	type = "ressourcenumerique";
}

resNumerique::~resNumerique(){}

void resNumerique::setFormat (std::string _format)
{
	format = _format;
}

std::string resNumerique::getFormat ()
{
	return format;
}

void resNumerique::setTaille (int _taille)
{
	taille = _taille;
}

int resNumerique::getTaille ()
{
	return taille;
}

void resNumerique::setPath (std::string _path)
{
	path = _path; 
}

std::string resNumerique::getPath ()
{
	return path;
}

void resNumerique::info ()
{
	std::cout << "Cette ressource Numerique a pour format " << getFormat() << " et est de taille " << getTaille()<< std::endl
			  << "Son chemin est " << getPath() << std::endl;
}

std::string resNumerique::infoToSave(){
    std::string str = getId() + ';' + getTitre() + ';' + getAuteur()  + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';' /*+ int2str(getIdClient()) + ';'*/ + getFormat() + ';' + int2str(getTaille()) + ';' + getPath();
    return str;
}