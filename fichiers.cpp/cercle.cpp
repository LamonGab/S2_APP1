#include "cercle.h"

cercle::cercle(int xc, int yc, int rayon_cercle)
{
	ancrage.x=xc;
	ancrage.y=yc;
	rayon=rayon_cercle;
}

cercle::~cercle()
{
}

double cercle::aire()
{
	return rayon*rayon*M_PI;
}

void cercle::afficher(ostream & s)
{
	s << "Cercle(x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon << ", a=" << aire() << ")" << endl;
}

int cercle::getRayon()
{
	return rayon;
}

void cercle::setRayon(int nouveauRayon)
{
	rayon=nouveauRayon;
}
