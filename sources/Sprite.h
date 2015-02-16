#ifndef __SPRITE_H_INCLUDED__
#define __SPRITE_H_INCLUDED__

#include <vector>
#include "SDL.h"
#include "Color.h"
#include "Window.h"
#include "Texture.h"

class Sprite : public Texture
{
	public:
		// Osoitin pelin ikkunaan, spriten kuvatiedoston nimi ja yhden tiedostossa olevan spriten koko.
		Sprite(Window *window, std::string filename, int width, int height);
		virtual ~Sprite();

		// Renderöi spriteSheet-vektorista osan, joka on määrätty 'index'-argumenttiin annetun arvon perusteella.
		void render(int x, int y);
		void setIndex(int i);

	private:
		Window *window;

		int width;
		int height;
		int index;

		// Vektori, johon on tallennettu spritet määrätyn kokoisina palasina.
		std::vector<SDL_Rect> spriteSheet;
};

#endif // __SPRITE_H_INCLUDED__
