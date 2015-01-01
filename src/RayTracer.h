/*
 * RayTracer.h
 *
 *  Created on: Dec 30, 2014
 *      Author: pieter
 */

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "Scene.h"

class RayTracer {
public:
	RayTracer(const Scene& scene);

	Color trace(const Ray& ray);

private:
	const Scene& scene;

	Color trace(const Ray& ray, int depth);
	Color shade(const SceneObject& object, const Ray& ray, const Vector4d& point, int depth);
	Color diffuse(const Material& material, const Vector4d& normal, const Vector4d& lightVector);
	Color specular(const Material& material, const Vector4d& normal, const Vector4d& lightVector, const Vector4d& viewVector);
};

#endif /* RAYTRACER_H_ */
