
#include "Scene.h"
#include "SceneObject.h"
#include "Light.h"
#include "Intersection.h"
#include <memory>
#include <boost/optional.hpp>
#include <vector>
#include <limits>

using boost::optional;
using boost::none;
using std::move;
using std::make_unique;
using std::forward;
using std::numeric_limits;
using std::unique_ptr;
using std::vector;

Scene::Scene() {}

void Scene::addLight(const Light& light) {
	lights.push_back(light);
}

void Scene::addObject(unique_ptr<SceneObject> object) {
	objects.push_back(move(object));
}

const vector<Light>& Scene::getLights() const {
	return lights;
}

bool Scene::isOccluded(const Vector4d& origin, const Vector4d& dest) const {
	Vector4d direction(dest - origin);
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

optional<Intersection> Scene::getNearestIntersection(const Ray& ray) const {
	double nearest = numeric_limits<double>::max();
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
		return Intersection(ray, *nearestObject, nearest);
	}
}
