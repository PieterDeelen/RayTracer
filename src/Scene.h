#ifndef SCENE_H_
#define SCENE_H_

#include "SceneObject.h"
#include "Light.h"
#include "Intersection.h"
#include <memory>
#include <boost/optional.hpp>
#include <vector>

class Scene {
public:
	Scene();

	void addObject(std::unique_ptr<SceneObject> shape);

	template<typename T, typename... Args>
	void add(Args&&... args);


	void addLight(const Light& light);

	const std::vector<Light>& getLights() const;
	bool isOccluded(const Vector4d& origin, const Vector4d& dest) const;

	boost::optional<Intersection> getNearestIntersection(const Ray& ray) const;

private:
	static constexpr double EPSILON = 1E-3;
	std::vector<std::unique_ptr<SceneObject>> objects;
	std::vector<Light> lights;
};

template<typename T, typename... Args>
inline void Scene::add(Args&&... args) {
	objects.push_back(std::move(std::make_unique<T>(args...)));
}

#endif /* SCENE_H_ */
