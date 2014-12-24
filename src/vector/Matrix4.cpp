#include <vector/Matrix4.h>
#include <vector/Vector4.h>
#include <ostream>
#include <cmath>

namespace vector {
	Matrix4::Matrix4() {
		for (int i = 0; i < 16; i++) {
			e[i] = 0.0;
		}
	}

	Matrix4::Matrix4(scalar_t elements[16]) {
		for (int i = 0; i < 16; i++) {
			e[i] = elements[i];
		}
	}

	Matrix4::Matrix4(scalar_t elements[4][4]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				(*this)(i, j) = elements[i][j];
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const Matrix4& m) {
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
