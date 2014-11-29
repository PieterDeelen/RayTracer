#include "vector4.h"
#include <ostream>
#include <cmath>

namespace vector {
	vector4::vector4(scalar_t x, scalar_t y, scalar_t z, scalar_t w) {
		e[0] = x;
		e[1] = y;
		e[2] = z;
		e[3] = w;
	}

	vector4::vector4(scalar_t elements[4]) {
		for (int i = 0; i < 4; i++) {
			e[i] = elements[i];
		}
	}

	vector4::vector4(const vector4& v) {
		for (int i = 0; i < 4; i++) {
			e[i] = v.e[i];
		}
	}

	vector4& vector4::operator=(const vector4& v) {
		// Check for self-assignment. Probably not necessary.
		if (&v != this) {
			for (int i = 0; i < 4; i++) {
				e[i] = v.e[i];
			}
		}
		return *this;
	}

	vector4 operator+(const vector4& v, const vector4& w) {
		return vector4(
			v[0] + w[0], v[1] + w[1], 
			v[2] + w[2], v[3] + w[3]
		      );
	}

	vector4 operator-(const vector4& v, const vector4& w) {
		return vector4(
			v[0] - w[0], v[1] - w[1], 
			v[2] - w[2], v[3] - w[3]
		      );
	}

	scalar_t dot(const vector4& v, const vector4& w) {
		return v[0] * w[0] + v[1] * w[1] + v[2] * w[2] + v[3] * w[3];
	}

	vector4 scale(const vector4& v, scalar_t s) {
		return vector4(v[0] * s, v[1] * s, v[2] * s, v[3] * s);
	}

	vector4 cross(const vector4& v, const vector4& w);

	scalar_t length(const vector4& v) {
		return sqrt(dot(v, v));
	}

	vector4 normalize(const vector4& v) {
		return scale(v, 1 / length(v));
	}

	std::ostream& operator<<(std::ostream& out, const vector4& v) {
		out << "[" << v[0] << ", " << v[1];
		out << ", " << v[2] << ", " << v[3] << "]";
		return out;
	}
}
