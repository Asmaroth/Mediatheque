#ifndef MEDIATHEQUE__HPP
#define MEDIATHEQUE__HPP

//#include "utilisateurs.hpp"
//#include "ressources.hpp"

class mediatheque {
    // Attributes
    protected :
        std::string nom;
    // Operations
    public :
    	mediatheque();
    	mediatheque(std::string _nom);
    	~mediatheque();
        void setNom (std::string _nom);
        std::string getNom ();
        void info ();
};

#endif
