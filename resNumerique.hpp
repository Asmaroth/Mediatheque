#ifndef RESNUMERIQUE__HPP
#define RESNUMERIQUE__HPP

#include "mediat.hpp"

class resNumerique : public mediat {
    // Attributes
    protected:
        std::string format;
        int taille;
        std::string path;
    // Operations
    public:
        resNumerique();
        resNumerique( std::string _format, int _taille, std::string path);
        ~resNumerique();
        void setFormat (std::string _format);
        std::string getFormat ();
        void setTaille (int _taille);
        int getTaille ();
        void setPath (std::string _path);
        std::string getPath ();
        virtual void info ();
};

#endif
