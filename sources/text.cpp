/*
 * Text.cpp
 *
 */

// Includetaan vain luokan header-tiedosto
#include "text.h"

Text::Text():
	texture(nullptr)
{
	this->color = Color("white");
}

Text::~Text()
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void Text::setFont(Font *font)
{
	this->font = font;
}

void Text::setColor(Color color)
{
	this->color = color;
}

void Text::print(Window *window, std::string text)
{
	// Get rid of pre-existing texture
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}

	// Get current font settings
	TTF_Font *primary_font = font->getFont();

	// Get color in SDL_Color
	SDL_Color font_color = {color.r(),
							color.g(),
							color.b(),
							color.a()};

	SDL_Surface* text_surface = TTF_RenderText_Solid(primary_font,
													text.c_str(),
													font_color);

	if (text_surface) {
		SDL_Renderer* renderer = window->getRenderer();
		texture = SDL_CreateTextureFromSurface(renderer, text_surface);

		window->renderImage(texture, 10, 10);
	} else {
		printf("Ei voitu tulostaa tekstiä! SDL_Error: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(text_surface);
}