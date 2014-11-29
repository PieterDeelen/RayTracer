#include "canvas.h"

using namespace graphics;

int main() {
	canvas c(640, 480);

	for (;;) {
		pixel_t* buffer = c.get_buffer();
		for (int i = 0; i < c.get_width(); i++) {
			for (int j = 0; j < c.get_height(); j++) {
				int w = c.get_width();
				buffer[j * w + i] = 0xffffff;
			}
		}
		c.update();
	}
}
