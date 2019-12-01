#pragma once
class Point
{
public:
	Point(double x = 0.0, double y = 0.0);
	Point(const Point& p);

	inline double getX() const { return x_; }
	inline double getY() const { return y_; }
	void   setX(double x);
	void   setY(double y);
private:
	double x_;
	double y_;
};

