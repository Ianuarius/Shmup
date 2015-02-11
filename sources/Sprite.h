#ifndef __SPRITE_H_INCLUDED__
#define __SPRITE_H_INCLUDED__

#include <vector>
#include "SDL.h"
#include "Color.h"
#include "Window.h"
#include "Texture.h"

class Sprite
{
	public:
		Sprite(Window *window, std::string filename, int width, int height);
		virtual ~Sprite();

		void render(int index, int x, int y);

	private:
		Window *window;
		Texture texture;

		int width;
		int height;

		std::vector<SDL_Rect> spriteSheet;
};

#endif // __SPRITE_H_INCLUDED__