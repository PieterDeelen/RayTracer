#include "canvas.h"
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

namespace graphics {
	canvas::canvas(int width, int height) : width(width), height(height) {
		if (SDL_Init(SDL_INIT_VIDEO)) {
			// FIXME: dit moet beter kunnen.
			cerr << "Error" << endl;
			exit(1);
		}

		screen = SDL_SetVideoMode(width, height, 32, SDL_DOUBLEBUF);
		if (!screen) {
			cerr << "Couldn't initialize video" << endl;
			exit (1);
		}
	}

	canvas::~canvas() {
		SDL_Quit();
	}

	pixel_t* canvas::get_buffer() {
		if (SDL_MUSTLOCK (screen)) 
			SDL_LockSurface (screen);
		return (pixel_t *) screen -> pixels;
	}

	void canvas::update() {
		if (SDL_MUSTLOCK (screen)) 
			SDL_UnlockSurface (screen);
		SDL_Rect destrect;
		destrect.x = 0;
		destrect.y = 0;
		destrect.w = width;
		destrect.h = height;
		SDL_Flip (screen);
		SDL_FillRect (screen, &destrect, 0);	
	}

	int canvas::get_width() {
		return width;
	}

	int canvas::get_height() {
		return height;
	}
}
