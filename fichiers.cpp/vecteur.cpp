#include "vecteur.h"

vecteur::vecteur()
{
	taille=0;
	capacite=1;
}

vecteur::~vecteur()
{
	delete [] tableau;
}

bool vecteur::ajoutForme(Forme *figure)
{
	bool retour=true;
	if(taille==capacite)
	{
		capacite=capacite*2;
		Forme* *tableau2=new Forme*[capacite];
		for(int i=0; i<taille; i++)
		{
			tableau2[i]=tableau[i];
		}
		delete [] tableau;
		tableau=tableau2;
	}
	tableau[taille]=figure;
	if(tableau[taille]==NULL)
	{
		retour=false;
	}
	taille++;
	return retour;
}

Forme *vecteur::supprimerForme(int index)
{
	Forme *retour=tableau[index];
	if(index>=taille || index<0)
	{
		retour=nullptr;
	}
	delete tableau[index];
	for(int i=index; i<taille-1; i++)
	{
		tableau[i]=tableau[i+1];
	}
	taille--;
	return retour;
}

Forme *vecteur::formeStocke(int index)
{
	if(index<0 || index>=taille)
	{
		return nullptr;
	}
	return tableau[index];
}

void vecteur::viderVecteur()
{
	int longueur=taille;
	for(int i=0; i<longueur; i++)
	{
		delete tableau[i];
		taille--;
	}
}

bool vecteur::vecteurVide()
{
	bool retour=false;
	if(taille==0)
	{
		retour=true;
	}
	return retour;
}

int vecteur::capaciteVecteur()
{
	return capacite;
}

int vecteur::tailleVecteur()
{
	return taille;
}

void vecteur::afficherVecteur(ostream & s)
{
	for(int i=0; i<taille; i++)
	{
		tableau[i]->afficher(s);
	}
}

Forme* *vecteur::getTableau()
{
	return tableau;
}


