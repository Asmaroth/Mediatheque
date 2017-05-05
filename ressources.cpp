#include "ressources.hpp"

    
ressources::ressources()
{
 nbrRessource = 0;
 stock = 0;
}

ressources::~ressources(){ 	//ATTENTION ICI : mauvaise idée de faire ça ? Detruit bien toutes les ressources a l'interieur, mais est-ce que ca detruit l'objet ressource lui meme ????
	for (int i = 0 ; i < medias.size() ; i++)
		delete medias[i];
}

ressources::ressources(int _nbrRessource , std::string _nomRessource , int _stock) //useless 
{
 nbrRessource = _nbrRessource;
 typeRessource.push_back(_nomRessource);
 stock = _stock;
}

int ressources::getNbrRessource() 
{
 return medias.size();
}

void ressources::setTypeRessource(std::string _nomRessource) 
{
 typeRessource.push_back( _nomRessource );
} 

std::string ressources::getTypeRessource()
{
	std::string str;
	for ( int i = 0; i < typeRessource.size(); i++)
  		str = str + ", " + typeRessource[i];
  	str = str + ".";
  	return str;
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
	else
		std::cout << "Aucun media repertorie." << std::endl;
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
	lvr->setId(data[0]);
	lvr->setTitre(data[1]);
	lvr->setAuteur(data[2]);
	lvr->setAnnee(str2int(data[3]));
	lvr->setDisponible(str2int(data[4]));
	lvr->setDureeEmprunt(str2int(data[5]));
	lvr->setDateEmprunt(str2int(data[6]));
	lvr->setPage(str2int(data[7]));
	lvr->setCollection(data[8]);
	lvr->setResume(data[9]);
	lvr->setNote(str2int(data[10]));
}


void ressources::createRevues(std::string _buf, revues *rev)
{
	std::string str;
	std::string data[NBR_DATA_REVUES];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_REVUES ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	std::stringstream ss2(data[12]);
	for( int i = 0 ; i < str2int(data[12]); i++ )
	{
		getline(ss2,str,',');
		rev->setNomArticle(str);
	}
	rev->setId(data[0]);
	rev->setTitre(data[1]);
	rev->setAuteur(data[2]);
	rev->setAnnee(str2int(data[3]));
	rev->setDisponible(str2int(data[4]));
	rev->setDureeEmprunt(str2int(data[5]));
	rev->setDateEmprunt(str2int(data[6]));
	rev->setPage(str2int(data[7]));
	rev->setCollection(data[8]);
	rev->setResume(data[9]);
	rev->setNote(str2int(data[10]));
	rev->setEditeur(data[11]);
	rev->setNbrArticle(str2int(data[12]));

}

void ressources::createCd(std::string _buf, cd *cd)
{
	std::string str;
	std::string data[NBR_DATA_CD];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_CD ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	std::stringstream ss2(data[8]);
	for (int i = 0 ; i < str2int(data[8]); i++)
	{
		getline(ss2, str , ',');
		cd->setTitrePiste(str);
	}

	cd->setId(data[0]);
	cd->setTitre(data[1]);
	cd->setAuteur(data[2]);
	cd->setAnnee(str2int(data[3]));
	cd->setDisponible(str2int(data[4]));
	cd->setDureeEmprunt(str2int(data[5]));
	cd->setDateEmprunt(str2int(data[6]));
	cd->setDuree(str2int(data[7]));
	cd->setNbrPiste(str2int(data[8]));
	cd->setMaisonDisque(data[9]);
	//cd->setTitrePiste(data[10]);
	cd->setNote(str2int(data[10]));
}

void ressources::createDvd(std::string _buf, dvd *dvd)
{
	std::string str;
	std::string data[NBR_DATA_DVD];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_DVD ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	std::stringstream ss2(data[10]);
	for (int i = 0 ; i < str2int(data[10]); i++)
	{
		getline(ss2, str , ',');
		dvd->setNomPiste(str);
	}
	dvd->setId(data[0]);
	dvd->setTitre(data[1]);
	dvd->setAuteur(data[2]);
	dvd->setAnnee(str2int(data[3]));
	dvd->setDisponible(str2int(data[4]));
	dvd->setDureeEmprunt(str2int(data[5]));
	dvd->setDateEmprunt(str2int(data[6]));
	dvd->setDuree(str2int(data[7]));
	dvd->setMaisonProduction(data[8]);
	dvd->setNote(str2int(data[9]));
	dvd->setNbrPiste(str2int(data[10]));
}

void ressources::createResNumerique(std::string _buf, resNumerique *resNum)
{
	std::string str;
	std::string data[NBR_DATA_RESNUM];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_RESNUM ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	resNum->setId(data[0]);
	resNum->setTitre(data[1]);
	resNum->setAuteur(data[2]);
	resNum->setAnnee(str2int(data[3]));
	resNum->setDisponible(str2int(data[4]));
	resNum->setDureeEmprunt(str2int(data[5]));
	resNum->setDateEmprunt(str2int(data[6]));
	resNum->setFormat((data[7]));
	resNum->setTaille(str2int(data[8]));
	resNum->setPath(data[9]);
}

void ressources::createVhs(std::string _buf, vhs *vhs)
{
	std::string str;
	std::string data[NBR_DATA_VHS];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_VHS ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	vhs->setId(data[0]);
	vhs->setTitre(data[1]);
	vhs->setAuteur(data[2]);
	vhs->setAnnee(str2int(data[3]));
	vhs->setDisponible(str2int(data[4]));
	vhs->setDureeEmprunt(str2int(data[5]));
	vhs->setDateEmprunt(str2int(data[6]));
	vhs->setDuree(str2int(data[7]));
	vhs->setMaisonProduction(data[8]);
	vhs->setNote(str2int(data[9]));
}

void ressources::createPeinture(std::string _buf, peinture *ptr)
{
	std::string str;
	std::string data[NBR_DATA_PTR];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_PTR ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	ptr->setId(data[0]);
	ptr->setTitre(data[1]);
	ptr->setAuteur(data[2]);
	ptr->setAnnee(str2int(data[3]));
	ptr->setDisponible(str2int(data[4]));
	ptr->setDureeEmprunt(str2int(data[5]));
	ptr->setDateEmprunt(str2int(data[6]));
	ptr->setHauteur(str2int(data[7]));
	ptr->setLongueur(str2int(data[8]));
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
    			//std::cout << "Creation d'un livre." << std::endl;
    			livre *lvr = new livre();
    			createLivre(buf, lvr);
    			medias.push_back(lvr);
    			mediaSave.push_back(lvr);
    			nbrRessource++;
    			stock++;
    		}
  			else if(mediaType == 2){
				//creation d'une revue
				//std::cout << "Creation d'une revue." << std::endl;
				revues *rev = new revues();
				createRevues(buf,rev);
				medias.push_back(rev);
				mediaSave.push_back(rev);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 3){
				//creation d'un cd 
				//std::cout << "Creation d'un cd." << std::endl;
				cd *CD = new cd();
				createCd(buf,CD);
				medias.push_back(CD);
				mediaSave.push_back(CD);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 4)
			{
				//creation d'un dvd
				//std::cout << "Creation d'un dvd." << std::endl;
				dvd *DVD = new dvd();
				createDvd(buf,DVD);
				medias.push_back(DVD);
				mediaSave.push_back(DVD);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 5)
			{
				//creation d'une ResNumerique
				//std::cout << "Creation d'une Ressource Numerique." << std::endl;
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
				//std::cout << "Creation d'une cassette vhs." << std::endl;
				vhs *VHS = new vhs();
				createVhs(buf,VHS);
				medias.push_back(VHS);
				mediaSave.push_back(VHS);
				nbrRessource++;
				stock++;
			}
			else if(mediaType == 7)
			{
				//creation d'une peinture
				//std::cout << "Creation d'une peinture." << std::endl;
				peinture *ptr = new peinture();
				createPeinture(buf,ptr);
				medias.push_back(ptr);
				mediaSave.push_back(ptr);
				nbrRessource++;
				stock++;
			}
			else
				std::cout << "Impossible de créer le media : " << buf << std::endl;
    	}
    	//list();
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
	char choix = 0; 												//il y avait -1, normal ??
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

void ressources::rechercheGene(std::string _str){

}
void ressources::rechercheType(std::string _str, int _type){

}
void ressources::rechercheChamp(std::string _str, int _type){
	
}