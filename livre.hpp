#ifndef LIVRE__HPP
#define LIVRE__HPP

#include "mediat.hpp"

class livre : public mediat {
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
        livre(int _nbrPage, std::string _collection, std::string _resume, int _note);
        void setPage (int _nbrPage);
        int getPage ();
        void setCollection (std::string _collection);
        std::string getCollection ();
        void setResume (std::string _resume);
        std::string getResume ();
        void setNote (int _note);
        int getNote ();
        void info ();
};

#endif
