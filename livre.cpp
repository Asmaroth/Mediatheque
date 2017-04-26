#include "livre.hpp"


livre::livre()
{
	nbrPage = 0;
	collection = "inconnu";
	resume = "non existant";
	note = 0;
	id = 0;
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
}

livre::~livre(){}

livre::livre(int _nbrPage, std::string _collection, std::string _resume, int _note, int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt)
{
	nbrPage = _nbrPage;
	collection = _collection;
	resume = _resume;
	note = _note;
	id = _id;
	titre = _titre;
	auteur = _auteur;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
}

void livre::setPage(int _nbrPage)
{
	nbrPage = _nbrPage;
}

int livre::getPage()
{
	return nbrPage;
}

void livre::setCollection(std::string _collection)
{
	collection = _collection;
}

std::string livre::getCollection()
{
	return collection;
} 

void livre::setResume(std::string _resume)
{
	resume = _resume;
}

std::string livre::getResume()
{
	return resume;
}

void livre::setNote(int _note)
{
	note = _note;
}

int livre::getNote()
{
	return note;
}

void livre::info()
{
	media::info();
	std::cout << "Ce livre est de la collection " << getCollection() << " et contient " << getPage() << " pages." << std::endl
		  	  << "La note des lecteurs est de: " << getNote() << std::endl
		  	  << "En voici un resume: " << getResume() << std::endl;
}

void livre::infoAdmin()
{
	media::infoAdmin();
	std::cout << "Ce livre est de la collection " << getCollection() << " et contient " << getPage() << " pages." << std::endl
		  	  << "La note des lecteurs est de: " << getNote() << std::endl
		  	  << "En voici un resume: " << getResume() << std::endl;

}