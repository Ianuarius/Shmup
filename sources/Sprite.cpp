#include "Sprite.h"

// NOTE(jouni): spriteWidth & spriteHeight = yhen spriten koko
Sprite::Sprite(Window *window,
			   std::string filename,
			   int spriteWidth,
			   int spriteHeight):
	Texture(window, filename),
	index(0)
{
	try {
		int spriteItems = 0;
		int columns = getWidth() / spriteWidth;
		int rows = getHeight() / spriteHeight;
	
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				SDL_Rect rect = {j*spriteWidth, i*spriteHeight, spriteWidth, spriteHeight};
				spriteSheet.push_back(rect);
			}
		}
	} catch(...) {
		printf("Error creating sprite");
		return;
	}

}

Sprite::~Sprite()
{
}

void Sprite::setIndex(int i) {
	if (i < 0) {
		index = 0;
	} else {
		index = i;
	}
}

// NOTE(jouni): index = mikä spriten "alkio" piirretään
void Sprite::render(int x, int y)
{
	crop(spriteSheet[index]);
	Texture::render(x, y);
}