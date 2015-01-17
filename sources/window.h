#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.h"
#include "Timer.h"
#include "Color.h"

class Window {
	public:
		Window (int width, int height, std::string title="");

		virtual ~Window();
		void destroy();

		//Tuhoaa ohjelman ikkunan ja luo sen uudelleen uusilla ominaisuuksilla (leveys, korkeus, nimi)
		void resize(int width, int height, std::string title="", bool fullscreen);

		int getWidth();
		int getHeight();
		void refresh();

		//Tyhjent‰‰ ikkunan, j‰tt‰en taustav‰rin
		void clear();
		
		bool toggleFullscreen();
		/*
		void setTitle(std::string title);
		int getFramerate();
		*/
		SDL_Texture *loadFromFile(std::string path);
		void freeImage(SDL_Texture* image);
		void freeImage(SDL_Surface* image);
		void renderImage(SDL_Texture *texture, SDL_Rect *source, SDL_Rect *destination);

		//Asettaa frameratelle rajan
		void capFramerate(Uint32 framerate);

		//Palauttaa montako millisekuntia on kulunut edellisest‰ ja nykyisest‰ framesta
		int getDelta();

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;

		bool isFullscreen;

		//Piirt‰‰ tilap‰isgrafiikaksi palikan
		void drawRect(int X, int Y, int W, int H, Color color);

	private:
		//Ikkunan nimi
		std::string title;

		//Frameraten timeri
		// Timer framerateTimer, frameTicks;

		//Framerateen liittyv‰t muuttujat
		int framerateCap, frameCount;
		
		//Deltatime
		int delta;

		//Nykyinen leveys ja korkeus
		int width, height;

		//Alkuper‰inen leveys ja korkeus
		int originalWidth, originalHeight;
};


#endif //__WINDOW_H_DEFINED__