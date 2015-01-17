#include "window.h"

Window::Window(int width, int height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	originalWidth(width),
	originalHeight(height)
{
	resize("Escape From Earth", width, height);
	clear();
    refresh();
	SDL_Delay(500);
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
	SDL_RenderSetLogicalSize(renderer, width, height);
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

void Window::renderImage(SDL_Texture *texture, SDL_Rect *source, SDL_Rect *destination)
{
	SDL_RenderCopy(renderer, texture, source, destination);
}

SDL_Texture *Window::loadImage(std::string filename)
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, filename.c_str());

	return texture;
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