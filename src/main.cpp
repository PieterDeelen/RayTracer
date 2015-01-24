#include "Sphere.h"
#include "Vector.h"
#include "Scene.h"
#include "Ray.h"
#include "Color.h"
#include "RayTracer.h"
#include <png++/png.hpp>
#include <iostream>
#include <ctime>
#include <cmath>

using png::image;
using png::rgb_pixel;
using std::clock;
using std::cout;
using std::endl;

Scene createScene() {
	Scene scene;
	Material material(Color(0, 0, 1), 0.5, 0.75, 0.5, 20);

	for (int i = 0; i < 10; i++) {
		double z = i * 10.0 + 5.0;
		scene.add<Sphere>(Vector4d( 2.5, -2.5, z, 1), 1.5, material);
		scene.add<Sphere>(Vector4d(-2.5, -2.5, z, 1), 1.5, material);
		scene.add<Sphere>(Vector4d( 2.5,  2.5, z, 1), 1.5, material);
		scene.add<Sphere>(Vector4d(-2.5,  2.5, z, 1), 1.5, material);
	}

	scene.addLight({{0.0, -10.0, -20.0, 1}, 1.0});

	return scene;
}

int main() {
	const int width = 1200;
	const int height = 1200;

	Scene scene = createScene();
	RayTracer rayTracer(scene);

	long begin = clock();
	image<rgb_pixel> image(width, height);
	for (size_t y = 0; y < image.get_height(); ++y) {
		for (size_t x = 0; x < image.get_width(); ++x) {
			double dx = (x / (width/2.0)) - 1.0;
			double dy = (y / (height/2.0)) - 1.0;
			const Ray ray({0.0, 0.0, 0.0, 1.0}, {dx, dy, 1.0, 0.0});
			Color color = rayTracer.trace(ray);
			rgb_pixel rgbPixel = rgb_pixel(color.getRed() * 0xff,
					color.getGreen() * 0xff, color.getBlue() * 0xff);
			image.set_pixel(x, y, rgbPixel);
		}
	}
	long end = clock();

	cout << (end - begin) / (double)CLOCKS_PER_SEC << endl;

	image.write("output.png");
}
