#include "sprite.h"

Sprite::Sprite(Window *window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr),
	width(0),
	height(0)
{
	image = window->loadImage(this->filename);

	if (!image)
	{
		printf("Spriten '%s' lataaminen epäonnistui", filename);
	} else {
		 int width, height;
		 SDL_QueryTexture(image, NULL, NULL, &width, &height);

		 this->width = width;
		 this->height = height;

		 SDL_Rect rect = {0, 0, width, height};

		 crop(rect);
	}
}

Sprite::~Sprite()
{
	if(image)
	{
		window->freeImage(image);
	}
}

void Sprite::crop(SDL_Rect rect)
{
	clipRect.x = rect.x;
	clipRect.y = rect.y;
	clipRect.w = rect.w;
	clipRect.h = rect.h;
}


void Sprite::render(int x, int y)
{
	window->render(image, x, y, &clipRect);
}

// TODO(jouni): Tämä vois returnaa jotaki järkevää..
void Sprite::create(int w, int h) {
	int width, height;
	SDL_QueryTexture(image, NULL, NULL, &width, &height);

	this->width = width;
	this->height = height;

	SDL_Rect rect = {0, 0, width, height};

	crop(rect);

	int spriteItems = 0;
	int columns = clipRect.w / w;
	int rows = clipRect.h / h;
	
	std::vector<std::vector<SDL_Rect>> spriteSheet;
	//spriteSheet.resize(columns, std::vector<SDL_Rect>(rows, 0));
	
	for (int i = 0; i < rows; i++)
	{
		std::vector<SDL_Rect> row;

		for (int j = 0; j < columns; j++)
		{
			SDL_Rect rect = {i*w, j*h, w, h};
			row.push_back(rect);
		}

		spriteSheet.push_back(row);
	}

	for (std::size_t y = 0; y < spriteSheet.size(); ++y)
	{
		for (std::size_t x = 0; x < spriteSheet[y].size(); ++x)
		{
			crop(spriteSheet[y][x]);
			render(x*w, y*h);
		}
	}
}