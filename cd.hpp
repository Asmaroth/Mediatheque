#ifndef CD__HPP
#define CD__HPP

#include "mediat.hpp"

class cd : public mediat {
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
        cd(int _duree, int _nbrPiste, std::string _maisonDisque, std::string _titrePiste, int _note);
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
