#include "sdl.h"

bool SDL::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf ("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	if (TTF_Init() == -1)
	{
		printf("SDL TTF could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

void SDL::exit()
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}