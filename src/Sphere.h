#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "SceneObject.h"
#include "Vector.h"
#include <memory>

class Sphere : public SceneObject {
public:
	Sphere(const Vector4d& center, double radius, const Material& material);
	virtual boost::optional<double> getNearestIntersection(const Ray& ray) const;
	virtual Vector4d getSurfaceNormal(const Vector4d& point) const;
	virtual const Material& getMaterial() const;
private:
	Vector4d center;
	double radius;
	Material material;
};

#endif //_SPHERE_H_
