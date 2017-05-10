#ifndef VHS__HPP
#define VHS__HPP

#include "media.hpp"

class vhs : public media {
    // Attributes
    protected:
        /// duree en s
        int duree;
        std::string maisonProduction;
        int note;
    // Operations
    public:

        vhs();
        vhs(int _duree, std::string _maisonProduction, int _note,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~vhs();
        virtual void setDuree (int _duree);
        virtual int getDuree ();
        virtual void setMaisonProduction (std::string _maisonProduction);
        virtual std::string getMaisonProduction ();
        virtual void setNote (int _note);
        virtual int getNote ();
        virtual void info ();
        virtual std::string infoToSave();
};

#endif
