#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "Shape.h"
#include "Material.h"
#include <memory>

class SceneObject {
public:
	SceneObject(std::unique_ptr<Shape> shape, const Material& material);
	SceneObject(SceneObject&& other);

	const Material& getMaterial() const;
	const Shape& getShape() const;

	double getNearestIntersection(const Ray& ray) const;

private:
	std::unique_ptr<Shape> shape;
	Material material;
};

inline SceneObject::SceneObject(std::unique_ptr<Shape> shape,
		const Material& material) : shape(std::move(shape)), material(material)
{}

inline const Material& SceneObject::getMaterial() const {
	return material;
}

inline const Shape& SceneObject::getShape() const {
	return *shape;
}

inline SceneObject::SceneObject(SceneObject&& other)
	: shape(std::move(other.shape)), material(other.material)
{}

inline double SceneObject::getNearestIntersection(const Ray& ray) const {
	return shape->getNearestIntersection(ray);
}

#endif /* SCENEOBJECT_H_ */
