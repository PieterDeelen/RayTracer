#include "Sphere.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

using std::pow;
using std::max;
using std::min;
using std::sqrt;
using boost::none;
using boost::optional;

Sphere::Sphere(const Vector4d& center, double radius, const Material& material)
	: center(center), radius(radius), material(material) {
}

optional<double> Sphere::getNearestIntersection(const Ray& ray) const {
	Vector4d p(ray.getOrigin() - center);
	double b = dot(ray.getDirection(), p);
	double c = dot(p, p) - pow(radius, 2);
	double d = pow(b, 2) - c;
	if (d >= 0) {
		double sqrtD = sqrt(d);
		double t1 = max(-b + sqrtD, 0.0);
		double t2 = max(-b - sqrtD, 0.0);
		return min(t1, t2);
	} else {
		return none;
	}
}

Vector4d Sphere::getSurfaceNormal(const Vector4d& point) const {
	return normalize(point - center);
}

const Material& Sphere::getMaterial() const {
	return material;
}
