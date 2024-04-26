/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
	couches[0].changerEtat(1);
	for(int i=1; i<MAX_COUCHES; i++)
	{
		couches[i].changerEtat(0);
	}
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	couches[0].changerEtat(0);
	couches[0].viderCouche();
	for(int i=1; i<MAX_COUCHES; i++)
	{
		couches[i].changerEtat(0);
		couches[i].viderCouche();
		if(couches[i].estActive())
		{
			return false;
		}
	}
	return true;
}

bool Canevas::activerCouche(int index)
{
	bool retour=true;
	if(index<0 || index>=MAX_COUCHES)
	{
		retour=false;
	}
	for(int i=0; i<MAX_COUCHES; i++)
	{
		if(couches[i].estActive())
		{
			couches[i].changerEtat(2);
		}
	}
	coucheActive=index;
	couches[index].changerEtat(1);
	return retour;
}

bool Canevas::cacherCouche(int index)
{
	bool retour=true;
	if(index<0 || index>=MAX_COUCHES)
	{
		retour=false;
	}
	couches[index].changerEtat(2);
	return retour;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	couches[coucheActive].ajoutForme(p_forme);
	return true;
}

bool Canevas::retirerForme(int index)
{
	couches[coucheActive].supprimerForme(index);
	return true;
}

double Canevas::aire()
{
	double aire=0;
	for(int i=0; i<MAX_COUCHES; i++)
	{
		aire=aire+couches[i].aireTotale();
	}
	return aire;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	couches[coucheActive].translation(deltaX, deltaY);
	return true;
}

void Canevas::afficher(ostream & s)
{
	for(int i=0; i<MAX_COUCHES; i++)
	{
		if(couches[i].aireTotale()==0)
		{
			s << "----- Couche " << i << endl << "Couche initialisee" << endl;
		}
		else
		{
			s << "----- Couche " << i << endl;
			couches[i].afficher(s);
		}
	}
}

