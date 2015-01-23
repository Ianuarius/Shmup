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
#include "Sprite.h"
#include "Level.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL::init();
	
	bool inGame = true;

	//The window we'll be rendering to
	Window window(800, 600, "Testi!", false);

	//SDL_Texture* tekstuuri = NULL;
	//tekstuuri = window.loadImage("testpic.png");
	Sprite sprite(&window, "tmw_desert_spacing16.png", 16, 16);

	int integerofdoom = 0;

	//SDL_Rect nelio = {64, 64, 50, 50};

	while(inGame) {
		Input::update();
		integerofdoom++;
		printf("index: %d\n", integerofdoom);

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

		//window.render(tekstuuri, 200, 200, &nelio);
		sprite.render(integerofdoom, 40, 40);

		// SÄÄSTELLÄÄN VÄHÄN RESURSSEJAJA
		SDL_Delay(500);

		window.refresh();
	}

	//window.freeImage(tekstuuri);

	//Destroy window
	window.destroy();
	

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}