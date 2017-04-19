#ifndef UTILISATEURS__HPP
#define UTILISATEURS__HPP

#include "client.cpp"

class utilisateurs {
    // Associations
    // Attributes
    private :
        std::vector<client*> clients;
        std::vector<admin*> admin;
    protected :
        int nbrUtilisateurs;
        std::vector<client*> nomUtilisateurs;
    // Operations
    public :
    	utilisateurs(const char *filename);
    	~utilisateurs();
    	void utilisateurs::createClient(const char *data);
    	void utilisateurs::createAdmin(const char *data);
        void setNbrUtilisateur (int _nbrUtilisateur);
        int getNbrUtilisateur ();
        void setNomUtilisateur (std::string _nomUtilisateur);
        std::string getNomUtilisateur ();
        std::string getClient ();
        std::string getAdmin ();
        void info ();
};

#endif
