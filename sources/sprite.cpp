#include "sprite.h"

Sprite::Sprite(Window *window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr),
	width(0),
	height(0)
{
	image = window->loadImage(filename);

	int w, h;
	SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

	width = w;
	height = h;

	//crop();
}

Sprite::~Sprite()
{
	if(image)
	{
		window->freeImage(image);
	}
}
/*
void Sprite::crop(SDL_Rect rect)
{
	clipRect.x = rect.x;
	clipRect.y = rect.y;
	clipRect.w = rect.w;
	clipRect.h = rect.h;
}
*/
void Sprite::render(int x, int y)
{
}