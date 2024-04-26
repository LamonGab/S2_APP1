/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include <iostream>
#include "vecteur.h"

using namespace std;

class Couche
{
private:
	Forme* *tableauFormes;
	vecteur v;
	int etat;
	//Active=1, Inactive=2, Initialisee=3
public:
	Couche();
	~Couche();
	bool  changerEtat(int etat1);
	bool ajoutForme(Forme *figure);
	Forme *supprimerForme(int index);
	Forme *formeStocke(int index);
	double aireTotale();
	bool translation(int x, int y);
	bool viderCouche();
	void afficher(ostream & s);
	bool estActive();
};

#endif
