#ifndef CD__HPP
#define CD__HPP


class cd : public media {
    // Attributes
    protected:

        int duree;
        int nbrPiste;
        std::string maisonDisque;
        /// tableau
        std::vector<std::string> titrePiste;
        int note;
    // Operations
    public:

        cd();
        cd(int _duree, int _nbrPiste, std::string _maisonDisque, std::string _titrePiste, int _note,std::string _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~cd();
        void setDuree (int _duree);
        virtual int getDuree ();
        void setNbrPiste (int _nbrPiste);
        virtual int getNbrPiste ();
        void setMaisonDisque (std::string _maisonDisque);
        virtual std::string getMaisonDisque ();
        void setTitrePiste (std::string _titrePiste, int _idPiste);
        void setTitrePiste(std::string _titrePiste);
        virtual std::string getTitrePiste (int _idPiste);
        virtual std::string getTitreAll();
        void setNote (int _note);
        virtual int getNote ();
        void info ();
};

#endif
