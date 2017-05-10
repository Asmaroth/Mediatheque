#include "vhs.hpp"


vhs::vhs()
{
    duree = 0;
    maisonProduction = "inconnu";
    note = 0;
    id = '0';
    titre = "Aucun";
    auteur = "Inconnu";
    annee = -1;
    disponible = 2;
    dureeEmprunt = -1;
    dateEmprunt = -1;
    type = "vhs";
}

vhs::vhs(int _duree, std::string _maisonProduction, int _note,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt)
{
    duree = _duree;
    maisonProduction = _maisonProduction;
    note = _note;
    id = _id;
    titre = _titre;
    auteur = _auteur;
    annee = _annee;
    disponible = _disponible;
    dureeEmprunt = _dureeEmprunt;
    dateEmprunt = _dateEmprunt;
    type = "vhs";
}

vhs::~vhs(){}

void vhs::setDuree (int _duree)
{
    duree = _duree;
}

int vhs::getDuree ()
{
    return duree;
}

void vhs::setMaisonProduction (std::string _maisonProduction)
{
    maisonProduction = _maisonProduction;
}

std::string vhs::getMaisonProduction ()
{
    return maisonProduction;
}

void vhs::setNote (int _note)
{
    note = _note;
}

int vhs::getNote ()
{
    return note;
}

void vhs::info ()
{
        std::cout << "Cette cassette dure " << getDuree() << " et est produit par " << getMaisonProduction() << std::endl
              << "Sa note est de " << getNote() << std::endl;
}

std::string vhs::infoToSave(){
    std::string str = getId() + ';' + getTitre() + ';' + getAuteur()  + ';' + int2str(getAnnee()) + ';' + int2str(getDisponible()) + ';' + int2str(getDureeEmprunt()) + ';' + int2str(getDateEmprunt()) + ';' /*+ int2str(getIdClient()) + ';'*/ + int2str(getDuree()) + ';' + getMaisonProduction() + ';' + int2str(getNote());
    return str;
}