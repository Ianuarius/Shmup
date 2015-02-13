#ifndef __TEXTURE_H_INCLUDED__
#define __TEXTURE_H_INCLUDED__

#include <string>
#include "SDL.h"
#include "Window.h"

class Texture
{
	public:
		Texture(Window *window, std::string filename);
		~Texture();
		
		// Getterit
		int getWidth();
		int getHeight();
		
		// Croppaa kuvasta rectin kokoisen alueen.
		void crop(SDL_Rect rect);
		
		// Renderöi tekstuurin kohtaan x, y.
		void render(int x, int y);

		// Vapauttaa SDL-tyypit muistista.
		void free();


	private:
		// Lataa kuvatiedoston SDL_Texture -pointteriin.
		SDL_Texture *loadImage(std::string filename);
		
		int height;
		int width;

		SDL_Rect clipRect;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
};

#endif // __LTEXTURE_H_INCLUDED__
