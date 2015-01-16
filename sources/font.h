/**
 * Font.h
 * 
 * Fonttien lataaminen
 *
 * Esimerkki:
 *   Font fontti("Fontin_nimi.ttf", 13);
 */

#ifndef __FONT_H_DEFINED__
#define __FONT_H_DEFINED__

// Includet
#include "SDL.h"
#include <string>

class Font {
	public:
		// Constructor overloading
		Font();
		Font(std::string fontName, int fontSize);

		~Font();

		bool loadFromFile(std::string fontName, int fontSize);
		TTF_Font *getFont();

	private:
		TTF_Font *font;
};

#endif