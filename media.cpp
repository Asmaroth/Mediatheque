#include "media.hpp"

media::media(){
	id = "0";
	titre = "Aucun";
    auteur = "Inconnu";
    type = "Indéfini";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = 0;
    idClient = "0";
}

media::media(std::string _id, std::string _titre, std::string _auteur, std::string _type, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, std::string _idClient){
	id = _id;
	titre = _titre;
	auteur = _auteur;
	type = _type;
	annee = _annee;
	disponible = _disponible;
	dureeEmprunt = _dureeEmprunt;
	dateEmprunt = _dateEmprunt;
	idClient = _idClient;
}

media::~media(){};

void media::reserver(){
	disponible = 0;
}

void media::emprunter(){
	disponible = 1;
}

void media::rendre(){
	disponible = 3;
}

void media::setId(std::string _id){
	id = _id;
}

std::string media::getId(){
	return id;
}

void media::setTitre (std::string _titre){
	titre = _titre;
}

std::string media::getTitre (){
	return titre;
}

void media::setAuteur (std::string _auteur){
	auteur = _auteur;
}

std::string media::getAuteur (){
	return auteur;
}

void media::setType (std::string _type){
	type = _type;
}

std::string media::getType (){
	return type;
}

void media::setAnnee (int _annee){
	annee = _annee;
}

int media::getAnnee (){
	return annee;
}

void media::setDisponible (int _disponible){
	disponible = _disponible;
}

int media::getDisponible (){
	return disponible;
}

void media::setDureeEmprunt (int _dureeEmprunt){
	dureeEmprunt = _dureeEmprunt;
}

int media::getDureeEmprunt (){
	return dureeEmprunt;
}

void media::setDateEmprunt (int _dateEmprunt){
	dateEmprunt = _dateEmprunt;
}

int media::getDateEmprunt (){
	return dateEmprunt;
}

void media::setIdClient(std::string _idClient){
	idClient = _idClient;
}

std::string media::getIdClient(){
	return idClient;
}

std::string media::int2str(int nbr)
{
	std::stringstream ss;
	ss << nbr;
	return ss.str();
}

void media::info(){
	std::string str;
	if (disponible == 0)
		str = "réservé";
	else if (disponible == 1)
		str = "emprunté";
	else if (disponible == 2)
		str = "indisponible";
	else
		str = "disponible";
	std::cout << "(" << id << ") " << titre << ", de " << auteur << " est paru en " << annee << ". Il est actuellement " << str << "." << std::endl;
}

void media::infoAdmin(){
	std::cout << "Ce media a été emprunté par (" << idClient << ") le " << dateEmprunt << " pour une durée maximale de " << dureeEmprunt << ".\n" << std::endl;	
	info();
}

std::string media::infoToSave(){
	std::string str = getId() + ';' + getTitre() + ';' + getAuteur()  + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';' + getIdClient();
	return str;
}

int media::str2int(std::string str)
{
	int result;
	std::stringstream ss(str);
	if(!(ss>>result))
		return 0;
	return result;
}

int media::getVersion()
{
	return version;
}

void media::setVersion(std::string _version)
{
	version = str2int(_version);
}

int media::getPage (){

}

std::string media::getCollection (){

}

std::string media::getResume (){

}

int media::getNote (){

}

std::string media::getEditeur (){

}

int media::getNbrArticle (){

}

std::string media::getNomArticle (int _idArticle){

}

std::string media::getArticle(){

}

int media::getDuree (){

}

int media::getNbrPiste (){

}

std::string media::getMaisonDisque (){

}

std::string media::getTitrePiste (int _idPiste){

}

std::string media::getTitreAll(){

}

std::string media::getNomPiste (int _nbrPiste){

}

std::string media::getNomPiste (){

}

std::string media::getPiste(){

}

int media::getHauteur (){

}

int media::getLongueur (){

}

std::string media::getFormat (){

}

int media::getTaille (){

}

std::string media::getPath (){

}

std::string media::getMaisonProduction (){

}

void media::setPage (int _nbrPage){

}

void media::setCollection (std::string _collection){

}

void media::setResume (std::string _resume){

}

void media::setNote (int _note){

}

void media::setEditeur (std::string _editeur){

}

void media::setNbrArticle (int _nbrArticle){

}

void media::setNomArticle (std::string _nomArticle, int _idArticle){

}

void media::setNomArticle (std::string _nomArticle){

}

void media::setDuree (int _duree){

}

void media::setMaisonProduction (std::string _maisonProduction){

}

void media::setNbrPiste (int _nbrPiste){

}

void media::setNomPiste (std::string _nomPiste, int _nbrPiste){

}

void media::setNomPiste(std::string _nomPiste){

}


void media::setMaisonDisque (std::string _maisonDisque){

}

void media::setTitrePiste (std::string _titrePiste, int _idPiste){

}

void media::setTitrePiste(std::string _titrePiste){

}


void media::setFormat (std::string _format){

}

void media::setTaille (int _taille){

}

void media::setPath (std::string _path){

}

void media::setHauteur (int _hauteur){

}

void media::setLongueur (int _longueur){

}
