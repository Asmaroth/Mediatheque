#ifndef RESSOURCES__HPP
#define RESSOURCES__HPP

#include "mediat.hpp"

class ressources {
    // Associations
    // Attributes
    protected :
        int nbrRessource;
        /// vecteur
        string typeRessource;
        int stock;
    // Operations
    public :
        void setNbrRessource (int _nbrRessource);
        int getNbrRessource ();
        void setTypeRessource (string _nomRessource);
        string getTypeRessource ();
        void setStock (int _stock);
        int getStock ();
        void info ();
};

#endif
