#ifndef PEINTURE__HPP
#define PEINTURE__HPP

#include "mediat.hpp"

class peinture : public mediat {
    // Attributes
    protected:
        int hauteur;
        int longueur;
    // Operations
    public:

        peinture();
        peinture(int _hauteur, int _longueur);
        ~peinture();
        void setHauteur (int _hauteur);
        int getHauteur ();
        void setLongueur (int _longueur);
        int getLongueur ();
        virtual void info ();
};

#endif
