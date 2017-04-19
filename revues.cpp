#include "revues.hpp"

revues::revues()
{
	editeur = "inconnu";
	nbrArticle = 0;
	nomArticle = "inconnu";
}

revues::~revues(){}

revues::revues(std::string _editeur, int _nbrArticle, std::string _nomArticle)
{
	editeur = _editeur;
	nbrArticle = _nbrArticle;
	nomArticle = _nomArticle;
}

void setEditeur(std::string _editeur)
{
	editeur = _editeur;
}

std::string getEditeur()
{
	return editeur;
}

void setNbrArticle(int _nbrArticle)
{
	nbrArticle = _nbrArticle;
}

int getNbrArticle()
{
	return nbrArticle;
}

 void setNomArticle(std::string _nomArticle, int _idArticle)
 {
 	nomArticle = _nomArticle;
 }

 std::string getNomArticle(int _idArticle)
 {
 	return _nomArticle;
 }

 void info()
 {
	std::cout << "Cette revue est de la produite par " << getEditeur() << " et contient " << getNbrArticle() << " Article(s)." << std::endl
		  	  << "Le nom des articles est: " << getNomArticle() << std::endl;
 }