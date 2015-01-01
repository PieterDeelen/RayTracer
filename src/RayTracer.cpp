#include "RayTracer.h"
#include "Vector.h"
#include "Scene.h"
#include "Ray.h"
#include "Intersection.h"
#include "Color.h"
#include <cmath>
#include <boost/optional.hpp>

using boost::optional;
using std::cout;
using std::endl;
using std::max;
using std::pow;

RayTracer::RayTracer(const Scene& scene) : scene(scene) {}

Vector4d mirror(const Vector4d& n, const Vector4d& v) {
	return (2.0 * dot(n, v) * n) - v;
}

Color RayTracer::trace(const Ray& ray) {
	return clamp(trace(ray, 0));
}

Color RayTracer::trace(const Ray& ray, int depth) {
	optional<Intersection> intersection = scene.getNearestIntersection(ray);
	if (intersection) {
		return shade(intersection->getObject(), ray,
				intersection->getPoint(), depth);
	} else {
		return Color(0, 0, 0);
	}
}

Color RayTracer::shade(const SceneObject& object, const Ray& ray, const Vector4d& point, int depth) {
	Color color(0.0, 0.0, 0.);

	Vector4d surfaceNormal = object.getSurfaceNormal(point);
	for (const Light& light : scene.getLights()) {
		Vector4d lightVector = normalize(light.getPosition() - point);
		if (dot(surfaceNormal, lightVector) > 0.0) {
			if (!scene.isOccluded(point, light.getPosition())) {
				Vector4d viewVector = -ray.getDirection();
				const Material& material = object.getMaterial();
				Color diffusePart = diffuse(material, surfaceNormal, lightVector);
				Color specularPart = specular(material, surfaceNormal, lightVector, viewVector);
				color += light.getIntensity() * (diffusePart + specularPart);
			}
		}
	}

	if (depth < 5) {
		double specular = object.getMaterial().getSpecular();
		if (specular > 0.0) {
			Ray reflectionRay(point, mirror(surfaceNormal, -ray.getDirection()));
			Color reflectionColor = trace(reflectionRay, depth + 1);
			color += specular * reflectionColor;
		}
	}

	return color;
}

Color RayTracer::diffuse(const Material& material, const Vector4d& normal, const Vector4d& lightVector) {
	double cosAlpha = max(dot(normal, lightVector), 0.0);
	return material.getColor() * material.getDiffuse() * cosAlpha;
}

Color RayTracer::specular(const Material& material, const Vector4d& normal, const Vector4d& lightVector, const Vector4d& viewVector) {
	Vector4d reflectionVector = mirror(normal, lightVector);
	double cosTheta = max(dot(reflectionVector, viewVector), 0.0);
	double specularPart = material.getSpecular() * pow(cosTheta, material.getReflectivity());
	return Color(specularPart, specularPart, specularPart);
}
