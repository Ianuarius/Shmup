/*
	SDL Template

	This should compile.
*/

//Using SDL and standard IO
#include <stdio.h>
#include "SDL.h"
#include "Input.h"
#include "Font.h"
#include "window.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL::init();
	
	bool inGame = true;

	//The window we'll be rendering to
	Window window(800, 600, "Testi!", false);

	SDL_Texture* tekstuuri = NULL;
	tekstuuri = window.loadImage("testpic.png");

	SDL_Rect nelio = {64, 64, 50, 50};

	while(inGame) {
		Input::update();

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			inGame = false;
		}

		if (Input::keyState(SDL_SCANCODE_M)) {
			window.minimize();
		}

		if (Input::keyState(SDL_SCANCODE_N)) {
			window.maximize();
		}

		window.clear();

		window.renderImage(tekstuuri, 200, 200, &nelio);

		window.refresh();
	}

	window.freeImage(tekstuuri);

	//Destroy window
	window.destroy();
	

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}