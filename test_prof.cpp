#include<vector>
#include<string>
#include<iostream>

class Media {
    public:
		int id;
		std::string auteur;
        Media(){id = 0; auteur="";}
        virtual ~Media(){}
        virtual void print(){std::cout<<id<<std::endl;std::cout<<auteur<<std::endl;}
};

class Livre : public Media {
	public :
        int pages;

        Livre(){id = 0, auteur="Paul"; pages=2;};
        ~Livre(){}
        void print(){Media::print(); std::cout<<pages<<std::endl;}
};

class CD : public Media {
	public :
        int duree;

        CD(){id = 1, auteur="Pierre"; duree=60;};
    	~CD(){}
        void print(){Media::print(); std::cout<<duree<<std::endl;}
};



int main(int argc, char const *argv[])
{
	
	std::vector<Media *> liste;

	Media * cd  = new CD;
	Media * livre = new Livre;

	liste.push_back(cd);
	liste.push_back(livre);

	liste[0]->print();
	liste[1]->print();

	delete cd;
	delete livre;

	return 0;
}