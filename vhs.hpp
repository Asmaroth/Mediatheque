#ifndef VHS__HPP
#define VHS__HPP

#include "mediat.hpp"

class vhs : public mediat {
    // Attributes
    protected :
        /// duree en s
        int duree;
        string maisonProduction;
        int note;
    // Operations
    public :
        void setDuree (int _duree);
        int getDuree ();
        void setMaisonProduction (string _maisonProduction);
        string getMaisonProduction ();
        void setNote (int _note);
        int getNote ();
        void info ();
};

#endif
