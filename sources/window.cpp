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
	resize(width, height, title);

	if (!this->window || !this->renderer) {
		printf("Ei pysty, ikkunaa tai renderöijää ei nyt voi luoda!");
	}

	frameTicks.start();
	framerateTimer.start();

	clear();
	refresh();

	SDL_Delay(10);
}

Window::~Window() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}

void Window::resize(int width, int height, std:.string title) {
	destroy();

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);

	if (!window || !renderer) {
		printf("Ei pysty, ikkunaa tai renderöijää ei nyt voi luoda, stna!");
		return;
	}

	//Nearest neighbour rendering
	SDL_SetHInt(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	SDL_RenderSetLogicalSize(this->renderer, 256, 240);

	surface = SDL_GetWindowSurface(window);

	if(!surface) {
		printf("Surfacea ei saatu!");
		return;
	}

	//Aseta nimi
	setTitle(title);

	this->width = width;
	this->height = height;
}

int Window::getWidth() {
	return width;
}

int Window::getHeight() {
	return height;
}

void Window::setTitle(std::string title) {
	if (window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}

void Window::refresh()
{
	SDL_RenderPresent(renderer);
	++frameCount;
}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}

bool Window::toggleFullscreen() {
	// WIP
	return true;
}

int Window::getFramerate() {
	int framerate = frameCount / (framerateTimer.getTicks() / 1000);

	if (framerate > 2000000) {
		return 0;
	}

	return framerate;
}

void Window::capFramerate(Uint32 framerate) {
	Uint32 ticks = frameTicks.getTicks();

	if (ticks < (1000 / framerate)) {
		SDL_Delay((1000 / framerate) - ticks);
	}

	frameTicks.start();
}

int Window::getDelta() {
	return frameTicks.getTicks();
}

void Window::drawRect(int X, int Y, int W, int H, Color color) {
	SDL_Rect fillRect = { X, Y, W, H };
	SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), color.a());
	SDL_RenderFillRect(renderer, &fillRect );
}

Texture* Window::loadTexture(std::string path) {
	//sourceTexture->setRenderer(renderer);
	//sourceTexture->loadFromFile(path);
	
	// The final texture
	SDL_Texture *newTexture = NULL;
	Texture *finalTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	if (!loadedSurface) {
		printf("Unable to load image %s! SDL_image error: %s\n", path.c_str(), IMG_GetError());
	} else {
		// Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0, 0xFF));

		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if (!newTexture) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		} else {
			finalTexture->mWidth = loadedSurface->w;
			finalTexture->mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	finalTexture->mTexture = newTexture;

	return finalTexture;
}

void Window::render(Texture *sourceTexture, SDL_Rect *destRect, int x, int y) {
	sourceTexture->setRenderer(renderer);
	sourceTexture->render(x, y, destRect, 0, NULL, SDL_FLIP_NONE);
}
