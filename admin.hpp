#ifndef ADMIN__HPP
#define ADMIN__HPP

#include "client.hpp"

class admin : public client {
    // Attributes
    protected :
        std::string mdp;
    // Operations
    public :
        admin();
        //admin(int _id, std::string _nom, std::string _prenom, std::string *_resReservee, media *_resRendue, std::string _resEmpruntee, int *_dateEmprunt, std::string _mdp);
        ~admin();
        void setMdp (std::string _mdp);
        std::string getMdp ();
        virtual void info();
};

#endif