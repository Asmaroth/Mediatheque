#ifndef DVD__HPP
#define DVD__HPP

#include "vhs.cpp"

class dvd : public vhs {
    // Attributes
    protected :
        int nbrPiste;
        /// tableau
        std::vector<std::string> nomPiste;
    // Operations
    public:
        dvd();
        dvd(int _nbrPiste, std::string _nomPiste,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~dvd();
        void setNbrPiste (int _nbrPiste);
        int getNbrPiste ();
        void setNomPiste (std::string _nomPiste, int _nbrPiste);
        std::string getNomPiste (int _nbrPiste);
        std::string getPiste();
        virtual void info ();
};

#endif
