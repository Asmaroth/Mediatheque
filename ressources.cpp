#include "ressources.hpp"

    
ressources::ressources()
{
 nbrRessource = 0;
 typeRessource.push_back("inconnu");
 stock = 0;
}

ressources::~ressources(){}

ressources::ressources(int _nbrRessource , std::string _nomRessource , int _stock)
{
 nbrRessource = _nbrRessource;
 typeRessource.push_back(_nomRessource);
 stock = _stock;
}

void ressources::setNbrRessource(int _nbrRessource)
{
 nbrRessource = _nbrRessource; 
}

int ressources::getNbrRessource()
{
 return nbrRessource;
}

void ressources::setTypeRessource(std::string _nomRessource)
{
 typeRessource.push_back( _nomRessource );
} 

std::string ressources::getTypeRessource()
{
	for ( int i = 0; i < typeRessource.size(); i++)
  		return typeRessource[i];
}

void ressources::setStock(int _stock)
{
 stock = _stock;
}

int ressources::getStock()
{
 return stock;
}
void ressources::info()
{
	std::cout << "il y a " << getNbrRessource() << " ressources " << "dont " << getStock() << " en stock" << std::endl
		  	  << "Elles sont de type: " << getTypeRessource() << std::endl;
}



