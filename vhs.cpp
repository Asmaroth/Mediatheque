#include "vhs.hpp"


vhs::vhs()
{
        duree = 0;
        maisonProduction = "inconnu";
        note = 0;
}

vhs::vhs(int _duree, std::string _maisonProduction, int _note)
{
    duree = _duree;
    maisonProduction = _maisonProduction;
    note = _note;
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
