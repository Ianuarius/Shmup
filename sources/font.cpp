#include "Font.h"

Font::Font():
	font(nullptr)
{ }

Font::Font(std::string fontName, int fontSize) {
	loadFromFile(fontName, fontSize);
}

Font::~Font() {
	TTF_CloseFont(font);
}

bool Font::loadFromFile(std::string fontName, int fontSize) {
	font = TTF_OpenFont(fontName.c_str(), fontSize);

	if (!font) {
		printf("Couldn't load font! %s\n", TTF_GetError());
		return false;
	}

	return true;
}

TTF_Font* Font::getFont() {
	return font;
}