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


void ressources::createRevues(std::string _buf, revues *rev)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	std::stringstream ss2(data[8]);
	for( int i = 0 ; i < str2int(data[7]); i++ )
	{
		getline(ss2,str,',');
		rev->setNomArticle(str);
	}
	rev->setId(0);
	rev->setTitre(data[0]);
	rev->setAuteur(data[1]);
	rev->setAnnee(str2int(data[2]));
	rev->setDisponible(str2int(data[3]));
	rev->setDureeEmprunt(str2int(data[4]));
	rev->setDateEmprunt(str2int(data[5]));
	rev->setEditeur(data[6]);
	rev->setNbrArticle(str2int(data[7]));

}

/*void ressources::createCd(std::string _buf, cd *cd)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	cd->setId(0);
	cd->setTitre(data[0]);
	cd->setAuteur(data[1]);
	cd->setAnnee(str2int(data[2]));
	cd->setDisponible(str2int(data[3]));
	cd->setDureeEmprunt(str2int(data[4]));
	cd->setDateEmprunt(str2int(data[5]));
	cd->setDuree(str2int(data[6]));
	cd->setNbrPiste(str2int(data[7]);
	cd->setMaisonDisque(data[8]);
	cd->setTitrePiste(data[9]);
	cd->setNote(str2int(data[10]));
}

void ressources::createDvd(std::string _buf, dvd *dvd)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	dvd->setId(0);
	dvd->setTitre(data[0]);
	dvd->setAuteur(data[1]);
	dvd->setAnnee(str2int(data[2]));
	dvd->setDisponible(str2int(data[3]));
	dvd->setDureeEmprunt(str2int(data[4]));
	dvd->setDateEmprunt(str2int(data[5]));
	dvd->setDuree(str2int(data[6]));
	dvd->setNbrPiste(str2int(data[7]);
	dvd->setNomPiste(data[8]);
}

void ressources::createResNumerique(std::string _buf, resNumerique *resNum)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	resNum->setId(0);
	resNum->setTitre(data[0]);
	resNum->setAuteur(data[1]);
	resNum->setAnnee(str2int(data[2]));
	resNum->setDisponible(str2int(data[3]));
	resNum->setDureeEmprunt(str2int(data[4]));
	resNum->setDateEmprunt(str2int(data[5]));
	resNum->setFormat((data[6]));
	resNum->setTaille(str2int(data[7]);
	resNum->setPath(data[8]);
}

void ressources::createVhs(std::string _buf, vhs *vhs)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	vhs->setId(0);
	vhs->setTitre(data[0]);
	vhs->setAuteur(data[1]);
	vhs->setAnnee(str2int(data[2]));
	vhs->setDisponible(str2int(data[3]));
	vhs->setDureeEmprunt(str2int(data[4]));
	vhs->setDateEmprunt(str2int(data[5]));
	vhs->setDuree(str2int(data[6]));
	vhs->setMaisonProduction(data[7]);
	vhs->setNote(str2int(data[9]));
}

void ressources::createPeinture(std::string _buf, peinture *ptr)
{
	std::string str;
	std::string data[NBR_DATA_LIVRE];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_LIVRE ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	ptr->setId(0);
	ptr->setTitre(data[0]);
	ptr->setAuteur(data[1]);
	ptr->setAnnee(str2int(data[2]));
	ptr->setDisponible(str2int(data[3]));
	ptr->setDureeEmprunt(str2int(data[4]));
	ptr->setDateEmprunt(str2int(data[5]));
	ptr->setHauteur(str2int(data[6]));
	ptr->setLongueur(str2int(data[7]));
}*/

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
  			else if(mediaType == 2){
				//creation d'une revue
				std::cout << "Creation d'une revues." << std::endl;
				revues *rev = new revues();
				printf("coucou toi \n");
				createRevues(buf,rev);
				printf("bha voilaaaa \n");
				medias.push_back(rev);
				mediaSave.push_back(rev);
				nbrRessource++;
				stock++;
			}/*
			else if(mediaType == 3){
				//creation d'un cd 
				std::cout << "Creation d'un cd." << std::endl;
				cd *cd = new cd();
				createCd(buf,cd);
				medias.push_back(cd);
				mediaSave.push_back(cd);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 4)
			{
				//creation d'un dvd
				std::cout << "Creation d'un dvd." << std::endl;
				dvd *dvd = new dvd();
				createDvd(buf,dvd);
				medias.push_back(dvd);
				mediaSave.push_back(dvd);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 5)
			{
				//creation d'une ResNumerique
				std::cout << "Creation d'une Ressource Numerique." << std::endl;
				resNumerique *resNum = new resNumerique();
				createResNumerique(buf,resNum);
				medias.push_back(resNum);
				mediaSave.push_back(resNum);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 6 )
			{
				//creation d'une vhs
				std::cout << "Creation d'une cassette vhs." << std::endl;
				vhs *vhs = new vhs();
				createVhs(buf,vhs);
				medias.push_back(vhs);
				mediaSave.push_back(vhs);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 7)
			{
				//creation d'une peinture
				std::cout << "Creation d'une peinture." << std::endl;
				peinture *ptr = new peinture();
				createPeinture(buf,ptr);
				medias.push_back(ptr);
				mediaSave.push_back(ptr);
				nbrRessource++;
				stock++;
			}*/
			else
				std::cout << "Impossible de créer le media : " << buf << std::endl;
    	}
    	list();
    }

}

void ressources::show(std::string _id){
	int flag = 0;
	for (int i = 0 ; i < medias.size() ; i++){
		if (medias[i]->getId().compare(_id) == 0){
			medias[str2int(_id)]->info();
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