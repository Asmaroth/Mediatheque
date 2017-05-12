#include "livre.hpp"
#include "ressources.hpp"


livre::livre()
{
	nbrPage = 0;
	collection = "inconnu";
	resume = "non existant";
	note = 0;
	id = "L0";
	titre = "Aucun";
    auteur = "Inconnu";
    type = "livre";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = 0;
}

livre::~livre(){}

livre::livre(std::string _id, const char *_titre, const char *_auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, const char *_collection, const char *_resume, int _note)
{
	nbrPage = _nbrPage;
	collection = _collection;
	resume = _resume;
	note = _note;
	id = _id;
	titre = _titre;
	auteur = _auteur;
	type = "livre";
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
}

livre::livre(std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, std::string _collection, std::string _resume, int _note)
{
	nbrPage = _nbrPage;
	collection = _collection;
	resume = _resume;
	note = _note;
	id = _id;
	titre = _titre;
	auteur = _auteur;
	type = "Livre";
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
		  	  << "La note des lecteurs est de : " << getNote() << "/5" << std::endl
		  	  << "En voici un resume: " << getResume() << std::endl;
}

void livre::infoAdmin()
{
	media::infoAdmin();
	std::cout << "Ce livre est de la collection " << getCollection() << " et contient " << getPage() << " pages." << std::endl
		  	  << "La note des lecteurs est de : " << getNote() << "/5" << std::endl
		  	  << "En voici un resume: " << getResume() << std::endl;

}

std::string livre::infoToSave(){
	std::string str = getId() + ';' + getTitre() + ';' + getAuteur()  + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';'/* + getIdClient() + ';'*/ + int2str(getPage()) + ';' + getCollection() + ';' + getResume() + ';' + int2str(getNote());
	return str;
}