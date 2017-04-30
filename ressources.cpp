#include "ressources.hpp"

    
ressources::ressources()
{
 nbrRessource = 0;
 typeRessource.push_back("aucun");
 stock = 0;
}

ressources::~ressources(){
	for (int i = 0 ; i < medias.size() ; i++)
		delete medias[i];
}

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
	std::cout << "il y a " << getNbrRessource() << " ressources dont " << getStock() << " en stock" << std::endl
		  	  << "Elles sont de type : " << getTypeRessource() << "." << std::endl;
}

void ressources::infoContenu(){
	for (int i = 0 ; i < medias.size() ; i++)
		std:: cout << '(' << medias[i]->getId() << ") " << medias[i]->getType() << " : " << medias[i]->getTitre() << std::endl;
}

int ressources::str2int(std::string str)
{
	int result;
	std::stringstream ss(str);
	if(!(ss>>result))
		return 0;
	return result;
}

void ressources::createLivre(std::string _buf, livre *lvr)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	lvr->setId(0);
	lvr->setTitre(data[0]);
	lvr->setAuteur(data[1]);
}

void ressources::load(const char *filename)
{
    std::string buf;
	std::ifstream myFile(filename);
	media *_medias;
	int mediaType;
    if(!myFile.is_open()){
    	std::cout << "Can't read file : " << filename << std::endl;
    }
    else{
    	getline(myFile, buf);
    	mediaType = buf[1] - 48;
    	while (getline(myFile, buf)){
    		if (mediaType == 1){
    			//creation d'un livre
    			std::cout << "Creation d'un livre." << std::endl;
    			livre *lvr = new livre();
    			createLivre(buf, lvr);
    			medias.push_back(lvr);
    			nbrRessource++;
    			stock++;
    		}
  			/*else if(mediaType == 2){
				//creation d'une revue
				medias.push_back(createRevue(buf));
				std::cout << "Creation d'un admin." << std::endl;
				nbrUtilisateurs++;
			}
			else if(mediaType == 3){
				//etc...
			}*/
			else
				std::cout << "Impossible de créer le media : " << buf << std::endl;
    	}
    	infoContenu();
    }

}