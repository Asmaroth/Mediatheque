#include "cd.hpp"


cd::cd()
{
	duree = 0;
	nbrPiste = 0;
	maisonDisque = "inconnu";
	titrePiste.push_back("inconnu");
	note = 0;

}

cd::cd(int _duree, int _nbrPiste, std::string _maisonDisque, std::string _titrePiste, int _note)
{
	duree = _duree;
	nbrPiste = _nbrPiste;
	maisonDisque = _maisonDisque;
	titrePiste.push_back(_titrePiste);
	note = _note;

}

cd::~cd(){}

void cd::setDuree(int _duree)
{
	duree = _duree;
}

int cd::getDuree()
{
	return duree;
}

void cd::setNbrPiste(int _nbrPiste)
{
	nbrPiste = _nbrPiste;
}

int cd::getNbrPiste()
{
	return nbrPiste;
}

void cd::setMaisonDisque(std::string _maisonDisque)
{
	maisonDisque = _maisonDisque;
}

std::string cd::getMaisonDisque()
{
	return maisonDisque;
}

void cd::setTitrePiste(std::string _titrePiste, int _idPiste)
{
	titrePiste[_idPiste] = _titrePiste;
}

std::string cd::getTitrePiste(int _idPiste)
{
	return titrePiste[_idPiste];
}

std::string cd::getTitre()
{
	for ( int i = 0; i < titrePiste.size(); i++)
  		return titrePiste[i];
}

void cd::setNote(int _note)
{
	note = _note;
}

int cd::getNote()
{
	return note;
}

void cd::info()
{
	std::cout << "Ce cd est d'une duree de " << getDuree() << " avec " << getNbrPiste() << " pistes." << " Les titres sont : " << getTitre() << std::endl
		  	  << "La maison de disque est: " << getMaisonDisque() << std::endl
		  	  << " Le cd a pour note " << getNote() << std::endl;

}
