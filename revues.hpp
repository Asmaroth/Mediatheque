#ifndef REVUES__HPP
#define REVUES__HPP
#include "media.hpp"

//#include "livre.hpp"      //dans la version finale, on doit inclure .hpp et non pas .cpp
#include <string>
#include <vector>

class revues : public livre {
    // Attributes
    protected:

        std::string editeur;
        int nbrArticle;
        /// tableau
        std::vector<std::string>  nomArticle;
    // Operations
    public:

        revues();
        ~revues();
        revues(std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, std::string _collection, std::string _resume, int _note, std::string _editeur, int _nbrArticle, std::string _nomArticle);
        virtual void setEditeur (std::string _editeur);
        virtual std::string getEditeur ();
        virtual void setNbrArticle (int _nbrArticle);
        virtual int getNbrArticle ();
        virtual void setNomArticle (std::string _nomArticle, int _idArticle);
        virtual void setNomArticle (std::string _nomArticle);
        virtual std::string getNomArticle (int _idArticle);
        virtual std::string getArticle();
        virtual void info ();
        virtual void infoAdmin();
        virtual std::string infoToSave();
};

#endif
