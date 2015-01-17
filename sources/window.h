#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.h"
#include "color.h"

class Window
{
public:
	Window(int width, int height, std::string title);
	virtual ~Window();
	void destroy();

	void renderImage(SDL_Texture *texture, SDL_Rect *source, SDL_Rect *destination);

	SDL_Texture *loadImage(std::string filename);
	void clear();
	void fill(Color color);
	void refresh();
	void resize(std::string title, int width, int height);
	void freeImage(SDL_Texture *image);
	void freeImage(SDL_Surface *image);
	void drawRect(int X, int Y, int W, int H, Color color);

	unsigned int width; 
	unsigned int height; 
	unsigned int originalWidth;
	unsigned int originalHeight;

private:
	SDL_Window *window;
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	
};

#endif //__WINDOW_H_DEFINED__