#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "vector/vector4.h"

namespace shape {
	using vector::vector4;
	using vector::scalar_t;

	class shape {
	public:
		virtual scalar_t intersect(vector4 base, vector4 direction) = 0;
		virtual vector4 get_normal(vector4 point) = 0;
	};
}

#endif //_SHAPE_H_
