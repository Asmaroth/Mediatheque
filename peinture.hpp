#ifndef PEINTURE__HPP
#define PEINTURE__HPP


class peinture : public media {
    // Attributes
    protected:
        int hauteur;
        int longueur;
    // Operations
    public:

        peinture();
        peinture(int _hauteur, int _longueur,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~peinture();
        virtual void setHauteur (int _hauteur);
        virtual int getHauteur ();
        virtual void setLongueur (int _longueur);
        virtual int getLongueur ();
        virtual void info ();
};

#endif
