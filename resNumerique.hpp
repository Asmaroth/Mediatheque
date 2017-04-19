#ifndef RESNUMERIQUE__HPP
#define RESNUMERIQUE__HPP

#include "mediat.hpp"

class resNumerique : public mediat {
    // Attributes
    protected :
        string format;
        int taille;
        string path;
    // Operations
    public :
        void setFormat (string _format);
        string getFormat ();
        void setTaille (int _taille);
        int getTaille ();
        void setPath (string _path);
        string getPath ();
        void info ();
};

#endif
