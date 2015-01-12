#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.h"
#include "Timer.h"
#include "Color.h"
#include "Texture.h"

class Window {
	public:
		Window (int width, int height, std::string title="");

		virtual ~Window();

		//Tuhoaa ikkunan ja sen sisällön
		void destroy();

		//Tuhoaa ohjelman ikkunan ja luo sen uudelleen uusilla ominaisuuksilla (leveys, korkeus, nimi)
		void resize(int width, int height, std::string title="");

		//Palauttaa leveyden
		int getWidth();

		//Palauttaa korkeuden
		int getHeight();

		//Päivittää ruudun
		void refresh();

		//Tyhjentää ikkunan, jättäen taustavärin
		void clear();

		//Aktivoi kokoruutu-moodin
		bool toggleFullScreen();

		//Laittaa ikkunalle titlen
		void setTitle(std::string title);

		//Palauttaa frameraten keskimäärän
		int getFramerate();

		//Asettaa frameratelle rajan
		void capFramerate(Uint32 framerate);

		//Palauttaa montako millisekuntia on kulunut edellisestä ja nykyisestä framesta
		int getDelta();

		//SDL:n sisäinen datarakenne joka edustaa ikkunaa
		SDL_Window* window;

		SDL_Renderer* renderer:

		SDL_Surface* surface;

		bool isFullscreen:

		//Piirtää tilapäisgrafiikaksi palikan
		void drawRect(int X, int Y, intW, int H, Color color);

		//Lataa tekstuurin tiedostosta
		Texture *loadTexture(std::string path);

		//Tekstuurin renderöinti
		void render(Texture *sourceTexture, SDL_Rect *destRect, int X, int Y);

	private:
		//Ikkunan nimi
		std::string title;

		//Frameraten timeri
		Timer framerateTimer, frameTicks;

		//Framerateen liittyvät muuttujat
		int framerateCap, frameCount;
		
		//Deltatime
		int delta;

		//Nykyinen leveys ja korkeus
		int width, height;

		//Alkuperäinen leveys ja korkeus
		int originalWidth, originalHeight;
};


#endif //__WINDOW_H_DEFINED__