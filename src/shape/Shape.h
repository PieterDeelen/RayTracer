#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector/Vector.h>

namespace shape {
	class Shape {
	public:
		virtual ~Shape() = default;

		virtual double getNearestIntersection(const Vector4d&  base, const Vector4d& direction) = 0;
		virtual Vector4d getNormal(const Vector4d& point) = 0;
	};
}

#endif //_SHAPE_H_
