#ifndef __TEXTURE_H_INCLUDED__
#define __TEXTURE_H_INCLUDED__

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Window.h"

class Texture
{
	public:
		//Initializes variables
		Texture(Window *window, std::string filename);

		//Deallocates memory
		~Texture();
		
		int getWidth();
		int getHeight();
		void crop(SDL_Rect rect);
		SDL_Texture* loadImage(std::string filename);
		void render(int x, int y);
		void freeImage(SDL_Texture *image);
		void freeImage(SDL_Surface *image);

	private:
		int height;
		int width;
		SDL_Rect clipRect;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
};

#endif // __LTEXTURE_H_INCLUDED__