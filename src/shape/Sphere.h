#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"
#include <vector/Vector.h>

namespace shape {
	class Sphere : public Shape {
	public:
		Sphere(const Vector4d& position, double radius);
		virtual double getNearestIntersection(const Vector4d& base, const Vector4d& direction);
		virtual Vector4d getNormal(const Vector4d& point);
	private:
		Vector4d position;
		double radius;
	};
}

#endif //_SPHERE_H_
