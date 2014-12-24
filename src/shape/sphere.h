#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "vector/vector4.h"
#include "shape.h"

namespace shape {
	using vector::vector4;
	using vector::scalar_t;

	class sphere : public shape {
	public:
		sphere(vector4 position, scalar_t radius);
		virtual scalar_t intersect(vector4 base, vector4 direction);
		virtual vector4 get_normal(vector4 point);
	private:
		vector4 position;
		scalar_t radius;
	};
}

#endif //_SPHERE_H_
