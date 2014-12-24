#include <shape/Sphere.h>
#include <vector/common.h>
#include <cmath>

namespace shape {
	using namespace vector;
	using namespace std;

	Sphere::Sphere(Vector4 position, scalar_t radius) 
		: position(position), radius(radius) {
	}

	scalar_t Sphere::intersect(Vector4 base, Vector4 direction) {
		Vector4 p(base - position);
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

	Vector4 Sphere::get_normal(Vector4 point) {
		return normalize(point - position);
	}
}
