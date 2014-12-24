#include <vector/Vector4.h>
#include <ostream>
#include <cmath>

namespace vector {
	Vector4::Vector4(scalar_t x, scalar_t y, scalar_t z, scalar_t w) {
		e[0] = x;
		e[1] = y;
		e[2] = z;
		e[3] = w;
	}

	Vector4::Vector4(scalar_t elements[4]) {
		for (int i = 0; i < 4; i++) {
			e[i] = elements[i];
		}
	}

	Vector4::Vector4(const Vector4& v) {
		for (int i = 0; i < 4; i++) {
			e[i] = v.e[i];
		}
	}

	Vector4& Vector4::operator=(const Vector4& v) {
		for (int i = 0; i < 4; i++) {
			e[i] = v.e[i];
		}
		return *this;
	}

	Vector4 operator+(const Vector4& v, const Vector4& w) {
		return Vector4(
			v[0] + w[0], v[1] + w[1], 
			v[2] + w[2], v[3] + w[3]
		      );
	}

	Vector4 operator-(const Vector4& v, const Vector4& w) {
		return Vector4(
			v[0] - w[0], v[1] - w[1], 
			v[2] - w[2], v[3] - w[3]
		      );
	}

	scalar_t dot(const Vector4& v, const Vector4& w) {
		return v[0] * w[0] + v[1] * w[1] + v[2] * w[2] + v[3] * w[3];
	}

	Vector4 scale(const Vector4& v, scalar_t s) {
		return Vector4(v[0] * s, v[1] * s, v[2] * s, v[3] * s);
	}

	scalar_t length(const Vector4& v) {
		return sqrt(dot(v, v));
	}

	Vector4 normalize(const Vector4& v) {
		return scale(v, 1 / length(v));
	}

	Vector4 operator *(const Vector4& v, scalar_t d) {
		return scale(v, d);
	}

	Vector4 operator *(scalar_t d, const Vector4& v) {
		return scale(v, d);
	}

	std::ostream& operator<<(std::ostream& out, const Vector4& v) {
		out << "[" << v[0] << ", " << v[1];
		out << ", " << v[2] << ", " << v[3] << "]";
		return out;
	}
}
