#include "utilisateurs.hpp"

#define NBR_DATA_USER 7
#define NBR_DATA_ADMIN 8

void utilisateurs::createClient(std::string _buf, client *clt){
	std::string str;
	std::string data[NBR_DATA_USER];
	std::string data2[NBR_DATA_USER];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_USER ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	std::stringstream ssReservee(data[3]);
	std::stringstream ssEmpruntee(data[5]);
	std::stringstream ssDate(data[6]);
	clt->setId(data[0]);
	clt->setNom(data[1]);
	clt->setPrenom(data[2]);
	for (int i = 0 ; i < LIMITE_RESERVATION ; i++){
		getline(ssReservee, str, ',');
		clt->setResReservee (str, i);
	}
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		getline(ssEmpruntee, str, ',');
		clt->setResEmpruntee (str, i);
	}
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		getline(ssDate, str, ',');
		clt->setDateEmprunt (str, i);
	}
	//client vector
	
}


void utilisateurs::createAdmin(std::string _buf, admin *administrateur){
	std::string str;
	std::string data[NBR_DATA_ADMIN];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_ADMIN ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	//admin *newAdmin = new admin(atoi(data[0].c_str()), data[1], data[2], data[3], data[4], data[5], data[6]);
	administrateur->setId(data[0]);
	administrateur->setNom(data[1]);
	administrateur->setPrenom(data[2]);
	std::stringstream ssReservee(data[3]);
	std::stringstream ssEmpruntee(data[5]);
	std::stringstream ssDate(data[6]);
	administrateur->setId(data[0]);
	administrateur->setNom(data[1]);
	administrateur->setPrenom(data[2]);
	for (int i = 0 ; i < LIMITE_RESERVATION ; i++){
		getline(ssReservee, str, ',');
		administrateur->setResReservee (str, i);
	}
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		getline(ssEmpruntee, str, ',');
		administrateur->setResEmpruntee (str, i);
	}
	for (int i = 0 ; i < LIMITE_EMPRUNT ; i++){
		getline(ssDate, str, ',');
		administrateur->setDateEmprunt (str, i);
	}
	//admin vector
	administrateur->setMdp(data[7]);
}

utilisateurs::utilisateurs(const char *filename){
    std::string buf;
	std::ifstream myFile(filename);
    if(!myFile.is_open()){
    	std::cout << "Can't read file : " << filename <<std::endl;
    }
    else{
    	while (getline(myFile, buf)){
    		if (buf[0] == '1'){
    			//creation du client
    			//std::cout << "Creation d'un Client." << std::endl;
    			client *clt = new client();
    			createClient(buf, clt);
    			clients.push_back(clt);
    		}
  			else if(buf[0] == '0'){
				//creation d'un admin
				//std::cout << "creation d'un admin" << std::endl;
				admin *administrateur = new admin();
				createAdmin(buf, administrateur);
				adm.push_back(administrateur);
			}
			else
				std::cout << "Impossible de créer l'utilisateur : " << buf << std::endl;
    	}
    	//info();
    	users.insert(users.end(), clients.begin(), clients.end());
    	users.insert(users.end(), adm.begin(), adm.end());
    }
}

utilisateurs::~utilisateurs(){};

/*void utilisateurs::setNomUtilisateur(std::string _users){
	users = _users;
}*/

std::string utilisateurs::getUsers(){
	std::string str;
	for (int i = 0 ; i < users.size() ; i++){
		str = str + ", " + users[i]->getNom();
	}
	str = str + ".";
	return str;
}

std::string utilisateurs::getClient(){ //possible de connaitre le type pour différencier client et admin ? Sinon utilisation d'un ID spécifique
	std::string str = "Les clients sont :\n";
	for (int i = 0 ; i < users.size() ; i++){
		if (users[i]->getId()[0] == '1')
			str = str + "\t(" + users[i] ->getId() + ") " + users[i]->getNom() + " " + users[i]->getPrenom() + "\n";
	}
	return str;
}

std::string utilisateurs::getAdmin(){ //possible de connaitre le type pour différencier client et admin ? Sinon utilisation d'un ID spécifique
	std::string str = "Les administrateurs sont :\n";
	for (int i = 0 ; i < users.size() ; i++){
		if (users[i]->getId()[0] == '0') //identifiant admin : commence par un 0
			str = str + "\t(" + users[i]->getId() + ") " + users[i]->getNom() + " " + users[i]->getPrenom() + "\n";
	}
	return str;
}

void utilisateurs::info(){
	std::cout << "Il y a " << clients.size() + adm.size() << " utilisateurs de la médiathèque, dont " << clients.size() << " clients et " << adm.size() << " administrateurs.\n" << getClient() << getAdmin() << std::endl;
}

void utilisateurs::infoClient(int _id){
	users[_id]->info();
}

int utilisateurs::str2int(std::string str)
{
	int result;
	std::stringstream ss(str);
	if(!(ss>>result))
		return 0;
	return result;
}

std::string utilisateurs::int2str(int nbr)
{
	std::stringstream ss;
	ss << nbr;
	return ss.str();
}

int utilisateurs::verifIdClient(std::string idClient){
	for (int i = 0 ; i < clients.size() ; i++){
		if(idClient.compare(clients[i]->getId()) == 0)
			return i+1;
	}
	for (int i = 0 ; i < adm.size() ; i++){
		if(idClient.compare(adm[i]->getId()) == 0)
			return -(i+1);
	}
	return 0;
}

int utilisateurs::verifMdp(std::string _mdp, int _id){
	return 1;
}

std::string utilisateurs::getClient(int _id){
	return clients[_id]->getNom() + " " + clients[_id]->getPrenom();
}

std::string utilisateurs::getAdmin(int _id){
	return adm[_id]->getNom() + " " + adm[_id]->getPrenom();
}

void utilisateurs::addClient(client *clt){
	std::string newId = clients[clients.size()-1]->getId();
	newId = newId.substr(1);
	newId = "1" + int2str(str2int(newId) + 1);	clt->setId(newId);
	clients.push_back(clt);
	users.push_back(clt);
	std::ofstream myFile("utilisateurs.txt", std::ios::out | std::ios::app);
	std::string info2save = newId + ";" + clt->getNom() + ";" + clt->getPrenom() + ";(0)aucun,(0)aucun;(0)aucun,(0)aucun;(0)aucun,(0)aucun;0,0";
	myFile << std::endl << info2save;
	myFile.close();
}

void utilisateurs::addAdmin(admin *administrateur){
	std::string newId = adm[adm.size()-1]->getId();
	newId = newId.substr(1);
	newId = "0" + int2str(str2int(newId) + 1);
	administrateur->setId(newId);
	adm.push_back(administrateur);
	users.push_back(administrateur);
	std::ofstream myFile("utilisateurs.txt", std::ios::out | std::ios::app);
	std::string info2save = newId + ";" + administrateur->getNom() + ";" + administrateur->getPrenom() + ";(0)aucun,(0)aucun;(0)aucun,(0)aucun;(0)aucun,(0)aucun;0,0;" + administrateur->getMdp();
	myFile << std::endl << info2save;
	myFile.close();
}

int utilisateurs::getIdUtilisateur(std::string _id){
	for (int i = 0 ; i < users.size() ; i++){
		if(users[i]->getId().compare(_id) == 0)
			return i;
	}
	return -1;
}

int utilisateurs::getIdClient(std::string _id){
	for (int i = 0 ; i < clients.size() ; i++){
		if(clients[i]->getId().compare(_id) == 0)
			return i;
	}
	return -1;
}


int utilisateurs::getIdAdmin(std::string _id){
	for (int i = 0 ; i < adm.size() ; i++){
		if(adm[i]->getId().compare(_id) == 0)
			return i;
	}
	return -1;
}

void utilisateurs::deleteAdmin(int _idAdmin, std::string admin2suppr)
{
	if( adm.size() == 1)
	{
		std::cout << "Impossible de supprimer cet administrateur. Il est necessaire d'avoir au moins un administrateur." << std::endl;
	}
	else{
	if(0 <= _idAdmin && _idAdmin - 1 <= adm.size()){
	delete users[_idAdmin];
	users.erase(users.begin() + _idAdmin);
	adm.erase(adm.begin() + getIdAdmin(admin2suppr));
	std::string filename;
	std::string id;
	std::string buf;
	filename = "utilisateurs.txt";
	std::ifstream myFile(filename.c_str());
	std::ofstream tempFile("temporary.txt");
	if(!myFile.is_open() && !tempFile.is_open()){
	    	std::cout << "Can't read file : " << filename << std::endl;
	    }
	else{
    	while (getline(myFile, buf)){
    		std::stringstream ss(buf);
    		getline(ss, id, ';');
    		if(id.compare(admin2suppr) != 0){
    			tempFile << std::endl << buf;
    			}
    		}
		}
	myFile.close();
	tempFile.close();
	remove(filename.c_str());
	rename("temporary.txt", filename.c_str());
}
	else
		std::cout << "Impossible de detruire l'administrateur " << admin2suppr << std::endl;
	}
}


void utilisateurs::deleteClient(int _idClient, std::string client2suppr)
{
	if(0 <= _idClient && _idClient <= clients.size()){
	delete users[_idClient];
	users.erase(users.begin() + _idClient);
	clients.erase(clients.begin() + getIdClient(client2suppr));
	std::string id;
	std::string filename;
	std::string buf;
	filename = "utilisateurs.txt";
	std::ifstream myFile(filename.c_str());
	std::ofstream tempFile("temporary.txt");
	if(!myFile.is_open() && !tempFile.is_open()){
	    	std::cout << "Can't read file : " << filename << std::endl;
	    }
	else{
    	while (getline(myFile, buf)){
    		std::stringstream ss(buf);
    		getline(ss, id, ';');
    		if(id.compare(client2suppr) != 0){
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
		std::cout << "Impossible de detruire le client " << client2suppr << std::endl;

}


void utilisateurs::effaceMemoire(){
	for (int i = 0 ; i < users.size() ; i++){
		delete users[i];
	}
	clients.clear();
	adm.clear();
	users.clear();
}

void utilisateurs::emprunt(int idClient, int idMedia){

}

std::string utilisateurs::getResEmpruntee(int idClient){
	return users[idClient]->getResEmpruntee();
}

std::string utilisateurs::getResReservee(int idClient){
	return users[idClient]->getResReservee();
}

void utilisateurs::retour(int idUser, int idMedia){

}

void utilisateurs::reservation(int idUser, std::string media, int pos){
	users[idUser]->setResReservee(media, pos);
}

std::string utilisateurs::getIdClient(int _id){
	return users[_id]->getId();
}

