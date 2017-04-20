#include "dvd.hpp"


dvd::dvd()
{
	nbrPiste = 0;
	nomPiste.push_back("inconnu");
}

dvd::dvd(int _nbrPiste, std::string _nomPiste)
{
	nbrPiste = _nbrPiste;
	nomPiste.push_back(_nomPiste);
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
