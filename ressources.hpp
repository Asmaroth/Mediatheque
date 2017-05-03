#ifndef RESSOURCES__HPP
#define RESSOURCES__HPP

#include <string>
#include <vector>
#include "media.hpp"
#include <iostream>
#include <fstream>


#define NBR_DATA_LIVRE 11
#define NBR_DATA_REVUES 14

class ressources {
    // Attributes
    private:
        std::vector<media*> medias;
        std::vector<media*> mediaSave; //use mediaSave.swap(medias)

    protected:

        std::vector<std::string> typeRessource;
        int nbrRessource; //utile ?
        int stock;
    // Operations
    public:

    	ressources();
    	~ressources();
    	ressources(int _nbrRessource, std::string _nomRessource, int _stock);
        void setNbrRessource (int _nbrRessource);
        int getNbrRessource ();
        void setTypeRessource (std::string _nomRessource);
        std::string getTypeRessource ();
        void setStock (int _stock);
        int getStock ();
        void info ();
        int str2int(std::string str);
        std::string int2str(int nbr);
        void createLivre(std::string _buf, livre *lvr);
        void createRevues(std::string _buf, revues *rev);
        //void createCd(std::string _buf, cd *cd);
        //void createDvd(std::string _buf, dvd *dvd);
        //void createResNumerique(std::string _buf, resNumerique *resNum);
        //void createVhs(std::string _buf, vhs *vhs);
        //void createPeinture(std::string _buf, peinture *ptr);
        void load(const char *filename);
        void save(const char *filename);
        void clear();
        void show(std::string _id); //revoir par rapport a ID ?
        void list();
        void deleteMedia(int _id);  //revoir par rapport a ID ?
        void reset();
};

#endif
