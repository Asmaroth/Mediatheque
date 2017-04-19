#ifndef MEDIATHEQUE__HPP
#define MEDIATHEQUE__HPP

#include "utilisateurs.hpp"
#include "ressources.hpp"

class mediatheque {
    // Associations
    // Attributes
    protected :
        string nom;
    // Operations
    public :
        void setNom (string _nom);
        string getNom ();
        void info ();
};

#endif
