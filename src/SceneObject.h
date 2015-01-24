#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "Material.h"
#include "Ray.h"
#include <boost/optional.hpp>

class SceneObject {
public:
	virtual ~SceneObject() = default;

	virtual boost::optional<double> getNearestIntersection(const Ray& ray) const = 0;
	virtual Vector4d getSurfaceNormal(const Vector4d& point) const = 0;
	virtual const Material& getMaterial() const = 0;
};

#endif /* SCENEOBJECT_H_ */
