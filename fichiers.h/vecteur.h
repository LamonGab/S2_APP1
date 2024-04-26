#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include "forme.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"

using namespace std;

class vecteur
{
private:
	int taille;
	int capacite;
	Forme* *tableau=new Forme*[capacite];
public:
	vecteur();
	~vecteur();
	void afficherVecteur(ostream & s);
	bool ajoutForme(Forme *figure);
	Forme *supprimerForme(int index);
	Forme *formeStocke(int index);
	void viderVecteur();
	bool vecteurVide();
	int capaciteVecteur();
	int tailleVecteur();
	Forme* *getTableau();
};

#endif
