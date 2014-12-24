#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector/Vector4.h>

namespace shape {
	using vector::Vector4;
	using vector::scalar_t;

	class Shape {
	public:
		virtual scalar_t intersect(Vector4 base, Vector4 direction) = 0;
		virtual Vector4 get_normal(Vector4 point) = 0;
	};
}

#endif //_SHAPE_H_
