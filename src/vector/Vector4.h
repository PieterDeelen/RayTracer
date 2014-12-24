#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "common.h"
#include <ostream>

namespace vector {

	class Vector4 {
	public:
		Vector4(scalar_t x=0, scalar_t y=0, scalar_t z=0, scalar_t w=0);
		Vector4(scalar_t elements[4]);

		Vector4(const Vector4& v);
		Vector4& operator=(const Vector4& v);

		inline scalar_t& operator()(int index);
		inline const scalar_t& operator[](int index) const;
	private:
		scalar_t e[4];
	};

	Vector4 operator==(const Vector4& m, const Vector4& n);

	Vector4 operator+(const Vector4& v, const Vector4& w);
	Vector4 operator-(const Vector4& v, const Vector4& w);
	Vector4 operator*(const Vector4& v, scalar_t d);
	Vector4 operator*(scalar_t d, const Vector4& v);
	scalar_t dot(const Vector4& v, const Vector4& w);
	Vector4 scale(const Vector4& v, scalar_t s);
	Vector4 cross(const Vector4& v, const Vector4& w);
	scalar_t length(const Vector4& v);
	Vector4 normalize(const Vector4& v);

	std::ostream& operator<<(std::ostream& out, const Vector4& v);

	//
	// Implementation of accessors.
	//
	scalar_t& Vector4::operator()(int index) {
		return e[index];
	}

	const scalar_t& Vector4::operator[](int index) const{
		return e[index];
	}
}

#endif // _VECTOR4_H_
