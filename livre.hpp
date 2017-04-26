#ifndef LIVRE__HPP
#define LIVRE__HPP

#include "media.cpp"

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
        livre(int _nbrPage, std::string _collection, std::string _resume, int _note, int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
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
};

#endif
