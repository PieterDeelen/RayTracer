#ifndef SCENE_H_
#define SCENE_H_

#include "SceneObject.h"
#include "Light.h"
#include "Intersection.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
#include <initializer_list>
#include <boost/optional.hpp>

using boost::optional;
using boost::none;
using std::move;
using std::make_unique;
using std::forward;
using std::unique_ptr;
using std::vector;

class Scene {
public:
	Scene();

	void addObject(unique_ptr<SceneObject> shape);

	template<typename T, typename... Args>
	void add(Args&&... args);

	void addLight(const Light& light);

	const vector<Light>& getLights() const;
	bool isOccluded(const Vector4d& origin, const Vector4d& dest) const;

	optional<Intersection> getNearestIntersection(const Ray& ray) const;

private:
	static constexpr double EPSILON = 1E-3;
	vector<std::unique_ptr<SceneObject>> objects;
	vector<Light> lights;
};

inline Scene::Scene() {}

inline void Scene::addLight(const Light& light) {
	lights.push_back(light);
}

inline void Scene::addObject(std::unique_ptr<SceneObject> object) {
	objects.push_back(std::move(object));
}

template<typename T, typename... Args>
inline void Scene::add(Args&&... args) {
	objects.push_back(move(make_unique<T>(args...)));
}

inline const std::vector<Light>& Scene::getLights() const {
	return lights;
}

inline bool Scene::isOccluded(const Vector4d& origin, const Vector4d& dest) const {
	Vector4d direction = dest - origin;
	Ray ray(origin, direction);
	double distance = length(direction);
	for (auto& object : objects) {
		optional<double> intersection = object->getNearestIntersection(ray);
		if (intersection && EPSILON < *intersection
				&& *intersection < distance) {
			return true;
		}
	}
	return false;
}

inline optional<Intersection> Scene::getNearestIntersection(const Ray& ray) const {
	double nearest = std::numeric_limits<double>::max();
	SceneObject* nearestObject = nullptr;

	for (auto& object : objects) {
		optional<double> intersection = object->getNearestIntersection(ray);
		if (intersection && EPSILON < *intersection  && *intersection < nearest) {
			nearest = *intersection;
			nearestObject = object.get();
		}
	}
	if (nearestObject == nullptr) {
		return none;
	} else {
		return Intersection(ray, nearestObject, nearest);
	}
}

#endif /* SCENE_H_ */
