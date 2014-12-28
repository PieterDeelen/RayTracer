#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"
#include "Vector.h"
#include <memory>

class Sphere : public Shape {
public:
	Sphere(const Vector4d& center, double radius);
	virtual double getNearestIntersection(const Ray& ray) const;
	virtual Vector4d getNormal(const Vector4d& point) const;
private:
	Vector4d center;
	double radius;
};

inline std::unique_ptr<Sphere> makeSphere(const Vector4d& center, double radius) {
	return std::make_unique<Sphere>(center, radius);
}

#endif //_SPHERE_H_
