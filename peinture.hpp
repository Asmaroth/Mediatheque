#ifndef PEINTURE__HPP
#define PEINTURE__HPP

#include "media.cpp"

class peinture : public media {
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
