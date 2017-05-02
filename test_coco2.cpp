#include <vector>
#include <iostream>	// std::cout
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream>
#include <ostream>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <string>	//std::string   std::to_string

#define TROUDUCUL 5

//#include "utilisateurs.cpp"

//using namespace std;

int main(){
	/*utilisateurs *users = new utilisateurs("utilisateurs.txt");
	delete users;*/



	/*std::string resReservee[3] = {"Livre 1", "Livre 2", "Livre 3"};
	std::string str;
	std::stringstream ss;
	for (int i = 0 ; i < 3 ; i++){
		str = str + resReservee[i];
		if (i + 1 < 3)
			str = str + ", ";
	}
	std::cout << str << std::endl;*/


	/*std::string str;			//conversion int->string
	int nbr = 123;
	std::stringstream ss;
	ss << nbr;
	str = ss.str();
	std::cout << str << std::endl;*/



	/*int resReservee[2];
	int i = 0;
	std::stringstream ss("01012017,01022017");
	std::string str;
	while(getline(ss, str, ','))
    	resReservee[i++] = atoi(str.c_str());
    std::cout << str << std::endl;*/


	/*std::string str = "cou";
	str = str + "cou" + "3";
	std::cout << str << TROUDUCUL << std::endl;*/

	/*std::string data;
	std::stringstream ss("100;DUPONT ;JEAN ;aucune ;aucune ;aucune ;0");
	for (int i = 0 ; i < 7 ; i++){
		getline(ss, data, ';');
		std::cout << data << std::endl;
	}*/



	std::string str;
	std::stringstream ss("100;DUPONT ;JEAN ;aucune ;aucune ;aucune ;0\n100 ;BELLICAULT ;CORENTIN ;aucune ;aucune ;aucune ;0");
	getline(ss, str, ';');
	std::cout << atoi(str.c_str()) + 5 << std::endl;
	getline(ss, str, ';');
	std::cout << str << std::endl;
	getline(ss, str, ';');
	std::cout << str << std::endl;

	int min  = std::min(13,15);
	std::cout << min << std::endl;

	while(getline(ss, str, ';'))
		std::cout << str << std::endl;


	/*const char *path = "utilisateurs.txt";
	std::string buf;
	std::ifstream myFile(path);
    if(!myFile.is_open()){
    	std::cout << "Can't read file : " << path <<std::endl;
    }
    else{
    	while (getline(myFile, buf)){
    		if (buf[0] == '1'){
    			//creation du client

    			//clients.push_back(_client);
    			std::cout << "creation d'un client" << std::endl;
    		}
  			else if(buf[0] == '0'){
				//creation de l'admin
				//admin.push_back(_admin);
				std::cout << "creation d'un admin" << std::endl;
			}
			else
				std::cout << "Impossible de créer l'utilisateur : " << buf << std::endl;
    	}
    }*/
	//return EXIT_SUCCESS;
}