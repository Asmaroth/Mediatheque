#ifndef UTILISATEURS__HPP
#define UTILISATEURS__HPP

#include "client.cpp"
//#include "admin.cpp"

class utilisateurs {
    // Associations
    // Attributes
    private :
        std::vector<client*> clients;
        //std::vector<admin*> admin;
    protected :
        std::vector<client*> nomUtilisateurs;
    // Operations
    public :
    	utilisateurs(const char *filename);
    	~utilisateurs();
    	void createClient(std::string _buf, client *clt);
    	void createAdmin(std::string _buf, client *adm);
        //void setNomUtilisateur (std::string _nomUtilisateur);
        std::string getNomUtilisateur ();
        std::string getClient (std::vector<client*> _clients);
        std::string getAdmin ();
        void info ();
};

#endif
