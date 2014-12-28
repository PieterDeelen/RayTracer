#include "shape/Sphere.h"
#include "vector/Vector.h"
#include <png++/png.hpp>
#include <iostream>
#include <ctime>

int main() {
	const int width = 1200;
	const int height = 1200;

	const Sphere sphere({0, 0, 0, 1}, 1);
	const Vector4d origin(0, 0, 2.0, 1);

	long begin = std::clock();
	png::image<png::rgb_pixel> image(width, height);
	for (size_t y = 0; y < image.get_height(); ++y) {
		for (size_t x = 0; x < image.get_width(); ++x) {
			double dx = (x / (width/2.0)) - 1.0;
			double dy = (y / (height/2.0)) - 1.0;
			const Vector4d direction = normalize(Vector4d(dx, dy, -1.0, 0.0));

			if (sphere.getNearestIntersection(origin, direction) > 0.0) {
				image.set_pixel(x, y, png::rgb_pixel(0xff, 0xff, 0xff));
			} else {
				image.set_pixel(x, y, png::rgb_pixel(0x00, 0x00, 0x00));
			}

		}
	}
	long end = std::clock();

	std::cout << (end - begin) / (double)CLOCKS_PER_SEC << std::endl;

	image.write("output.png");
}
