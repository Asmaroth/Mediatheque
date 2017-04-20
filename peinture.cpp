#include "peinture.hpp"

peinture::peinture()
{
	hauteur = 0;
	longueur = 0;
}

peinture::peinture(int _hauteur, int _longueur)
{
	hauteur = _hauteur;
	longueur = _longueur;
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