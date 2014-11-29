#include "sphere.h"
#include "vector4.h"
#include <cmath>
#include <iostream>

namespace shape {
	using namespace vector;
	using namespace std;

	sphere::sphere(vector4 position, scalar_t radius) 
		: position(position), radius(radius) {
	}

	scalar_t sphere::intersect(vector4 base, vector4 direction) {
		vector4 p(base - position);
		scalar_t b = dot(direction, p);
		scalar_t c = dot(p, p) - (radius * radius);

		scalar_t d = (b * b) - c;

		scalar_t result;
		if (d >= 0) {
			scalar_t t1 = (-b + sqrt(d));
			scalar_t t2 = (-b - sqrt(d));

			result = min(max(t1, 0.0), max(t2, 0.0));
		} else {
			result = 0.0;
		}

		return result;
	}

	vector4 sphere::get_normal(vector4 point) {
		return normalize(point - position);
	}
}
