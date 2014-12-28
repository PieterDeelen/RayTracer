#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"
#include "Vector.h"

class Sphere : public Shape {
public:
	Sphere(const Vector4d& center, double radius);
	virtual double getNearestIntersection(const Vector4d& base, const Vector4d& direction) const;
	virtual Vector4d getNormal(const Vector4d& point) const;
private:
	Vector4d center;
	double radius;
};

#endif //_SPHERE_H_
