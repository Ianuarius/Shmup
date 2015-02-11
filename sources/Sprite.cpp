#include "Sprite.h"

// NOTE(jouni): spriteWidth & spriteHeight = yhen spriten koko
Sprite::Sprite(Window *window,
			   std::string filename,
			   int spriteWidth,
			   int spriteHeight):
	texture(window, filename)
{
	int spriteItems = 0;
	int columns = texture.getWidth() / spriteWidth;
	int rows = texture.getHeight() / spriteHeight;
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			SDL_Rect rect = {j*spriteWidth, i*spriteHeight, spriteWidth, spriteHeight};
			spriteSheet.push_back(rect);
		}
	}
}

Sprite::~Sprite()
{
}

// NOTE(jouni): index = mik� spriten "alkio" piirret��n
void Sprite::render(int index, int x, int y)
{
	texture.crop(spriteSheet[index]);
	texture.render(x, y);
}