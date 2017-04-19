#ifndef MEDIAT__HPP
#define MEDIAT__HPP

/**
 * \brief Contient toutes les ressources de la médiathèque
 *        Ajouter un "info" ou pas ?
 */
class media {
    // Attributes
    protected :
        std::string titre;
        std::string auteur;
        int annee;
        int disponible;
        int stock;
        int dureeEmprunt;
        int dateEmprunt;
    // Operations
    public :
        media();
        media(std::string _titre, std::string _auteur, int _annee, int _disponible, int _stock, int _dureeEmprunt, int _dateEmprunt);
        ~media();
        void reserver ();
        void emprunter ();
        void rendre ();
        void setTitre (std::string _titre);
        string getTitre ();
        void setAuteur (std::string _auteur);
        string getAuteur ();
        void setAnnee (int _annee);
        int getAnnee ();
        void setDisponible (int _disponible);
        int getDisponible ();
        void setStock (int _stock);
        int getStock ();
        void setDureeEmprunt (int _dureeEmprunt);
        int getDureeEmprunt ();
        void setDateEmprunt (int _dateEmprunt);
        int getDateEmprunt ();
        void info();
};

#endif
