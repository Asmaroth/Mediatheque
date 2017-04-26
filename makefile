#création de l'executable " Test "

all: main.o revues.o livre.o resNumerique.o vhs.o dvd.o cd.o media.o peinture.o ressources.o
		g++ main.o -o Test

main.o: main.cpp revues.hpp livre.hpp resNumerique.hpp vhs.hpp dvd.hpp cd.hpp media.hpp peinture.hpp ressources.hpp
		g++ main.cpp main.o 

revues.o: revues.cpp livre.cpp
		g++ revues.cpp livre.cpp -o revues.o livre.o

livre.o: livre.cpp
		g++ livre.cpp -o livre.o

resNumerique.o: resNumerique.cpp
		g++ resNumerique.cpp -o resNumerique.o

vhs.o: vhs.cpp
		g++ vhs.cpp -o vhs.o

dvd.o: dvd.cpp vhs.cpp
		g++ dvd.cpp -o dvd.o

cd.o: cd.cpp
		g++ cd.cpp -o cd.o

media.o: media.cpp
		g++ media.cpp -o media.o

peinture.o: peinture.cpp
		g++ peinture.cpp -o peinture.o

ressources.o: ressources.cpp
		g++ ressources.cpp -o ressources.o

clean:
		rm -rf *.o

