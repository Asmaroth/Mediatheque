#ifndef VHS__HPP
#define VHS__HPP

#include "mediat.hpp"

class vhs : public mediat {
    // Attributes
    protected:
        /// duree en s
        int duree;
        std::string maisonProduction;
        int note;
    // Operations
    public:

        vhs();
        vhs(int _duree, std::string _maisonProduction, int _note);
        ~vhs();
        void setDuree (int _duree);
        int getDuree ();
        void setMaisonProduction (std::string _maisonProduction);
        std::string getMaisonProduction ();
        void setNote (int _note);
        int getNote ();
        virtual void info ();
};

#endif
