#ifndef CLIENT__HPP
#define CLIENT__HPP

#include <vector>
#include <iostream> // std::cout
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream>
#include <ostream>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <string>

#define LIMITE_RESERVATION 2
#define LIMITE_EMPRUNT 2

#include "media.hpp"

class client {
    // Attributes
    protected :
        std::string id;
        std::string nom;
        std::string prenom;
        std::string resReservee[LIMITE_RESERVATION];
        std::vector<std::string> resRendue;
        std::string resEmpruntee[LIMITE_EMPRUNT];
        std::string dateEmprunt[LIMITE_EMPRUNT];
    // Operations
    public :
        client();
        //client(std::string _id, std::string _nom, std::string _prenom, std::string *_resReservee, media *_resRendue, std::string *_resEmpruntee, int *_dateEmprunt);
        ~client();
        void initTableau(std::string *tab, int taille);
        //void initTableau(int tab, int taille);
        void setId(std::string _id);
        std::string getId ();
        void setNom(std::string _nom);
        std::string getNom ();
        void setPrenom(std::string _prenom);
        std::string getPrenom();
        void setResReservee (std::string _resReservee, int _idResReservee);
        std::string getResReservee ();
        std::string getResReservee (int _idResReservee);
        //void setResRendue (media *_resRendue);
        void setResRendue(std::string infoToSave);
        std::string getResRendue ();
        std::string getResRendue (int _idResRendue);
        void setResEmpruntee (std::string _resEmpruntee, int _idResEmpruntee);
        std::string getResEmpruntee ();
        std::string getResEmpruntee (int _idResEmpruntee);
        void setDateEmprunt (std::string _dateEmprunt, int _idDateEmprunt);
        std::string getDateEmprunt ();
        std::string getDateEmprunt (int _idDateEmprunt);
        virtual void info ();
};

#endif