#ifndef VHS__HPP
#define VHS__HPP

#include "media.cpp"

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
        void setDuree (int _duree);
        int getDuree ();
        void setMaisonProduction (std::string _maisonProduction);
        std::string getMaisonProduction ();
        void setNote (int _note);
        int getNote ();
        virtual void info ();
};

#endif
