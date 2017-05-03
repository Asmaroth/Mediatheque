#ifndef DVD__HPP
#define DVD__HPP
#include "media.hpp"

class dvd : public vhs {
    // Attributes
    protected:

        int nbrPiste;
        /// tableau
        std::vector<std::string> nomPiste;
    // Operations
    public:
        dvd();
        dvd(int _nbrPiste, std::string _nomPiste,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~dvd();
        virtual void setNbrPiste (int _nbrPiste);
        int getNbrPiste ();
        void setNomPiste (std::string _nomPiste, int _nbrPiste);
        void setNomPiste(std::string _nomPiste);
        std::string getNomPiste (int _nbrPiste);
        std::string getPiste();
        virtual void info ();
};

#endif
