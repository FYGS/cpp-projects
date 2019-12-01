#include "Point3D.h"
#include <iostream>

using namespace std;

void Point3D::init(double x, double y, double z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

void Point3D::affiche() const
{
	cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << endl;
}

bool Point3D::compare(const Point3D& autre) const
{
	return (x_ == autre.getX()) and (y_ == autre.getY()) and (z_ == autre.getZ());
}
