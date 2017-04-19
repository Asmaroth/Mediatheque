#ifndef RESSOURCES__HPP
#define RESSOURCES__HPP

class ressources {
    // Associations
    // Attributes
    protected:

        int nbrRessource;
        /// vecteur
        std::vector<std::string> typeRessource;
        int stock;
    // Operations
    public:

    	ressources();
    	~ressources();
    	ressources(int _nbrRessource , std::string _nomRessource , int _stock);
        void setNbrRessource (int _nbrRessource);
        int getNbrRessource ();
        void setTypeRessource (std::string _nomRessource);
        std::string getTypeRessource ();
        void setStock (int _stock);
        int getStock ();
        void info ();
};

#endif
