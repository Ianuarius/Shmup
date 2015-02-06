#ifndef __SPRITE_H_INCLUDED__
#define __SPRITE_H_INCLUDED__

#include <vector>
#include "sdl.h"
#include "color.h"
#include "window.h"

class Sprite
{
	public:
		Sprite(Window *window, std::string filename, int width, int height);
		virtual ~Sprite();

		void crop(SDL_Rect rect);
		virtual void render(int index, int x, int y);

		SDL_Rect clipRect;

	private:
		Window *window;
		std::string filename;

		SDL_Texture *image;

		std::vector<SDL_Rect> spriteSheet;
};

#endif // __SPRITE_H_INCLUDED__
