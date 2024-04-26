# makefile de graphicus-02

graficus-02: graphicus-02.o tests.o canevas.o couche.o vecteur.o rectangle.o carre.o cercle.o forme.o
	g++ -o graficus-02 graphicus-02.o tests.o canevas.o couche.o vecteur.o rectangle.o carre.o cercle.o forme.o

graphicus-02.o: graphicus-02.cpp tests.h
	g++ graphicus-02.cpp -g -c

tests.o: tests.cpp tests.h canevas.h couche.h vecteur.h rectangle.h carre.h cercle.h forme.h coordonnee.h
	g++ tests.cpp -g -c

canevas.o: canevas.cpp canevas.h couche.h vecteur.h rectangle.h carre.h cercle.h forme.h coordonnee.h
	g++ canevas.cpp -g -c

couche.o: couche.cpp couche.h
	g++ couche.cpp -g -c

vecteur.o: vecteur.cpp vecteur.h rectangle.h carre.h cercle.h forme.h coordonnee.h
	g++ vecteur.cpp -g -c

carre.o: carre.cpp carre.h rectangle.h cercle.h forme.h coordonnee.h
	g++ carre.cpp -g -c

rectangle.o: rectangle.cpp rectangle.h cercle.h forme.h coordonnee.h
	g++ rectangle.cpp -g -c

cercle.o: cercle.cpp cercle.h forme.h coordonnee.h
	g++ cercle.cpp -g -c

forme.o: forme.cpp forme.h coordonnee.h
	g++ forme.cpp -g -c

clean:
	rm -f *.o
