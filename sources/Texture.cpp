#include "Texture.h"

Texture::Texture()
{
	//Initialize
	/*mTexture = NULL;
	mWidth = 0;
	mHeight = 0;*/
}

Texture::~Texture()
{
	//Deallocate
	//free();
}

void Sprite::crop(SDL_Rect rect)
{
	clipRect.x = rect.x;
	clipRect.y = rect.y;
	clipRect.w = rect.w;
	clipRect.h = rect.h;
}

void Sprite::crop(int index)
{
	crop(spriteSheet[index]);
}

int Texture::getWidth()
{
	return width();
}

int Texture::getHeight()
{
	return height;
}

void Texture::render(int x, int y)
{
	crop(spriteSheet[index]);
	window->render(image, x, y, &clipRect);
}