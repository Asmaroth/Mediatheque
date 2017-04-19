#ifndef REVUES__HPP
#define REVUES__HPP

#include "livre.hpp"

class revues : public livre {
    // Attributes
    protected :
        string editeur;
        int nbrArticle;
        /// tableau
        string nomArticle;
    // Operations
    public :
        void setEditeur (string _editeur);
        string getEditeur ();
        void setNbrArticle (int _nbrArticle);
        int getNbrArticle ();
        void setNomArticle (string _nomArticle, int _idArticle);
        string getNomArticle (int _idArticle);
        void info ();
};

#endif
