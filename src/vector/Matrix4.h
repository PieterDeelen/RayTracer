#ifndef _MATRIX4_H_
#define _MATRIX4_H_

#include "common.h"
#include <ostream>

namespace vector {
	class Matrix4 {
	public:
		Matrix4();
		Matrix4(scalar_t elements[16]);
		Matrix4(scalar_t elements[4][4]);

		Matrix4(const Matrix4& v);
		Matrix4& operator=(const Matrix4& v);

		inline scalar_t& operator()(int row, int col);
		inline const scalar_t& operator()(int row, int col) const;
	private:
		scalar_t e[16];
	};

	Matrix4 operator==(const Matrix4& m, const Matrix4& n);

	Matrix4 operator+(const Matrix4& m, const Matrix4& n);
	Matrix4 operator-(const Matrix4& m, const Matrix4& n);
	Matrix4 operator*(const Matrix4& m, const Matrix4& n);

	std::ostream& operator<<(std::ostream& out, const Matrix4& m);

	//
	// Implementation of accessors.
	//
	scalar_t& Matrix4::operator()(int row, int col) {
		return e[row * 4 + col];
	}

	const scalar_t& Matrix4::operator()(int row, int col) const{
		return e[row * 4 + col];
	}
}

#endif // _MATRIX4_H_
