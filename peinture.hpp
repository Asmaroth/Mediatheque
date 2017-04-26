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
        peinture(int _hauteur, int _longueur,int _hauteur, int _longueur,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~peinture();
        void setHauteur (int _hauteur);
        int getHauteur ();
        void setLongueur (int _longueur);
        int getLongueur ();
        virtual void info ();
};

#endif
