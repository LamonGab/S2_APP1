#include "carre.h"

carre::carre(int xs, int ys, int cote_carre)
{
	ancrage.x=xs;
	ancrage.y=ys;
	cote=cote_carre;
}

carre::~carre()
{
}

double carre::aire()
{
	return cote*cote;
}

void carre::afficher(ostream& s)
{
	s << "Carre(x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << cote << ", a=" << aire() << ")" << endl;
}

int carre::getCote()
{
	return cote;
}

void carre::setCote(int nouveauCote)
{
	cote=nouveauCote;
}
