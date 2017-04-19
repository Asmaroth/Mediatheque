#ifndef CD__HPP
#define CD__HPP

#include "mediat.hpp"

class cd : public mediat {
    // Attributes
    protected :
        int duree;
        int nbrPiste;
        string maisonDisque;
        /// tableau
        string titrePiste;
        int note;
    // Operations
    public :
        void setDuree (int _duree);
        int getDuree ();
        void setNbrPiste (int _nbrPiste);
        int getNbrPiste ();
        void setMaisonDisque (string _maisonDisque);
        string getMaisonDisque ();
        void setTitrePiste (string _titrePiste, int _idPiste);
        string getTitrePiste (int _idPiste);
        void setNote (int _note);
        int getNote ();
        void info ();
};

#endif
