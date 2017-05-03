#include "utilisateurs.hpp"

#define NBR_DATA_USER 7
#define NBR_DATA_ADMIN 8

void utilisateurs::createClient(std::string _buf, client *clt){
	std::string str;
	std::string data[NBR_DATA_USER];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_USER ; i++){
		getline(ss, str, ';');
		data[i] = str;
	}
	clt->setId(5);
	clt->setNom(data[1]);
	clt->setPrenom(data[2]);
	//clt->set
	
}


/*admin utilisateurs::createAdmin(std::string _buf){
	std::string data[NBR_DATA_ADMIN];
	std::stringstream ss(_buf);
	for (int i = 0 ; i < NBR_DATA_ADMIN ; i++)
		getline(ss, data[i], ';');
	admin *newAdmin = new admin(atoi(data[0].c_str()), data[1], data[2], data[3], data[4], data[5], data[6]);
	return newAdmin;
}*/

utilisateurs::utilisateurs(const char *filename){
    std::string buf;
	std::ifstream myFile(filename);
	//client *_client;
    //admin *_admin;
    if(!myFile.is_open()){
    	std::cout << "Can't read file : " << filename <<std::endl;
    }
    else{
    	while (getline(myFile, buf)){
    		if (buf[0] == '1'){
    			//creation du client
    			std::cout << "Creation d'un Client." << std::endl;
    			client *clt = new client();
    			createClient(buf, clt);
    			clients.push_back(clt);
    		}
  			/*else if(buf[0] == '0'){
				//creation d'un admin
				std::cout << "creation d'un admin" << std::endl;
				admin *adm = new admin();
				//createAdmin(buf, adm);
				admin.push_back(adm);
			}*/
			else
				std::cout << "Impossible de créer l'utilisateur : " << buf << std::endl;
    	}
    	info();
    }
}

utilisateurs::~utilisateurs(){};

/*void utilisateurs::setNomUtilisateur(std::string _nomUtilisateurs){
	nomUtilisateurs = _nomUtilisateurs;
}*/

std::string utilisateurs::getNomUtilisateur(){
	std::string str;
	for (int i = 0 ; i < nomUtilisateurs.size() ; i++){
		str = str + ", " + nomUtilisateurs[i]->getNom();
	}
	str = str + ".";
	return str;
}

std::string utilisateurs::getClient(std::vector<client*> _clients){ //possible de connaitre le type pour différencier client et admin ? Sinon utilisation d'un ID spécifique
	std::string str = "Les clients sont :\n";
	for (int i = 0 ; i < _clients.size() ; i++){
		str = str + "\t(" /*+ int2str(_clients[i]->getId())*/ + "TEST) " + _clients[i]->getNom() + " " + _clients[i]->getPrenom() + "\n";
	}
	return str;
}

/*std::string utilisateurs::getAdmin(std::vector<admin*> _admin){ //possible de connaitre le type pour différencier client et admin ? Sinon utilisation d'un ID spécifique
	std::string str = "Les administrateurs sont :\n";
	for (int i = 0 ; i < _admin.size() ; i++){
		if (nomUtilisateurs[i]->getId()[0] == 0) //identifiant admin : commence par un 0
			str = str + "\t(" + _clients[i]->getId() + ") " + _clients[i]->getNom() + " " + _clients[i]->getPrenom() + "\n";
	}
	return str;
}*/

void utilisateurs::info(){
	std::string listeClients = getClient(clients);
	//std::string listeAdmin = getAdmin(admin);
	std::cout << "Il y a " << clients.size() /*+ admin.size()*/ << " utilisateurs de la médiathèque, dont " << clients.size() << " clients et " << /*admin.size()*/ "TEST" << " administrateurs.\n" << listeClients <</* listeAdmin <<*/ std::endl;
}