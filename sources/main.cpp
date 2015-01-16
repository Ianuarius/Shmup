#include "statemanager.h"
#include "window.h"
#include "sdl.h"

int main(int argc,  char* argv[])
{
	SDL::init();
	Window window(640, 480, "Escape From Earth");
	// StateManager stateManager(&window);

	// stateManager.run();

	SDL::exit();
	return 0;
}