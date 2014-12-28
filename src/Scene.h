#ifndef SCENE_H_
#define SCENE_H_

#include "SceneObject.h"
#include "Light.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
#include <initializer_list>

class Scene {
public:
	Scene();

	void addObject(SceneObject&& object);
	void addObject(std::unique_ptr<Shape> shape, const Material& material);
	void addLight(const Light& light);

	double getNearestIntersection(const Ray& ray);

private:
	std::vector<SceneObject> objects;
	std::vector<Light> lights;
};

inline Scene::Scene() {}

inline void Scene::addLight(const Light& light) {
	lights.push_back(light);
}

inline void Scene::addObject(std::unique_ptr<Shape> shape,
		const Material& material) {
	objects.emplace_back(std::move(shape), material);
}

inline void Scene::addObject(SceneObject&& object) {
	objects.push_back(std::move(object));
}

inline double Scene::getNearestIntersection(const Ray& ray) {
	double nearest = std::numeric_limits<double>::max();
	for (const SceneObject& object : objects) {
		nearest = std::min(nearest, object.getNearestIntersection(ray));
	}
	return nearest;
}

#endif /* SCENE_H_ */
