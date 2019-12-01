#include "Cercle.h"
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

Point Cercle::getCentre() const
{
	return centre_;
}

double Cercle::getRayon() const
{
	return rayon_;
}

void Cercle::setRayon(double r)
{
	if (r < 0.0) r = 0.0;
	rayon_ = r;
}

void Cercle::setCentre(double x, double y)
{
	centre_.setX(x);
	centre_.setY(y);
}

void Cercle::setCentre(const Point& p)
{
	setCentre(p.getX(), p.getY());
	// ou centre_ = p;
}

double Cercle::surface() const
{
	return M_PI * pow(rayon_, 2);
}

bool Cercle::estInterieur(const double x, const double y) const
{
	return ( pow((x - centre_.getX()), 2) + pow((y - centre_.getY()), 2) <= pow(rayon_, 2) );
}

bool Cercle::estInterieur(const Point& p) const
{
	return (pow((p.getX() - centre_.getX()), 2) + pow((p.getY() - centre_.getY()), 2) <= pow(rayon_, 2));
}
