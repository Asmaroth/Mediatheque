#include "mediatheque.hpp"


mediatheque::mediatheque(){
	nom = "Inconnu";
}
mediatheque::mediatheque(std::string _nom){
	nom = _nom;
}
void mediatheque::setNom(std::string _nom){
	nom = _nom;
}

mediatheque::~mediatheque(){}

std::string mediatheque::getNom(){
	return nom;
}
void mediatheque::info(){
	std::cout<<"Mediatheque "<<nom<<std::endl; 
}