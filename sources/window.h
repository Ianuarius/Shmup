#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.h"
#include "color.h"

class Window
{
public:
	// Constructor
	Window(int width, int height, std::string title, bool fullscreen);
	
	// Destructor & destroy()
	virtual ~Window();
	void destroy();

	void resize(std::string title, int width, int height, bool fullscreen = false);
	void refresh();
	void clear();

	void setTitle(std::string title);

	void minimize();
	void maximize();
	void restore();

	SDL_Texture* loadImage(std::string filename);

	// source = Alkuper�isest� kuvasta leikatun alueen sijanti ja koko
	void renderImage(SDL_Texture* texture, int x, int y, SDL_Rect* source = NULL);
	void freeImage(SDL_Texture *image);
	void freeImage(SDL_Surface *image);

	void drawRect(int X, int Y, int W, int H, Color color);
	void fill(Color color);

	unsigned int width; 
	unsigned int height; 
	unsigned int originalWidth;
	unsigned int originalHeight;
	
	//The actual hardware texture
	SDL_Texture* texture;

private:
	SDL_Window *window;
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	
};

#endif //__WINDOW_H_DEFINED__