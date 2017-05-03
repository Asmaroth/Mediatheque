#include "dvd.hpp"


dvd::dvd()
{
	nbrPiste = 0;
	nomPiste.push_back("inconnu");
	id = '0';
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
    type = "DVD";
}

dvd::dvd(int _nbrPiste, std::string _nomPiste,std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt)
{
	nbrPiste = _nbrPiste;
	nomPiste.push_back(_nomPiste);
	id = _id;
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
	type = "DVD";
}

dvd::~dvd(){}

void dvd::setNbrPiste (int _nbrPiste)
{
	nbrPiste = _nbrPiste;
}

int dvd::getNbrPiste ()
{
	return nbrPiste;
}

void dvd::setNomPiste (std::string _nomPiste, int _nbrPiste)
{
	nomPiste[_nbrPiste] = _nomPiste;
}
std::string dvd::getNomPiste (int _nbrPiste)
{
	return nomPiste[_nbrPiste];
}

std::string dvd::getPiste()
{
	for ( int i = 0; i < nomPiste.size(); i++)
  		return nomPiste[i];
}
void dvd::info ()
{
	std::cout << "Ce dvd contient " << getNbrPiste() << " pistes " << "dont les noms sont  " << getPiste() <<  std::endl;
}
