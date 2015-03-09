#include "Window.h"

Window::Window(int width, int height, std::string title, bool fullscreen):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	originalWidth(width),
	originalHeight(height),
	current_delta(0)
{
	resize(title, width, height, fullscreen);

	frametimeTimer.start();
	fpsTimer.start();

	current_delta = frametimeTimer.getTicks();

	clear();
	refresh();
}

Window::~Window()
{
	destroy();
}

void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

void Window::resize(std::string title, int width, int height, bool fullscreen)
{
	destroy();

	Uint32 window_flag; 

	if (fullscreen)
	{
		window_flag = SDL_WINDOW_FULLSCREEN;
	} else {
		window_flag = SDL_WINDOW_SHOWN;
	}

	SDL_CreateWindowAndRenderer(width, height, window_flag, &window, &renderer);
	
	// NOTE(jouni): Perus virhetarkistusta; jos window tai renderer ei ssaa arvoa,
	// ei anneta ohjelman vaan raa'asti kaatua vaan ilmotetaan siitä käyttäjälle.
	if (!window || !renderer)
	{
		printf("SDL_Window tai SDL_Renderer ei pelaa!\n");
		return;
	}
	
	// Nearest-neighbour resize
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	SDL_RenderSetLogicalSize(renderer, 256, 240);

	// Asetetaan title
	setTitle(title);

	surface = SDL_GetWindowSurface(window);
	if (!surface)
	{
		printf("SDL_GetWindowSurface failas!\n");
		return;
	}

	this->width = width;
	this->height = height;
}

void Window::clear()
{
	fill(Color("black"));
}

void Window::fill(Color color)
{
	SDL_SetRenderDrawColor(renderer,
						   color.r(),
						   color.g(),
						   color.b(),
						   color.a());

	SDL_RenderClear(renderer);
}

void Window::refresh()
{
	SDL_RenderPresent(renderer);

	fps_current++;
	
	int ticks = frametimeTimer.getTicks();

	if (ticks < (1000 / FRAMERATE)) {
		SDL_Delay((1000 / FRAMERATE) - ticks);
	}

	current_delta = frametimeTimer.getTicks();
	frametimeTimer.start();
}

void Window::drawRect(int X, int Y, int W, int H, Color color)
{
	SDL_Rect fillRect = { X, Y, W, H };
	SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), color.a());
	SDL_RenderFillRect(renderer, &fillRect );
}

void Window::setTitle(std::string title)
{
	if (window)
	{
		SDL_SetWindowTitle(window, title.c_str());
	}
}

void Window::minimize() 
{
	if (window)
	{
		SDL_MinimizeWindow(window);
	}
}

void Window::maximize()
{
	if (window)
	{
		SDL_MaximizeWindow(window);
	}
}

void Window::restore()
{
	SDL_RestoreWindow(this->window);
}

SDL_Renderer* Window::getRenderer() 
{
	return renderer;
}

Uint32 Window::getDelta()
{
	return current_delta;
}

int Window::getFramerate()
{
	if (fpsTimer.getTicks() >= FPS_INTERVAL) {
		fps = fps_current;
		fps_current = 0;
		fpsTimer.start();
	}

	return fps;
}