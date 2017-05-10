#include "ressources.hpp"

    
ressources::ressources()
{
 nbrRessource = 0;
 stock = 0;
}

ressources::~ressources(){}

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
    myFile.close();
}

void ressources::reload(){
	load("cd.txt");
	load("revues.txt");
	load("livre.txt");
	load("vhs.txt");
	load("dvd.txt");
	load("resNumerique.txt");
	load("peinture.txt");
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
		testFile.close();
		if(choix == 110){
			std::cout << "Abandon de la sauvegarde" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	std::ofstream myFile(filename, std::ios::out | std::ios::trunc);
	std::cout << "Creation d'un fichier de sauvegarde : " << filename << std::endl;
	for (int i = 0 ; i < medias.size() ; i++){
		myFile << medias[i]->infoToSave() << std::endl;
	}
	myFile.close();
}

void ressources::clear(){
	medias.swap(mediaSave);
}

void ressources::effaceMemoire(){
	for (int i = 0 ; i < medias.size() ; i++){
		delete medias[i];
		stock--;
	}
	medias.clear();
	mediaSave.clear();
}

void ressources::deleteMedia(int _id, std::string _idMedia){
	std::string type;
	std::string buf;
	std::string filename;
	std::string id;
	if(1 <= _id && _id <= medias.size()){
		type = medias[_id-1]->getType();
		delete medias[_id-1];
		medias.erase(medias.begin() + _id - 1);
		mediaSave.erase(mediaSave.begin() + _id - 1);
		filename = type + ".txt";
		std::ifstream myFile(filename.c_str());
		std::ofstream tempFile("temporary.txt");
	    if(!myFile.is_open() && !tempFile.is_open()){
	    	std::cout << "Can't read file : " << type << ".txt" << std::endl;
	    }
	    else{
	    	getline(myFile, buf);
	    	tempFile << buf << std::endl;
    		while (getline(myFile, buf)){
    			std::stringstream ss(buf);
    			getline(ss, id, ';');
    			if(id.compare(_idMedia) != 0){
    				tempFile << buf << std::endl;
    			}
    		}
		}
		myFile.close();
		tempFile.close();
		remove(filename.c_str());
		rename("temporary.txt", filename.c_str());
	}
	else
		std::cout << "Impossible de detruire le media d'identifiant " << _id << std::endl;
	nbrRessource--;
}

int ressources::findLastPosition(std::string _type){
	std::string str;
	int flagDebut = 0;
	for (int i = 0 ; i < medias.size() ; i++){
		str = medias[i]->getId()[0];
		if(str.compare(_type) == 0){
			flagDebut = 1;
		}
		if(str.compare(_type) != 0 && flagDebut == 1){
			return i;
		}
	}
	return medias.size() - 1;
}

void ressources::saveEndOfFile(std::string filename, std::string str, const char *entete){
	std::ifstream testFile(filename.c_str());
	int flag = 0;
	if(!testFile.is_open()){
		flag = 1;
	}
	testFile.close();
	std::ofstream myFile(filename.c_str(), std::ios::out |std::ios::app);
	if(flag == 1){
		myFile << entete << std::endl;
	}
	myFile << std::endl << str;
	myFile.close();
}	


std::string ressources::addMedia(int _type){
	std::string name;


	int pos;
	std::string id;
	std::string newId;
	std::string type;
	std::string buf;
	std::string str;
	std::cout << "Merci de remplir le formulaire de creation de nouveau media. AUCUN CHAMP NE DOIT RESTER VIDE (mettre 'aucun' ou '0' si donnee inconnue)\n\t- Titre : ";
	std::getline (std::cin,str);
	std::getline (std::cin,str);
	buf = buf + ";" + str;
	std::cout << "\t- Auteur : ";
	std::getline (std::cin,str);
	buf = buf + ";" + str;
	std::cout << "\t- Annee de parution : ";
	std::getline (std::cin,str);
	buf = buf + ";" + str + ";3;60;-1";
	if(_type == 1){
		std::cout << "\t- Nombre de pages : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Collection : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Resume : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		if(_type == 2){
			type = "revue";
			revues *med = new revues();
			std::cout << "\t- Editeur : ";
			std::getline (std::cin,str);
			buf = buf + ";" + str;
			std::cout << "\t- Nombre d'articles : ";
			std::getline (std::cin,str);
			buf = buf + ";" + str;
			std::cout << "\t- Nom des articles (separe par une virgule, sans espace autour des virgules) : ";
			std::getline (std::cin,str);
			buf = buf + ";" + str;
			pos = findLastPosition("R");
			id = medias[pos-1]->getId();
			for (int i = 1 ; i < id.size() ; i++){
				newId = newId + id[i];
			}
			newId = "R" + int2str(str2int(newId) + 1);
			buf = newId + buf;
			createRevues(buf, med);
			medias.insert(medias.begin() + pos, med);
			mediaSave.insert(mediaSave.begin() + pos, med);
			str = type + ".txt";
			saveEndOfFile(str, buf, "(2) Listes des revues :");
		}
		else{
			type = "livre";
			livre *med = new livre();
			pos = findLastPosition("L");
			id = medias[pos-1]->getId();
			for (int i = 1 ; i < id.size() ; i++){
				newId = newId + id[i];
			}
			newId = "L" + int2str(str2int(newId) + 1);
			buf = newId + buf;
			createLivre(buf, med);
			medias.insert(medias.begin() + pos, med);
			mediaSave.insert(mediaSave.begin() + pos, med);
			str = type + ".txt";
			saveEndOfFile(str, buf, "(1) Liste des Livres :");
		}
	}
	else if(_type == 3){
		std::cout << "\t- Duree : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Maison de production : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		if(_type == 4){
			type = "dvd";
			dvd *med = new dvd();
			std::cout << "\t- Nombre de pistes : ";
			std::getline (std::cin,str);
			buf = buf + ";" + str;
			std::cout << "\t- Nom des pistes (separe par une virgule, sans espace autour des virgules) : ";
			std::getline (std::cin,str);
			buf = buf + ";" + str;
			pos = findLastPosition("D");
			id = medias[pos-1]->getId();
			for (int i = 1 ; i < id.size() ; i++){
				newId = newId + id[i];
			}
			newId = "D" + int2str(str2int(newId) + 1);
			buf = newId + buf;
			createDvd(buf, med);
			medias.insert(medias.begin() + pos, med);
			mediaSave.insert(mediaSave.begin() + pos, med);
			str = type + ".txt";
			saveEndOfFile(str, buf, "(4) liste des DVD :");
		}
		else{
			type = "vhs";
			vhs *med = new vhs();
			pos = findLastPosition("V");
			id = medias[pos-1]->getId();
			for (int i = 1 ; i < id.size() ; i++){
				newId = newId + id[i];
			}
			newId = "V" + int2str(str2int(newId) + 1);
			buf = newId + buf;
			createVhs(buf, med);
			medias.insert(medias.begin() + pos, med);
			mediaSave.insert(mediaSave.begin() + pos, med);
			str = type + ".txt";
			saveEndOfFile(str, buf, "(6) liste des vhs :");
		}
	}
	else if(_type == 5){
		type = "cd";
		cd *med = new cd();
		std::cout << "\t- Duree : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Nombre de pistes : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Maison de disque : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Titre des pistes (separe par une virgule, sans espace autour des virgules) : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		pos = findLastPosition("C");
		id = medias[pos-1]->getId();
		for (int i = 1 ; i < id.size() ; i++){
			newId = newId + id[i];
		}
		newId = "C" + int2str(str2int(newId) + 1);
		buf = newId + buf;
		createCd(buf, med);
		medias.insert(medias.begin() + pos, med);
		mediaSave.insert(mediaSave.begin() + pos, med);
		str = type + ".txt";
		saveEndOfFile(str, buf, "(3) liste de cd :");
	}
	else if(_type == 6){
		type = "ressourcenumerique";
		resNumerique *med = new resNumerique();
		std::cout << "\t- Format : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Taille : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Path : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		pos = findLastPosition("N");
		id = medias[pos-1]->getId();
		for (int i = 1 ; i < id.size() ; i++){
			newId = newId + id[i];
		}
		newId = "N" + int2str(str2int(newId) + 1);
		buf = newId + buf;
		createResNumerique(buf, med);
		medias.insert(medias.begin() + pos, med);
		mediaSave.insert(mediaSave.begin() + pos, med);
		str = type + ".txt";
		saveEndOfFile(str, buf, "(5) liste des ressources numerique :");
	}
	else if(_type == 7){
		type = "peinture";
		peinture *med = new peinture();
		std::cout << "\t- Hauteur : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		std::cout << "\t- Longueur : ";
		std::getline (std::cin,str);
		buf = buf + ";" + str;
		pos = findLastPosition("P");
		id = medias[pos-1]->getId();
		for (int i = 1 ; i < id.size() ; i++){
			newId = newId + id[i];
		}
		newId = "P" + int2str(str2int(newId) + 1);
		buf = newId + buf;
		createPeinture(buf, med);
		medias.insert(medias.begin() + pos, med);
		mediaSave.insert(mediaSave.begin() + pos, med);
		str = type + ".txt";
		saveEndOfFile(str, buf, "(7) liste des peintures : ");
	}
	nbrRessource++;
	stock++;
	return newId;
}

void ressources::modifMedia(int _id, std::string _idMedia){
	std::string type = medias[_id-1]->getType();
	std::string str;
	std::string filename;
	std::string id;
	std::cout << "Informations actuelles du media a modifier :" <<std::endl;
	medias[_id-1]->info();
	std::cout << "\nMerci de remplir le formulaire de modification de media. AUCUN CHAMP NE DOIT RESTER VIDE (mettre 'aucun' ou '0' si donnee inconnue)\n\t- Titre : ";
	std::getline (std::cin,str);
	std::getline (std::cin,str);
	medias[_id-1] ->setTitre(str);
	std::cout << "\t- Auteur : ";
	std::getline (std::cin,str);
	medias[_id-1] ->setAuteur(str);
	std::cout << "\t- Annee de parution : ";
	std::getline (std::cin,str);
	medias[_id-1] ->setAnnee(str2int(str));
	if(type.compare("livre") == 0){
		std::cout << "\t- Nombre de pages : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setPage(str2int(str));
		std::cout << "\t- Collection : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setCollection(str);
		std::cout << "\t- Resume : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setResume(str);
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNote(str2int(str));
	}
	else if(type.compare("revue") == 0){
		std::cout << "\t- Nombre de pages : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setPage(str2int(str));
		std::cout << "\t- Collection : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setCollection(str);
		std::cout << "\t- Resume : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setResume(str);
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNote(str2int(str));
		std::cout << "\t- Editeur : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setEditeur(str);
		std::cout << "\t- Nombre d'articles : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNbrArticle(str2int(str));
		std::cout << "\t- Nom des articles (separe par une virgule, sans espace autour des virgules) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNomArticle(str);
	}
	else if(type.compare("vhs") == 0){
		std::cout << "\t- Duree (en minutes) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setDuree(str2int(str));
		std::cout << "\t- Maison de production : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setMaisonProduction(str);
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNote(str2int(str));
	}
	else if(type.compare("dvd") == 0){
		std::cout << "\t- Duree (en minutes ): ";
		std::getline (std::cin,str);
		medias[_id-1] ->setDuree(str2int(str));
		std::cout << "\t- Maison de production : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setMaisonProduction(str);
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNote(str2int(str));
		std::cout << "\t- Nombre de pistes : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNbrPiste(str2int(str));
		std::cout << "\t- Nom des pistes (separe par une virgule, sans espace autour des virgules) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNomPiste(str);
	}
	else if(type.compare("cd") == 0){
		std::cout << "\t- Duree (en secondes) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setDuree(str2int(str));
		std::cout << "\t- Nombre de pistes : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNbrPiste(str2int(str));
		std::cout << "\t- Maison de disque : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setMaisonDisque(str);
		std::cout << "\t- Titre des pistes (separe par une virgule, sans espace autour des virgules) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setTitrePiste(str);
		std::cout << "\t- Note (/5) : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setNote(str2int(str));
	}
	else if(type.compare("ressourcenumerique") == 0){
		std::cout << "\t- Format : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setFormat(str);
		std::cout << "\t- Taille : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setTaille(str2int(str));
		std::cout << "\t- Path : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setPath(str);
	}
	else if(type.compare("peinture") == 0){
		std::cout << "\t- Hauteur : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setHauteur(str2int(str));
		std::cout << "\t- Longueur : ";
		std::getline (std::cin,str);
		medias[_id-1] ->setLongueur(str2int(str));
	}
	filename = type + ".txt";
	std::ifstream myFile(filename.c_str());
	std::ofstream tempFile("temporary.txt");
	   if(!myFile.is_open() && !tempFile.is_open()){
	    std::cout << "Can't read file : " << type << ".txt" << std::endl;
	   }
	   else{
	    getline(myFile, str);
	    tempFile << str << std::endl;
    	while (getline(myFile, str)){
    		std::stringstream ss(str);
    		getline(ss, id, ';');
    		if(id.compare(_idMedia) != 0){
    			tempFile << str << std::endl;
    		}
    		else{
    			tempFile << medias[_id-1]->infoToSave() << std::endl;
    		}
    	}
	}
	myFile.close();
	tempFile.close();
	remove(filename.c_str());
	rename("temporary.txt", filename.c_str());
}

void ressources::reset(){
	for (int i = 0 ; i < medias.size() ; i++){
		delete medias[i];
		stock--;
	}
	medias.clear();
	mediaSave.clear();
	std::ofstream deleteLivre("livre.txt");
	deleteLivre.close();
	std::ofstream deleteRevue("revues.txt");
	deleteRevue.close();
	std::ofstream deleteVhs("vhs.txt");
	deleteVhs.close();
	std::ofstream deleteDvd("dvd.txt");
	deleteDvd.close();
	std::ofstream deleteCd("cd.txt");
	deleteCd.close();
	std::ofstream deleteResNum("resNumerique.txt");
	deleteResNum.close();
	std::ofstream deletePeinture("peinture.txt");
	deletePeinture.close();
}

void ressources::rechercheGene(std::string _str){
	for (int i = 0 ; i < medias.size() ; i++){
        if (medias[i]->getId().compare(_str) != 0 && medias[i]->getTitre().find(_str) == -1 && medias[i]->getAuteur().find(_str) == -1 && int2str(medias[i]->getAnnee()).compare(_str) != 0 && int2str(medias[i]->getAnnee()).compare(_str) != 0){
			if(medias[i]->getType().compare("livre") == 0 && int2str(medias[i]->getPage()).compare(_str) != 0 && medias[i]->getCollection().compare(_str) != 0 && medias[i]->getResume().find(_str) == -1 && int2str(medias[i]->getNote()).compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("revue") == 0 && medias[i]->getEditeur().compare(_str) != 0 && (medias[i]->getArticle()).find(_str) == -1 && int2str(medias[i]->getNbrArticle()).compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("cd") == 0 && int2str(medias[i]->getDuree()).compare(_str) != 0 && int2str(medias[i]->getNbrPiste()).compare(_str) != 0 && int2str(medias[i]->getNote()).compare(_str) != 0 && medias[i]->getMaisonDisque().compare(_str) != 0 && medias[i]->getTitreAll().find(_str) == -1){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("dvd") == 0 && int2str(medias[i]->getNbrPiste()).compare(_str) != 0 && medias[i]->getNomPiste().compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("peinture") == 0 && int2str(medias[i]->getHauteur()).compare(_str) != 0 && int2str(medias[i]->getLongueur()).compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("ressourcenumerique") == 0 && int2str(medias[i]->getTaille()).compare(_str) != 0 && medias[i]->getFormat().find(_str) == -1 && medias[i]->getPath().compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
			}
			else if(medias[i]->getType().compare("vhs") == 0 && int2str(medias[i]->getDuree()).compare(_str) != 0 && int2str(medias[i]->getNote()).compare(_str) != 0 && medias[i]->getMaisonProduction().compare(_str) != 0){
				medias.erase(medias.begin()+i);
				i--;
	        }
		}
	}
}

void ressources::rechercheType(std::string _str, int _type){
	for (int i = 0 ; i < medias.size() ; i++){
		if (!((_type == 1 && medias[i]->getType().compare("livre") == 0) || (_type != 1 && medias[i]->getType().compare("livre") != 0))){	//ces conditions codent un !(&exclusif)
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 2 && medias[i]->getType().compare("revue") == 0) || (_type != 2 && medias[i]->getType().compare("revue") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 3 && medias[i]->getType().compare("vhs") == 0) || (_type != 3 && medias[i]->getType().compare("vhs") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 4 && medias[i]->getType().compare("dvd") == 0) ||(_type != 4 && medias[i]->getType().compare("dvd") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 5 && medias[i]->getType().compare("cd") == 0) || (_type != 5 && medias[i]->getType().compare("cd") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 6 && medias[i]->getType().compare("ressourcenumerique") == 0) || (_type != 6 && medias[i]->getType().compare("ressourcenumerique") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 7 && medias[i]->getType().compare("peinture") == 0) || (_type != 7 && medias[i]->getType().compare("peinture") != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
	}
	rechercheGene(_str);
}




void ressources::rechercheChamp(std::string _str, int _type){
	for (int i = 0 ; i < medias.size() ; i++){
		if (!((_type == 1 && medias[i]->getId().compare(_str) == 0) || (_type != 1 && medias[i]->getId().compare(_str) != 0))){	//ces conditions codent un !(&exclusif)
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 2 && medias[i]->getTitre().compare(_str) == 0) || (_type != 2 && medias[i]->getTitre().compare(_str) != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 3 && medias[i]->getAuteur().find(_str) != -1) || (_type != 3 && medias[i]->getAuteur().find(_str) == -1))){
			medias.erase(medias.begin()+i);
			i--;
		}
		else if(!((_type == 4 && int2str(medias[i]->getAnnee()).compare(_str) == 0) ||(_type != 4 && int2str(medias[i]->getAnnee()).compare(_str) != 0))){
			medias.erase(medias.begin()+i);
			i--;
		}	
	}
}

int ressources::verifIdMedia(std::string idRessource){
	for (int i = 0 ; i < medias.size() ; i++){
		if(idRessource.compare(medias[i]->getId()) == 0){
			if(medias[i]->getDisponible() == 3)
				return i+1;
			else if(medias[i]->getDisponible() == 0)
				return -1;
			else if(medias[i]->getDisponible() == 1)
				return -2;
			else if(medias[i]->getDisponible() == 2)
				return -3;
		}
	}
	return 0;
}

void ressources::info (int _id){
	medias[_id]->info();
}


int ressources::getDisponible(int idMedia){
	return medias[idMedia]->getDisponible();
}

std::string ressources::infoPrincipales(int _id){
	return "(" + medias[_id]->getId() + ") " + medias[_id]->getTitre();
}

void ressources::reservation(std::string str, int idMedia){
	medias[idMedia]->setDisponible(0);
	medias[idMedia]->setIdClient(str);
}

void ressources::checkVersion()
{
	std::string buf;
	std::string id;
	int version;
	int set[7] = {-1,-1,-1,-1,-1,-1,-1};
	std::ifstream fileLivre("livre.txt");
	getline(fileLivre,buf,':');
	getline(fileLivre,buf,' ');
	version = str2int(buf);

	for ( int i = 0 ; i < medias.size(); i++)
	{
		id = medias[i]->getId();
		id = id[0];
		if(id.compare("L") == 0)
			set[0] = i;
		if(id.compare("C") == 0)
			set[1] = i;
		if(id.compare("D") == 0)
			set[2] = i;
		if(id.compare("R") == 0)
			set[3] = i;
		if(id.compare("N") == 0)
			set[4] = i;
		if(id.compare("P") == 0)
			set[5] = i;
		if(id.compare("V") == 0)
			set[6] = i;
	} 

	for (int i = 0 ; i<7 ; i++ )
	{
		if( set[0] != -1)
		{
			if ( version != medias[set[0]]->getVersion())
				load("livre.txt");
		}
		else
			load("livre.txt");

		if(set[1] != -1)
		{
			if ( version != medias[set[1]]->getVersion())
				load("cd.txt");			
		}
		else
			load("cd.txt");

		if(set[2] != -1)
		{
			if ( version != medias[set[2]]->getVersion())
				load("dvd.txt");			
		}
		else
			load("dvd.txt");

		if(set[3] != -1)
		{
			if ( version != medias[set[3]]->getVersion())
				load("revues.txt");			
		}
		else
			load("resvues.txt");

		if(set[4] != -1)
		{
			if ( version != medias[set[4]]->getVersion())
				load("resNumerique.txt");			
		}
		else
			load("resNumerique.txt");

		if(set[5] != -1)
		{
			if ( version != medias[set[5]]->getVersion())
				load("peinture.txt");			
		}
		else
			load("peinture.txt");

		if(set[6] != -1)
		{
			if ( version != medias[set[6]]->getVersion())
				load("vhs.txt");			
		}
		else
			load("vhs.txt");
	}
}