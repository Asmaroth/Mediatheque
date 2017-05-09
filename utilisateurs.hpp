#ifndef UTILISATEURS__HPP
#define UTILISATEURS__HPP

#include "client.hpp"
#include "admin.hpp"

class utilisateurs {
    // Associations
    // Attributes
    private :
        std::vector<client*> clients;
        std::vector<admin*> adm;
    protected :
        std::vector<client*> users;
    // Operations
    public :
    	utilisateurs(const char *filename);
    	~utilisateurs();
    	void createClient(std::string _buf, client *clt);
    	void createAdmin(std::string _buf, admin *administrateur);
        std::string getUsers ();
        std::string getClient (); //(std::vector<client*> _clients) avant
        std::string getClient(int _id);
        std::string getAdmin ();
        std::string getAdmin(int _id);
        void info ();
        void infoClient(int _id);
        int verifIdClient(std::string idClient);
        int verifMdp(std::string _mdp, int _id);
        void addClient(client *clt);
        void addAdmin(admin *administrateur);
        int getIdUtilisateur(std::string _id);
        void effaceMemoire();
        void reservation(int idClient, int idMedia);
};

#endif