#include "statemanager.h"
#include "window.h"
#include "sdl.h"

int main(int argc,  char* argv[])
{
	SDL::init();
	Window window;
	StateManager stateManager(&window);

	stateManager.run();

	SDL::exit();
	return 0;
}