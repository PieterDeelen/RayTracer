#include "matrix4.h"
#include "vector4.h"
#include <ostream>
#include <cmath>

namespace vector {
	matrix4::matrix4() {
		for (int i = 0; i < 16; i++) {
			e[i] = 0.0;
		}
	}

	matrix4::matrix4(scalar_t elements[16]) {
		for (int i = 0; i < 16; i++) {
			e[i] = elements[i];
		}
	}

	matrix4::matrix4(scalar_t elements[4][4]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				(*this)(i, j) = elements[i][j];
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const matrix4& m) {
		for (int i = 0; i < 4; i++) {
			out << "[ ";
			for (int j = 0; j < 4; j++) {
				out << m(i,j) << " ";
			}
			out << "]" << std::endl;
		}
		return out;
	}
}
