#pragma once

class Point3D
{
public:
	void init(double x, double y, double z);
	void affiche() const;
	bool compare(const Point3D& autre) const;

	inline double getX() const;
	inline double getY() const;
	inline double getZ() const;

private:
	double x_;
	double y_;
	double z_;
};


inline double Point3D::getX() const {
	return x_;
}
inline double Point3D::getY() const { return y_; }
inline double Point3D::getZ() const { return z_; }