#include "resNumerique.hpp"


resNumerique::resNumerique()
{
	format = "inconnu";
	taille = 0;
	path = "inconnu";
}

resNumerique::resNumerique( std::string _format, int _taille, std::string _path)
{
	format = _format;
	taille = _taille;
	path = _path;
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