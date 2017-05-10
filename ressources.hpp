#ifndef RESSOURCES__HPP
#define RESSOURCES__HPP

#include <string>
#include <vector>
#include "media.hpp"
#include <iostream>
#include <fstream>


#define NBR_DATA_LIVRE 12
#define NBR_DATA_REVUES 15
#define NBR_DATA_CD 13
#define NBR_DATA_VHS 11
#define NBR_DATA_DVD 13
#define NBR_DATA_RESNUM 11
#define NBR_DATA_PTR 10

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
        int getNbrRessource ();
        void setTypeRessource (std::string _nomRessource);
        std::string getTypeRessource ();
        void setStock (int _stock);
        int getStock ();
        void info ();
        void info (int _id);
        std::string infoPrincipales(int _id);
        int str2int(std::string str);
        std::string int2str(int nbr);
        void createLivre(std::string _buf, livre *lvr);
        void createRevues(std::string _buf, revues *rev);
        void createCd(std::string _buf, cd *cd);
        void createDvd(std::string _buf, dvd *dvd);
        void createResNumerique(std::string _buf, resNumerique *resNum);
        void createVhs(std::string _buf, vhs *vhs);
        void createPeinture(std::string _buf, peinture *ptr);
        void incrVersion(const char *filename);
        void load(const char *filename);
        void reload();
        void save(const char *filename);
        void clear();
        void effaceMemoire();
        void show(std::string _id); //revoir par rapport a ID ?
        void list();
        void deleteMedia(int _id, std::string _idMedia);  //revoir par rapport a ID ?
        std::string addMedia(int _type);
        void modifMedia(int _id, std::string _idMedia);
        void reset();
        void rechercheGene(std::string _str);
        void rechercheType(std::string _str, int _type);
        void rechercheChamp(std::string _str, int _type);
        int verifIdMedia(std::string idRessource);
        int findLastPosition(std::string _type);
        void saveEndOfFile(std::string filename, std::string str, const char *entete);
        int getDisponible(int idMedia);
        void reservation(std::string str, int idMedia);
        void checkVersion();
};

#endif
