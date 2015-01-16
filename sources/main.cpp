#include "statemanager.h"
#include "window.h"
#include "sdl.h"

int main(int argc,  char* argv[])
{
	SDL::init();
	Window window(640, 480, "Escape From Earth");
	// StateManager stateManager(&window);

	// stateManager.run();

	SDL_Rect *gameArea;

	gameArea->x = 0;
	gameArea->y = 0;
	gameArea->w = window.getWidth();
	gameArea->h = window.getHeight();


	SDL_Texture *testikuva = window.loadFromFile("..//..//graphics//example_image.png");
	window.renderImage(testikuva, , gameArea);

	SDL_Delay(4000);
	SDL::exit();
	return 0;
}