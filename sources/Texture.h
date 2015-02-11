#ifndef __TEXTURE_H_INCLUDED__
#define __TEXTURE_H_INCLUDED__

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Texture
{
	public:
		//Initializes variables
		Texture(Window *window, std::string filename, int width, int height);

		//Deallocates memory
		~Texture();
		
		int getWidth();
		int getHeight();
		void crop(SDL_Rect rect);
		void crop(int index);
		virtual void render(int x, int y);
};

#endif // __LTEXTURE_H_INCLUDED__