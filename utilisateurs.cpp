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
    	getline(myFile, buf);
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
				std::cout << "Impossible de creer l'utilisateur : " << buf << std::endl;
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

void utilisateurs::modifyAdmin(int id2modif, std::string client2modif){
	std::string newname;
	std::string newprenom;
	std::string newmdp;
	admin *administrateur = adm[id2modif];
	if(0 <= id2modif && id2modif <= adm.size())
	{
	std::cout << "Quel est le nouveau nom de l'administrateur : ";
	std::cin >> newname;
	administrateur->setNom(newname);
	std::cout << "Quel est le nouveau prenom de l'administrateur : ";
	std::cin >> newprenom;
	administrateur->setPrenom(newprenom);
	std::cout << "Quel est le nouveau mot de passe de l'administrateur : ";
	std::cin >> newmdp;
	administrateur->setMdp(newmdp);
	std::string info2Save = client2modif+ ";" + newname + ";" + newprenom + ";"+ administrateur->getResEmpruntee() +";"+ administrateur->getDateEmprunt() +";"+ administrateur->getResRendue() +";"+ administrateur->getResReservee() +";"+ newmdp;
	std::string filename;
	std::string id;
	std::string buf;
	filename = "utilisateurs.txt";
	std::ifstream myFile(filename.c_str());
	std::ofstream tempFile("temporary.txt");
	if(!myFile.is_open() && !tempFile.is_open()){
	    	std::cout << "Can't read file : " << filename << " ou de creer un temporary.txt." << std::endl;
	    }
	else{
		getline(myFile, buf);
		tempFile << buf ;
    	while (getline(myFile, buf)){
    		std::stringstream ss(buf);
    		getline(ss, id, ';');
    		if(id.compare(client2modif) != 0){
    			tempFile << std::endl  << buf;
    			}
    		else if (id.compare(client2modif) == 0)
    		{
    			tempFile << std::endl << info2Save;
    		}
    	}
		}
	myFile.close();
	tempFile.close();
	remove(filename.c_str());
	rename("temporary.txt", filename.c_str());
	std::cout << "Administrateur modifie. " << std::endl;
	}
	else
		std::cout << "Impossible de modifier l'administrateur " << client2modif << std::endl;
}




void utilisateurs::modifyClient(int id2modif, std::string client2modif){
	std::string newname;
	std::string newprenom; 
	client * clt = clients[id2modif];
	if(0 <= id2modif && id2modif <= clients.size()){
		std::cout << "Quel est le nouveau nom du client : ";
		std::cin >> newname;
		clt->setNom(newname);
		std::cout << "Quel est le nouveau prenom du client : ";
		std::cin >> newprenom;
		clt->setPrenom(newprenom);
		std::string infoToSave = client2modif + ";" + newname + ";" + newprenom + ";"+ clt->getResEmpruntee() +";"+ clt->getDateEmprunt() +";"+ clt->getResRendue() +";"+ clt->getResReservee();
		std::string filename;
		std::string id;
		std::string buf;
		filename = "utilisateurs.txt";
		std::ifstream myFile(filename.c_str());
		std::ofstream tempFile("temporary.txt");
		if(!myFile.is_open() && !tempFile.is_open()){
	    	std::cout << "Can't read file : " << filename << " ou de creer un temporary.txt." << std::endl;
	   		 }
		else{
			getline(myFile, buf);
			tempFile << buf ;
    		while (getline(myFile, buf)){
    			std::stringstream ss(buf);
    			getline(ss, id, ';');
    			if(id.compare(client2modif) != 0)
    			{
    				tempFile << std::endl << buf;
    			}
    			else if (id.compare(client2modif) == 0)
    			{
    				tempFile << std::endl << infoToSave;
    			}
    		}
		}
	myFile.close();
	tempFile.close();
	remove(filename.c_str());
	rename("temporary.txt", filename.c_str());
	std::cout << "Client modifie. " << std::endl;
	}

	else
		std::cout << "Impossible de modifier le client " << client2modif << std::endl;
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
	/*int type = idClient[0] - '0';
	//type = type[0];
	//std::string str = type;
	std::cout << type  << " test " << idClient << std::endl;
	for(int i = 0 ; i < users.size() ; i++){
		if(idClient.compare(users[i]->getId()) == 0){
			if(/*str.compare("0") == 0type == 0)
				return -(i+1);
			else if(/*str.compare("1") == 0type == 1)
				return i+1;
		}
	}*/
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

std::string utilisateurs::getAdminNbr(int _id){
	return adm[_id]->getId();
}


std::string utilisateurs::getLastClientId(){
	return clients[clients.size()-1]->getId();
}

std::string utilisateurs::getLastAdminId(){
	return adm[adm.size()-1]->getId();
}

void utilisateurs::addClient(client *clt){
	std::string newId;
	if(clients.size() == 0)
		newId = "11";
	else{
		newId = clients[clients.size()-1]->getId();
		newId = newId.substr(1);
		newId = "1" + int2str(str2int(newId) + 1);	clt->setId(newId);
	}
	clients.push_back(clt);
	users.push_back(clt);
	std::ofstream myFile("utilisateurs.txt", std::ios::out | std::ios::app);
	if(myFile.is_open()){
		std::string info2save = newId + ";" + clt->getNom() + ";" + clt->getPrenom() + ";(0)aucun,(0)aucun;(0)aucun,(0)aucun;(0)aucun,(0)aucun;0,0";
		myFile << std::endl << info2save;
		myFile.close();
	}
	else
		std::cout << "Impossible d'ouvrir le fichier utilisateurs.txt." << std::endl;
}

void utilisateurs::addAdmin(admin *administrateur){
	std::string newId;
	if(adm.size() == 0)
		newId = "01";
	else{
		newId = adm[adm.size()-1]->getId();
		newId = newId.substr(1);
		newId = "0" + int2str(str2int(newId) + 1);
	}
	administrateur->setId(newId);
	adm.push_back(administrateur);
	users.push_back(administrateur);
	std::ofstream myFile("utilisateurs.txt", std::ios::out | std::ios::app);
	if(myFile.is_open()){
		std::string info2save = newId + ";" + administrateur->getNom() + ";" + administrateur->getPrenom() + ";(0)aucun,(0)aucun;(0)aucun,(0)aucun;(0)aucun,(0)aucun;0,0;" + administrateur->getMdp();
		myFile << std::endl << info2save;
		myFile.close();
	}
	else
		std::cout << "Impossible d'ouvrir le fichier utilisateurs.txt." << std::endl;
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

void utilisateurs::deleteAdmin(int _idAdmin, std::string admin2suppr, std::string idUti)
{
	if( adm.size() == 1 || admin2suppr.compare(idUti) == 0)
	{
		std::cout << "Impossible de supprimer cet administrateur. Remarque : il est impossible de supprimer le dernier administrateur restant et la suppression de son propre compte est impossible." << std::endl;
	}
	else{
		std::cout << users.size() << "\t" << adm.size() << std::endl;
		if(0 <= _idAdmin && _idAdmin < users.size()){
			delete users[_idAdmin];
			users.erase(users.begin() + _idAdmin);
			adm.erase(adm.begin() + getIdAdmin(admin2suppr));
			std::cout << users.size() << "\t" << adm.size() << std::endl;
			std::string filename;
			std::string id;
			std::string buf;
			filename = "utilisateurs.txt";
			std::ifstream myFile(filename.c_str());
			std::ofstream tempFile("temporary.txt");
			if(!myFile.is_open() || !tempFile.is_open()){
			    std::cout << "Can't read file : " << filename << " ou de creer un temporary.txt." << std::endl;
			}
			else{
				getline(myFile, buf);
				tempFile << buf ;
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
			std::cout << "Administrateur supprime." << std::endl;
		}
		else
			std::cout << "Impossible de detruire l'administrateur " << admin2suppr << std::endl;
	}
}


void utilisateurs::deleteClient(int _idClient, std::string client2suppr, int _idInClients)
{
	std::cout << _idClient << std::endl;
	std::cout << getIdUtilisateur(client2suppr) << std::endl;
	if(0 <= _idClient && _idClient < users.size()){
		delete users[_idClient];
		users.erase(users.begin() + _idClient);
		clients.erase(clients.begin() + _idInClients);
		std::string id;
		std::string filename;
		std::string buf;
		filename = "utilisateurs.txt";
		std::ifstream myFile(filename.c_str());
		std::ofstream tempFile("temporary.txt");
		if(!myFile.is_open() || !tempFile.is_open()){
	    	std::cout << "Can't read file : " << filename << std::endl;
	    }
		else{
			getline(myFile, buf);
			tempFile << buf ;
    		while (getline(myFile, buf)){
    			std::stringstream ss(buf);
    			getline(ss, id, ';');
    			if(id.compare(client2suppr) != 0){
    				tempFile << std::endl << buf;
    			}
    		}
		}
		myFile.close();
		tempFile.close();
		remove(filename.c_str());
		rename("temporary.txt", filename.c_str());
		std::cout << "Client supprime." << std::endl;
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

std::string utilisateurs::getResEmpruntee(int idClient){
	return users[idClient]->getResEmpruntee();
}

std::string utilisateurs::getResReservee(int idClient){
	return users[idClient]->getResReservee();
}

void utilisateurs::retour(int idUser, std::string media, int pos){
	users[idUser]->setResEmpruntee(media, pos);



	//users[idUser]->setDateEmprunt(date, pos); //TODO

	std::string id;
	std::string id2compare = users[idUser]->getId();
	std::string str;
	std::string firstPart, secondPart, thirdPart;
	std::ifstream myFile("utilisateurs.txt");
	std::ofstream tempFile("temporary.txt");
	   if(!myFile.is_open() || !tempFile.is_open()){
	    std::cout << "Can't read file : utilisateurs.txt or write in 'temporary.txt'" << std::endl;
	   }
	   else{
	   	getline(myFile, str);
	   	tempFile << str;
    	while (getline(myFile, str)){
    		std::stringstream ss(str);
    		getline(ss, id, ';');
    		if(id.compare(id2compare) != 0){
    			tempFile << std::endl << str;
    		}
    		else{
    			if(pos == 0){
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				getline(ss, secondPart);
    				tempFile << std::endl << id << ";" << firstPart << media << ",(" << secondPart;
    			}
    			else{
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//1
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//2
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//3
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//4
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//5
    				getline(ss, secondPart, ';');
    				getline(ss, secondPart);
    				tempFile << std::endl << id << ";" << firstPart << media << ";" << secondPart;
    			}
    		}
    	}
	}
	myFile.close();
	tempFile.close();
	remove("utilisateurs.txt");
	rename("temporary.txt", "utilisateurs.txt");


}

void utilisateurs::reservation(int idUser, std::string media, int pos){
	users[idUser]->setResReservee(media, pos);

	std::string id;
	std::string id2compare = users[idUser]->getId();
	std::string str;
	std::string firstPart, secondPart, thirdPart;
	std::ifstream myFile("utilisateurs.txt");
	std::ofstream tempFile("temporary.txt");
	   if(!myFile.is_open() || !tempFile.is_open()){
	    std::cout << "Can't read file : utilisateurs.txt or write in 'temporary.txt'" << std::endl;
	   }
	   else{
	   	getline(myFile, str);
	   	tempFile << str;
    	while (getline(myFile, str)){
    		std::stringstream ss(str);
    		getline(ss, id, ';');
    		if(id.compare(id2compare) != 0){
    			tempFile << std::endl << str;
    		}
    		else{
    			if(pos == 0){
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				getline(ss, secondPart);
    				tempFile << std::endl << id << ";" << firstPart << media << ",(" << secondPart;
    			}
    			else{
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				getline(ss, thirdPart, ';');
    				getline(ss, thirdPart);
    				tempFile << std::endl << id << ";" << firstPart << "(" << secondPart << media << ";" << thirdPart;
    			}
    		}
    	}
	}
	myFile.close();
	tempFile.close();
	remove("utilisateurs.txt");
	rename("temporary.txt", "utilisateurs.txt");

}

void utilisateurs::emprunt(int idUser, std::string media, int pos){
	users[idUser]->setResEmpruntee(media, pos);



	//users[idUser]->setDateEmprunt(date, pos); //TODO

	std::string id;
	std::string id2compare = users[idUser]->getId();
	std::string str;
	std::string firstPart, secondPart, thirdPart;
	std::ifstream myFile("utilisateurs.txt");
	std::ofstream tempFile("temporary.txt");
	   if(!myFile.is_open() || !tempFile.is_open()){
	    std::cout << "Can't read file : utilisateurs.txt or write in 'temporary.txt'" << std::endl;
	   }
	   else{
	   	getline(myFile, str);
	   	tempFile << str;
    	while (getline(myFile, str)){
    		std::stringstream ss(str);
    		getline(ss, id, ';');
    		if(id.compare(id2compare) != 0){
    			tempFile << std::endl << str;
    		}
    		else{
    			if(pos == 0){
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;
    				getline(ss, secondPart, '(');
    				getline(ss, secondPart);
    				tempFile << std::endl << id << ";" << firstPart << media << ",(" << secondPart;
    			}
    			else{
    				getline(ss, firstPart, '(');
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//1
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//2
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//3
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//4
    				getline(ss, secondPart, '(');
    				firstPart = firstPart + "(" + secondPart;//5
    				getline(ss, secondPart, ';');
    				getline(ss, secondPart);
    				tempFile << std::endl << id << ";" << firstPart << media << ";" << secondPart;
    			}
    		}
    	}
	}
	myFile.close();
	tempFile.close();
	remove("utilisateurs.txt");
	rename("temporary.txt", "utilisateurs.txt");

}

std::string utilisateurs::getIdClient(int _id){
	return users[_id]->getId();
}


int utilisateurs::peutEmprunter(int idUser){
	std::string id1, id2;
	std::stringstream idResEmpruntee(getResEmpruntee(idUser));
	getline(idResEmpruntee, id1, '(');
	getline(idResEmpruntee, id1, ')');
	getline(idResEmpruntee, id2, '(');
	getline(idResEmpruntee, id2, ')');
	if(id1.compare("0") == 0)
		return 0;
	else if(id2.compare("0") == 0)
		return 1;
	else
		return -1;
}

void utilisateurs::setResRendue(int idUser, std::string infoToSave){
	users[idUser]->setResRendue(infoToSave);
}