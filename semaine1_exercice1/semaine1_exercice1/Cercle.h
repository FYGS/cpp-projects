#pragma once

#include "Point.h"

class Cercle
{
public:
	Point getCentre() const;
	double getRayon() const;
	void setRayon(double r);
	void setCentre(double x, double y);
	void setCentre(const Point& p);


	double surface() const;
	bool estInterieur(double x, double y) const;
	bool estInterieur(const Point& p) const;
private:
	double rayon_;
	Point centre_;
};

