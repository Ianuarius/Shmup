#include "statemanager.h"
#include "window.h"
#include "sdl.h"

int main(int argc,  char* argv[])
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL::init();
	Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Escape From Earth");
	// StateManager stateManager(&window);

	// stateManager.run();

	SDL_Rect *gameArea;

	gameArea->x = 0;
	gameArea->y = 0;
	gameArea->w = window.getWidth();
	gameArea->h = window.getHeight();


	SDL_Texture *testikuva = window.loadFromFile("..//..//graphics//testpic.png");
	window.renderImage(testikuva, gameArea);
	window.clear();
	window.refresh();

	SDL_Delay(4000);
	SDL::exit();
	return 0;
}