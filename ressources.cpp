#include "ressources.hpp"

    
ressources::ressources()
{
 nbrRessource = 0;
 typeRessource.push_back("aucun");
 stock = 0;
}

ressources::~ressources(){ 	//ATTENTION ICI : mauvaise idée de faire ça ? Detruit bien toutes les ressources a l'interieur, mais est-ce que ca detruit l'objet ressource lui meme ????
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

void ressources::list(){
	if(medias.size() != 0)
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

std::string ressources::int2str(int nbr)
{
	std::stringstream ss;
	ss << nbr;
	return ss.str();
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
	lvr->setAnnee(str2int(data[2]));
	lvr->setDisponible(str2int(data[3]));
	lvr->setDureeEmprunt(str2int(data[4]));
	lvr->setDateEmprunt(str2int(data[5]));
	lvr->setPage(str2int(data[6]));
	lvr->setCollection(data[7]);
	lvr->setResume(data[8]);
	lvr->setNote(str2int(data[9]));
}

void ressources::load(const char *filename)
{
    std::string buf;
	std::ifstream myFile(filename);
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
    			mediaSave.push_back(lvr);
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
    	list();
    }

}

void ressources::show(int _id){
	int flag = 0;
	for (int i = 0 ; i < medias.size() ; i++){
		if (medias[i]->getId() == _id){
			medias[_id]->info();
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "Aucun media ne correspond à cet ID" << std::endl;
}

void ressources::save(const char *filename){
	std::ifstream testFile(filename);
	char choix = -1;
	if(testFile.is_open()){
		while (choix != 121 && choix != 110){ //121 = y 110 = n
			std::cout << "Le fichier existe déjà, êtes vous sur de vouloir ecraser les données ? y/n : ";
			std::cin >> choix;
		}
		if(choix == 110){
			std::cout << "Abandon de la sauvegarde" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	std::ofstream myFile(filename/*, ios::out | std::trunc*/);
	std::cout << "Creation d'un fichier de sauvegarde : " << filename << std::endl;
	for (int i = 0 ; i < medias.size() ; i++){
		myFile << medias[i]->infoToSave() << std::endl;
	}
}

void ressources::clear(){
	medias.swap(mediaSave);
}

void ressources::deleteMedia(int _id){
	if(1 <= _id && _id <= medias.size()){
		delete medias[_id-1];
		medias.erase(medias.begin() + _id - 1);
	}
	else
		std::cout << "Impossible de detruire le media d'identifiant " << _id << std::endl;
}

void ressources::reset(){
	for (int i = 0 ; i < medias.size() ; i++){
		delete medias[i];
	}
	medias.clear();
	for (int i = 0 ; i < mediaSave.size() ; i++){
		delete mediaSave[i];
	}
	mediaSave.clear();
}