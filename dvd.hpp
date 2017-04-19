#ifndef DVD__HPP
#define DVD__HPP

#include "vhs.hpp"

class dvd : public vhs {
    // Attributes
    protected :
        int nbrPiste;
        /// tableau
        string nomPiste;
    // Operations
    public :
        void setNbrPiste (int _nbrPiste);
        int getNbrPiste ();
        void setNomPiste (string _nomPiste, int _nbrPiste);
        string getNomPiste (int _nbrPiste);
        void info ();
};

#endif
