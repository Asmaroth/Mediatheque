#include "revues.hpp"

revues::revues()
{
	editeur = "inconnu";
	nbrArticle = 0;
	nomArticle.push_back("inconnu");
}

revues::~revues(){}

revues::revues(std::string _editeur, int _nbrArticle, std::string _nomArticle)
{
	editeur = _editeur;
	nbrArticle = _nbrArticle;
	nomArticle.push_back(_nomArticle);
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
	std::cout << "Cette revue est de la produite par " << getEditeur() << " et contient " << getNbrArticle() << " Article(s)." << std::endl
		  	  << "Le nom des articles est: " << getArticle() << std::endl;
 }