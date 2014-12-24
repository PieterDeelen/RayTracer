#include "Sphere.h"
#include <algorithm>
#include <cmath>

namespace shape {
	Sphere::Sphere(const Vector4d& position, double radius)
		: position(position), radius(radius) {
	}

	double Sphere::getNearestIntersection(const Vector4d& base, const Vector4d& direction) {
		using std::min;
		using std::max;

		Vector4d p(base - position);
		double b = dot(direction, p);
		double c = dot(p, p) - (radius * radius);

		double d = (b * b) - c;

		double result;
		if (d >= 0) {
			double t1 = (-b + sqrt(d));
			double t2 = (-b - sqrt(d));

			result = min(max(t1, 0.0), max(t2, 0.0));
		} else {
			result = 0.0;
		}

		return result;
	}

	Vector4d Sphere::getNormal(const Vector4d& point) {
		return normalize(point - position);
	}
}
