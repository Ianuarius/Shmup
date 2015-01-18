#include "window.h"

Window::Window(int width, int height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	texture(nullptr),
	width(width),
	height(height),
	originalWidth(width),
	originalHeight(height)
{
	// NOTE(juha): Tehdään ikkunasta 3x pelialueen kokoinen.
	resize("Escape From Earth", width*3, height*3);
	clear();
    refresh();
}

Window::~Window()
{
	destroy();
}

void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

void Window::resize(std::string title, int width, int height)
{
	destroy();

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

	// NOTE(juha): Määritellään että skaalataan pikseleitä 3x
	// Tälle voi luultavasti keksiä järkevämmän menetelmän.
	SDL_RenderSetLogicalSize(renderer, width/3, height/3);
}

void Window::clear()
{
	fill(0x000000);
}

void Window::fill(Color color)
{
	SDL_SetRenderDrawColor(renderer,
							color.r(),
							color.g(),
							color.b(),
							color.a());

	SDL_RenderClear(renderer);
}

void Window::refresh()
{
	SDL_RenderPresent(renderer);
}

void Window::loadImage(std::string filename)
{
	SDL_Texture *newTexture = IMG_LoadTexture(renderer, filename.c_str());
	int w, h;
	SDL_QueryTexture(newTexture, nullptr, nullptr, &w, &h);
	texture = newTexture;
}

void Window::renderImage(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = {x, y, 256, 240};
	clip->x = 0;
	clip->y = 0;
	clip->w = 256;
	clip->h = 240;
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

void Window::freeImage(SDL_Texture *image)
{
	if(image)
	{
		SDL_DestroyTexture(image);
	}
}
void Window::freeImage(SDL_Surface *image)
{
	if(image)
	{
		SDL_FreeSurface(image);
	}
}

void Window::drawRect(int X, int Y, int W, int H, Color color) {
	SDL_Rect fillRect = { X, Y, W, H };
	SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), color.a());
	SDL_RenderFillRect(renderer, &fillRect );
}