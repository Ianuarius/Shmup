#include "sprite.h"

// NOTE(jouni): spriteWidth & spriteHeight = yhen spriten koko
Sprite::Sprite(Window *window, std::string filename, int spriteWidth, int spriteHeight):
	window(window),
	filename(filename),
	image(nullptr)
{
	image = window->loadImage(filename);

	if (!image) {
		printf("Kuvan lataaminen epäonnistui. Spriteä ei voitu luoda\n");
	} else {
		// NOTE(jouni): Koko kuvan korkeus ja leveys
		int imageWidth, imageHeight;
		SDL_QueryTexture(image, NULL, NULL, &imageWidth, &imageHeight);

		int spriteItems = 0;
		int columns = imageWidth / spriteWidth;
		int rows = imageHeight / spriteHeight;
	
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				SDL_Rect rect = {j*spriteWidth, i*spriteHeight, spriteWidth, spriteHeight};
				spriteSheet.push_back(rect);
			}
		}
	}
}

Sprite::~Sprite()
{
	if(image)
	{
		window->freeImage(image);
	}
}

// NOTE(jouni): index = mikä spriten "alkio" piirretään
void Sprite::render(int index, int x, int y)
{
	crop(spriteSheet[index]);
	window->render(image, x, y, &clipRect);
}