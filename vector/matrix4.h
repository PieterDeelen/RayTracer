#ifndef _MATRIX4_H_
#define _MATRIX4_H_

#include "common.h"
#include <ostream>

namespace vector {
	class matrix4 {
	public:
		matrix4();
		matrix4(scalar_t elements[16]);
		matrix4(scalar_t elements[4][4]);

		matrix4(const matrix4& v);
		matrix4& operator=(const matrix4& v);

		inline scalar_t& operator()(int row, int col);
		inline const scalar_t& operator()(int row, int col) const;
	private:
		scalar_t e[16];
	};

	matrix4 operator==(const matrix4& m, const matrix4& n);

	matrix4 operator+(const matrix4& m, const matrix4& n);
	matrix4 operator-(const matrix4& m, const matrix4& n);
	matrix4 operator*(const matrix4& m, const matrix4& n);

	std::ostream& operator<<(std::ostream& out, const matrix4& m);

	//
	// Implementation of accessors.
	//
	scalar_t& matrix4::operator()(int row, int col) {
		return e[row * 4 + col];
	}

	const scalar_t& matrix4::operator()(int row, int col) const{
		return e[row * 4 + col];
	}
}

#endif // _MATRIX4_H_
