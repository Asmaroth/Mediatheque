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
        virtual void setDuree (int _duree);
        virtual int getDuree ();
        virtual void setNbrPiste (int _nbrPiste);
        virtual int getNbrPiste ();
        virtual void setMaisonDisque (std::string _maisonDisque);
        virtual std::string getMaisonDisque ();
        virtual void setTitrePiste (std::string _titrePiste, int _idPiste);
        virtual void setTitrePiste(std::string _titrePiste);
        virtual std::string getTitrePiste (int _idPiste);
        virtual std::string getTitreAll();
        virtual void setNote (int _note);
        virtual int getNote ();
        void info ();
        virtual std::string infoToSave();
};

#endif
