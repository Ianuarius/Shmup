#include "window.h"

Window::Window(int width, int height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	originalWidth(width),
	originalHeight(height),
	isFullscreen(false),
	title(title),
	frameCount(0)
{
	//Resizen ekalla kerralla kutsu luo ikkunan
	//Tallennetaan se ikkuna-muuttujaan
	bool fullscreen = true;
	resize(width, height, title, fullscreen);

	if (!this->window || !this->renderer)
	{
		printf("Ei pysty, ikkunaa tai renderöijää ei nyt voi luoda!");
	}
	/*
	frameTicks.start();
	framerateTimer.start();
	*/
	clear();
	refresh();

	SDL_Delay(10);
}

Window::~Window()
{
	if(renderer)
	{
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	if(window)
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}

// NOTE(juha): Pitää vielä katella, että miksi tämä oli taas tässä.
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

void Window::resize(int width, int height, std::string title, bool fullscreen)
{
	// NOTE(juha): Tuhotaan ikkuna ennen kuin se luodaan uudestaan
	destroy();
	
	// NOTE(juha): Nearest neighbour renderöinti, eli skaalatut pikselit terävinä
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);

	if(!window || !renderer) {
		printf("Ei pysty, ikkunaa tai renderöijää ei nyt voi luoda, stna!");
		return;
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if(((IMG_Init(imgFlags) & imgFlags) == NULL))
	{
		printf("SDL_image ei lähteny pyöriin! SDL_image Error: %s\n", IMG_GetError());
	}

	// NOTE(juha): Pelin resoluutio 256x240
	SDL_RenderSetLogicalSize(renderer, this->width, this->height);

	surface = SDL_GetWindowSurface(window);

	if(!surface)
	{
		printf("Surfacea ei saatu!");
		return;
	}

	//Aseta nimi
	// setTitle(title);

	this->width = width;
	this->height = height;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}

/*
void Window::setTitle(std::string title)
{
	if(window)
	{
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}
*/

void Window::refresh()
{
	SDL_RenderPresent(renderer);
	++frameCount;
}

void Window::clear()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}

bool Window::toggleFullscreen()
{
	// WIP
	return true;
}
/* NOTE(juha): Kommentoidaan tässä vaiheessa pois, että saadaan renderöinti eka pelittään.
int Window::getFramerate()
{
	int framerate = frameCount / (framerateTimer.getTicks() / 1000);

	if(framerate > 2000000)
	{
		return 0;
	}

	return framerate;
}

void Window::capFramerate(Uint32 framerate)
{
	Uint32 ticks = frameTicks.getTicks();

	if(ticks < (1000 / framerate))
	{
		SDL_Delay((1000 / framerate) - ticks);
	}

	frameTicks.start();
}

int Window::getDelta()
{
	return frameTicks.getTicks();
}
*/
void Window::drawRect(int X, int Y, int W, int H, Color color)
{
	SDL_Rect fillRect = { X, Y, W, H };
	SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), color.a());
	SDL_RenderFillRect(renderer, &fillRect );
}

SDL_Texture *Window::loadFromFile(std::string path)
{
	SDL_Texture *newTexture = IMG_LoadTexture(this->renderer, path.c_str());

    if(newTexture = NULL)
    {
		printf("Ei voinu ladata tekstuuria!");
	    // loggausta
    }

    return newTexture;

	/*if(!loadedSurface)
	{
		return false;
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0, 0xFF));

	newTexture = SDL_CreateTextureFromSurface()*/
}

void Window::renderImage(SDL_Texture *sourceTexture, SDL_Rect *destRect)
{
	if (!sourceTexture || !destRect)
	{
		// Ei pysty!
		return;
	}
	
	SDL_Rect sdl_destination =
	{
		(int)destRect->x,
		(int)destRect->y,
		destRect->w,
		destRect->h
	};

    SDL_RenderCopy(this->renderer,
                   sourceTexture,
                   &sdl_source,
                   &sdl_destination);
}