#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "Ray.h"
#include "SceneObject.h"
#include "Vector.h"

class Intersection {
public:
	Intersection(const Ray& ray, const SceneObject* object, double t)
		: ray(ray), object(object), t(t) {}

	const SceneObject& getObject() const {
		return *object;
	}

	double getT() const {
		return t;
	}

	Vector4d getPoint() const {
		return ray.getPoint(t);
	}

	bool isHit() {
		return object != nullptr;
	}

private:
	const Ray& ray;
	const SceneObject* object;
	double t;
};




#endif /* INTERSECTION_H_ */
