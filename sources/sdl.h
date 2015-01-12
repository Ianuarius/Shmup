#ifndef __SDL_H_INCLUDED__
#define __SDL_H_INCLUDED__

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// High level wrapper for SDL2 calls

namespace SDL
{
	// Initializes SDL2, must be called before everything else
	bool init();

	// Destroys SDL2, must be called when program closes
	void exit();
};

#endif // __SDL_H_INCLUDED__