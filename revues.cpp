#include "revues.hpp"

revues::revues()
{
	editeur = "inconnu";
	nbrArticle = 0;
	nomArticle.push_back("inconnu");
	nbrPage = 0;
	collection = "inconnu";
	resume = "non existant";
	note = 0;
	id = '0';
	titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = 0;
    type = "Revue";
}

revues::~revues(){}

revues::revues(std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, std::string _collection, std::string _resume, int _note, std::string _editeur, int _nbrArticle, std::string _nomArticle)
{
	editeur = _editeur;
	nbrArticle = _nbrArticle;
	nomArticle.push_back(_nomArticle);
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
	type = "Revue";
}

void revues::setEditeur(std::string _editeur)
{
	editeur = _editeur;
}

std::string revues::getEditeur()
{
	return editeur;
}

void revues::setNbrArticle(int _nbrArticle)
{
	nbrArticle = _nbrArticle;
}

int revues::getNbrArticle()
{
	return nbrArticle;
}

 void revues::setNomArticle(std::string _nomArticle, int _idArticle)
 {
 	nomArticle[_idArticle] = _nomArticle;
 }

 void revues::setNomArticle (std::string _nomArticle){
 	nomArticle.push_back(_nomArticle);
 }

 std::string revues::getNomArticle(int _idArticle)
 {
 	return nomArticle[_idArticle];
 }

 std::string revues::getArticle()
 {
 		for ( int i = 0; i < nomArticle.size(); i++)
  		return nomArticle[i];
 }

 void revues::info()
 {
 	livre::info();
	std::cout << "Cette revue est produite par " << getEditeur() << " et contient " << getNbrArticle() << " Article(s)." << std::endl
		  	  << "Le nom des articles est : " << getArticle() << std::endl;
 }

void revues::infoAdmin()
{
	livre::infoAdmin();
	std::cout << "Cette revue est produite par " << getEditeur() << " et contient " << getNbrArticle() << " Article(s)." << std::endl
		  	  << "Le nom des articles est : " << getArticle() << std::endl;
}