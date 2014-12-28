#include "Sphere.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

Sphere::Sphere(const Vector4d& center, double radius)
	: center(center), radius(radius) {
}

double Sphere::getNearestIntersection(const Vector4d& base, const Vector4d& direction) const {
	Vector4d p(base - center);
	double b = dot(direction, p);
	double c = dot(p, p) - pow(radius, 2);
	double d = pow(b, 2) - c;
	double result;
	if (d >= 0) {
		double t1 = max(-b + sqrt(d), 0.0);
		double t2 = max(-b - sqrt(d), 0.0);
		result = min(t1, t2);
	} else {
		result = 0.0;
	}
	return result;
}

Vector4d Sphere::getNormal(const Vector4d& point) const {
	return normalize(point - center);
}
