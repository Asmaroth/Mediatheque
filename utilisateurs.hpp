#ifndef UTILISATEURS__HPP
#define UTILISATEURS__HPP

#include "client.hpp"
#include "admin.hpp"

class utilisateurs {
    // Associations
    // Attributes
    private:
        std::vector<client*> clients;
        std::vector<admin*> adm;
    protected:
        std::vector<client*> users;
    // Operations
    public:
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
        void emprunt(int idClient, int idMedia);
        std::string getResEmpruntee(int idClient);
        std::string getResReservee(int idClient);
        void retour(int idUser, int idMedia);
        void reservation(int idUser, std::string media, int pos);
        std::string getIdClient(int _id);
        void deleteAdmin(int _idAdmin, std::string admin2suppr);
        void deleteClient(int _idClient, std::string client2suppr);
        int getIdAdmin(std::string _id);
        int getIdClient(std::string _id);
        int str2int(std::string str);
        std::string int2str(int nbr);
};

#endif