/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{
	etat=1;
}

Couche::~Couche()
{
}

bool Couche::changerEtat(int etat1)
{
	bool retour=false;
	if(etat!=etat1)
	{
		etat=etat1;
		retour=true;
	}
	return retour;
}

bool Couche::ajoutForme(Forme *figure)
{
	if(etat!=1)
	{
		return false;
	}
	return v.ajoutForme(figure);
}

Forme *Couche::supprimerForme(int index)
{
	if(etat!=1)
	{
		return NULL;
	}
	return v.supprimerForme(index);
}

Forme *Couche::formeStocke(int index)
{
	return v.formeStocke(index);
}

double Couche::aireTotale()
{
	double aire=0;
	int taille=v.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		aire+=v.getTableau()[i]->aire();
	}
	return aire;
}

bool Couche::translation(int x, int y)
{
	bool retour=true;
	if(etat!=1)
	{
		retour=false;
	}
	int taille=v.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		v.getTableau()[i]->translater(x, y);
	}
	return retour;
}

bool Couche::viderCouche()
{
	bool retour=true;
	v.viderVecteur();
	if(aireTotale()!=0)
	{
		retour=false;
	}
	return retour;
}

void Couche::afficher(ostream & s)
{
	int taille=v.tailleVecteur();
	for(int i=0; i<taille; i++)
	{
		v.getTableau()[i]->afficher(s);
	}
}

bool Couche::estActive()
{
	bool retour=false;
	if(etat==1)
	{
		retour=true;
	}
	return retour;
}

