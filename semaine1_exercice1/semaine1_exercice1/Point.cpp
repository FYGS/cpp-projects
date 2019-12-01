#include "Point.h"

Point::Point(double x, double y)
	: x_(x), y_(y) {}
Point::Point(const Point& p)
	: x_(p.x_), y_(p.y_) {}


void   Point::setX(double x) { x_ = x; }
void   Point::setY(double y) { y_ = y; }