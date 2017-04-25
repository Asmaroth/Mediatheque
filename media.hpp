#ifndef MEDIAT__HPP
#define MEDIAT__HPP

/**
 * \brief Contient toutes les ressources de la médiathèque
 *        Ajouter un "info" ou pas ?
 */

class media {
    // Attributes
    protected :
        int id;
        std::string titre;
        std::string auteur;
        int annee;
        int disponible;     //0 = réservé, 1 = emprunté, 2 = non disponible (utile ?), 3 = disponible
        int dureeEmprunt;
        int dateEmprunt;
        int idClient;
    // Operations
    public :
        media();
        media(int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~media();
        void reserver ();
        void emprunter ();
        void rendre ();
        void setId(int _id);
        int getId();
        void setTitre (std::string _titre);
        std::string getTitre ();
        void setAuteur (std::string _auteur);
        std::string getAuteur ();
        void setAnnee (int _annee);
        int getAnnee ();
        void setDisponible (int _disponible);
        int getDisponible ();
        void setDureeEmprunt (int _dureeEmprunt);
        int getDureeEmprunt ();
        void setDateEmprunt (int _dateEmprunt);
        int getDateEmprunt ();
        void setIdClient(int _idClient);
        int getIdClient();
        void info();
        void infoAdmin();
};

#endif