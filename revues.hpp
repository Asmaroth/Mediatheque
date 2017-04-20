#ifndef REVUES__HPP
#define REVUES__HPP

#include "livre.hpp"

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
        revues(std::string _editeur, int _nbrArticle, std::string _nomArticle);
        void setEditeur (std::string _editeur);
        std::string getEditeur ();
        void setNbrArticle (int _nbrArticle);
        int getNbrArticle ();
        void setNomArticle (std::string _nomArticle, int _idArticle);
        std::string getNomArticle (int _idArticle);
        std::string getArticle();
        virtual void info ();
};

#endif
