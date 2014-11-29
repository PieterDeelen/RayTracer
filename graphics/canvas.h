#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <SDL/SDL.h>

namespace graphics {

	typedef unsigned long pixel_t;

	class canvas {
	public:
		canvas(int width, int height);
		~canvas();

		pixel_t* get_buffer();
		void update();

		int get_width();
		int get_height();
	private:
		SDL_Surface* screen;
		int width;
		int height;
	};
}

#endif //_CANVAS_H_
