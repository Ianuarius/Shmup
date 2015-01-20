#ifndef __SPRITE_H_INCLUDED__
#define __SPRITE_H_INCLUDED__

#include "sdl.h"
#include "color.h"
#include "window.h"

class Sprite
{
public:
	Sprite(Window *window, std::string filename);
	virtual ~Sprite();

	void crop(SDL_Rect rect);

	virtual void render(int x, int y);

protected:
	Window *window;
	std::string filename;
	SDL_Texture *image;
	SDL_Rect clipRect;

	int width;
	int height;
};

#endif // __SPRITE_H_INCLUDED__
