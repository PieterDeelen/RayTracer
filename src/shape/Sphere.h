#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <shape/Shape.h>
#include <vector/Vector4.h>

namespace shape {
	using vector::Vector4;
	using vector::scalar_t;

	class Sphere : public Shape {
	public:
		Sphere(Vector4 position, scalar_t radius);
		virtual scalar_t intersect(Vector4 base, Vector4 direction);
		virtual Vector4 get_normal(Vector4 point);
	private:
		Vector4 position;
		scalar_t radius;
	};
}

#endif //_SPHERE_H_
