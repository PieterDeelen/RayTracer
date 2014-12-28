#ifndef RAY_H_
#define RAY_H_

#include "Vector.h"

class Ray {
public:
	Ray(const Vector4d& origin, const Vector4d& direction);

	const Vector4d& getOrigin() const;
	const Vector4d& getDirection() const;

	Vector4d getPoint(double t) const;

private:
	Vector4d origin;
	Vector4d direction;
};

inline Ray::Ray(const Vector4d& origin, const Vector4d& direction)
	: origin(origin), direction(normalize(direction)) {}

inline const Vector4d& Ray::getOrigin() const {
	return origin;
}

inline const Vector4d& Ray::getDirection() const {
	return direction;
}

inline Vector4d Ray::getPoint(double t) const {
	return origin + t * direction;
}

#endif /* RAY_H_ */
