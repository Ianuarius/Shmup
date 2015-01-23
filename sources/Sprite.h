#ifndef __SPRITE_H_INCLUDED__
#define __SPRITE_H_INCLUDED__

#include <vector>
#include "sdl.h"
#include "color.h"
#include "window.h"

/*
TODO(jouni): Tämä luokka ettii vielä perimmäistä tarkoitustaan
*/

class Sprite
{
public:
	Sprite(Window *window, std::string filename, int width, int height);
	virtual ~Sprite();

	void crop(SDL_Rect rect);
	virtual void render(int index, int x, int y);

protected:
	Window *window;
	std::string filename;
	SDL_Texture *image;
	SDL_Rect clipRect;
	std::vector<SDL_Rect> spriteSheet;
};

#endif // __SPRITE_H_INCLUDED__
