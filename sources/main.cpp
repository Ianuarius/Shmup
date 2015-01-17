#include "sdl.h"
#include <stdio.h>
#include <string>
#include "window.h"
#include "statemanager.h"

int main( int argc, char* args[] )
{
	int width = 256;
	int height = 240;
	Window window(width, height, "Escape From Earth");

	StateManager manager(&window);

	manager.run();

	SDL::exit();
	return 0;
}