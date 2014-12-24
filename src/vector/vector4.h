#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "common.h"
#include <ostream>

namespace vector {
	class vector4 {
	public:
		vector4(scalar_t x=0, scalar_t y=0, scalar_t z=0, scalar_t w=0);
		vector4(scalar_t elements[4]);

		vector4(const vector4& v);
		vector4& operator=(const vector4& v);

		inline scalar_t& operator()(int index);
		inline const scalar_t& operator[](int index) const;
	private:
		scalar_t e[4];
	};

	vector4 operator==(const vector4& m, const vector4& n);

	vector4 operator+(const vector4& v, const vector4& w);
	vector4 operator-(const vector4& v, const vector4& w);
	vector4 operator*(const vector4& v, scalar_t d);
	vector4 operator*(scalar_t d, const vector4& v);
	scalar_t dot(const vector4& v, const vector4& w);
	vector4 scale(const vector4& v, scalar_t s);
	vector4 cross(const vector4& v, const vector4& w);
	scalar_t length(const vector4& v);
	vector4 normalize(const vector4& v);

	std::ostream& operator<<(std::ostream& out, const vector4& v);

	//
	// Implementation of accessors.
	//
	scalar_t& vector4::operator()(int index) {
		return e[index];
	}

	const scalar_t& vector4::operator[](int index) const{
		return e[index];
	}
}

#endif // _VECTOR4_H_
