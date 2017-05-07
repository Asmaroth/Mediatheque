#ifndef LIVRE__HPP
#define LIVRE__HPP
#include "media.hpp"

#define NBR_ATTRIB_LIVRE 13

class livre : public media {
    // Attributes
    protected:
        int nbrPage;
        std::string collection;
        std::string resume;
        int note;
    // Operations
    public:

        livre();
        ~livre();
        livre(std::string _id, const char *_titre, const char *_auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, const char *_collection, const char *_resume, int _note);
        livre(std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt, int _nbrPage, std::string _collection, std::string _resume, int _note);
        void setPage (int _nbrPage);
        int getPage ();
        void setCollection (std::string _collection);
        std::string getCollection ();
        void setResume (std::string _resume);
        std::string getResume ();
        void setNote (int _note);
        int getNote ();
        virtual void info ();
        virtual void infoAdmin();
        virtual std::string infoToSave();
};

#endif
