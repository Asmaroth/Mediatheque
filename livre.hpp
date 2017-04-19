#ifndef LIVRE__HPP
#define LIVRE__HPP

#include "mediat.hpp"

class livre : public mediat {
    // Attributes
    protected :
        int nbrPage;
        string collection;
        string resume;
        int note;
    // Operations
    public :
        void setPage (int _nbrPage);
        int getPage ();
        void setCollection (string _collection);
        string getCollection ();
        void setResume (string _resume);
        string getResume ();
        void setNote (int _note);
        int getNote ();
        void info ();
};

#endif
