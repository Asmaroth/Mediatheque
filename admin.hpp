#ifndef ADMIN__HPP
#define ADMIN__HPP

#include "client.hpp"

class admin : public client {
    // Attributes
    protected :
        string mdp;
    // Operations
    public :
        void setMdp (string _mdp);
        string getMdp ();
        void add (string _type);
        void info ();
        void delete (int _id);
        void reset ();
};

#endif
