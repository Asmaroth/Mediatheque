#ifndef CD__HPP
#define CD__HPP

#include "media.cpp"

class cd : public media {
    // Attributes
    protected:

        int duree;
        int nbrPiste;
        std::string maisonDisque;
        /// tableau
        std::vector<std::string> titrePiste;
        int note;
    // Operations
    public:

        cd();
        cd(int _duree, int _nbrPiste, std::string _maisonDisque, std::string _titrePiste, int _note,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~cd();
        void setDuree (int _duree);
        int getDuree ();
        void setNbrPiste (int _nbrPiste);
        int getNbrPiste ();
        void setMaisonDisque (std::string _maisonDisque);
        std::string getMaisonDisque ();
        void setTitrePiste (std::string _titrePiste, int _idPiste);
        std::string getTitrePiste (int _idPiste);
        std::string getTitre();
        void setNote (int _note);
        int getNote ();
        void info ();
};

#endif
