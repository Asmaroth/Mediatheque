#ifndef MEDIAT__HPP
#define MEDIAT__HPP

#include <string>

/**
 * \brief Contient toutes les ressources de la médiathèque
 *        Ajouter un "info" ou pas ?
 */

class media {
    // Attributes
    protected :
        std::string id;
        std::string titre;
        std::string auteur;
        std::string type;
        int annee;
        int disponible;     //0 = réservé, 1 = emprunté, 2 = non disponible (utile ?), 3 = disponible
        int dureeEmprunt;
        int dateEmprunt;
        int idClient;
    // Operations
    public :
        media();
        media(std::string _id, std::string _titre, std::string _auteur, std::string _type, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~media();
        void reserver ();
        void emprunter ();
        void rendre ();
        void setId(std::string _id);
        std::string getId();
        void setTitre (std::string _titre);
        std::string getTitre ();
        void setAuteur (std::string _auteur);
        std::string getAuteur ();
        void setType (std::string _type);
        std::string getType ();
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
        std::string int2str(int nbr);
        virtual void info();
        virtual void infoAdmin();
        virtual std::string infoToSave();
        virtual int getPage ();
        virtual std::string getCollection ();
        virtual std::string getResume ();
        virtual int getNote ();
        virtual std::string getEditeur ();
        virtual int getNbrArticle ();
        virtual std::string getNomArticle (int _idArticle);
        virtual std::string getArticle();
        virtual int getDuree ();
        virtual int getNbrPiste ();
        virtual std::string getMaisonDisque ();
        virtual std::string getTitrePiste (int _idPiste);
        virtual std::string getTitreAll();
        virtual std::string getNomPiste (int _nbrPiste);
        virtual std::string getNomPiste ();
        virtual std::string getPiste();
        virtual int getHauteur ();
        virtual int getLongueur ();
        virtual std::string getFormat ();
        virtual int getTaille ();
        virtual std::string getPath ();
        virtual std::string getMaisonProduction ();

        virtual void setPage (int _nbrPage);
        virtual void setCollection (std::string _collection);
        virtual void setResume (std::string _resume);
        virtual void setNote (int _note);
        virtual void setEditeur (std::string _editeur);
        virtual void setNbrArticle (int _nbrArticle);
        virtual void setNomArticle (std::string _nomArticle, int _idArticle);
        virtual void setNomArticle (std::string _nomArticle);
        virtual void setDuree (int _duree);
        virtual void setMaisonProduction (std::string _maisonProduction);
        virtual void setNbrPiste (int _nbrPiste);
        virtual void setNomPiste (std::string _nomPiste, int _nbrPiste);
        virtual void setNomPiste(std::string _nomPiste);
        virtual void setMaisonDisque (std::string _maisonDisque);
        virtual void setTitrePiste (std::string _titrePiste, int _idPiste);
        virtual void setTitrePiste(std::string _titrePiste);
        virtual void setFormat (std::string _format);
        virtual void setTaille (int _taille);
        virtual void setPath (std::string _path);
        virtual void setHauteur (int _hauteur);
        virtual void setLongueur (int _longueur);
};

#endif
