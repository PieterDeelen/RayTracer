#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "Ray.h"
#include "SceneObject.h"
#include "Vector.h"

class Intersection {
public:
	Intersection(const Ray& ray, const SceneObject& object, double t);

	const SceneObject& getObject() const;
	Vector4d getPoint() const;

	bool operator<(const Intersection& other);

private:
	const Ray& ray;
	const SceneObject& object;
	const double t;
};

inline Intersection::Intersection(const Ray& ray, const SceneObject& object, double t)
	: ray(ray), object(object), t(t) {}

inline const SceneObject& Intersection::getObject() const {
	return object;
}

inline Vector4d Intersection::getPoint() const {
	return ray.getPoint(t);
}

inline bool Intersection::operator<(const Intersection& other) {
	return t < other.t;
}

#endif /* INTERSECTION_H_ */
