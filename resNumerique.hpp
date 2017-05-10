#ifndef RESNUMERIQUE__HPP
#define RESNUMERIQUE__HPP



class resNumerique : public media {
    // Attributes
    protected:
        std::string format;
        int taille;
        std::string path;
    // Operations
    public:
        resNumerique();
        resNumerique( std::string _format, int _taille, std::string path,int _id, std::string _titre, std::string _auteur, int _annee, int _disponible, int _dureeEmprunt, int _dateEmprunt);
        ~resNumerique();
        virtual void setFormat (std::string _format);
        virtual std::string getFormat ();
        virtual void setTaille (int _taille);
        virtual int getTaille ();
        virtual void setPath (std::string _path);
        virtual std::string getPath ();
        virtual void info ();
        virtual std::string infoToSave();
};

#endif
