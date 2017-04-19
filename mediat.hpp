#ifndef MEDIAT__HPP
#define MEDIAT__HPP

/**
 * \brief Contient toutes les ressources de la médiathèque
 *        Ajouter un "info" ou pas ?
 */
class mediat {
    // Attributes
    protected :
        string titre;
        string auteur;
        int annee;
        int disponible;
        int stock;
        int duree_emprunt;
        int date_emprunt;
    // Operations
    public :
        void reserver ();
        void emprunter ();
        void rendre ();
        void setTitre (string _titre);
        string getTitre ();
        void setAuteur (string _auteur);
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
};

#endif
