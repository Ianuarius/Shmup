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
#include "Level.h"
#include "Animation.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();
	
	bool inGame = true;

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);

	// SDL_Texture* tekstuuri = NULL;
	// tekstuuri = window.loadImage("testpic.png");
	Sprite sprite(&window, "pengsheet.png", 16, 16);
	// Animation hahmo(&window, &sprite, 0, 48, 0);

	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Level level(&window);
	level.loadLevel("level00.tmx");
	
	while(inGame) {
		Input::update();

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			inGame = false;
		}

		if (Input::keyState(SDL_SCANCODE_LEFT))
		{
			// Move camera left
			camera.x = camera.x - 10;

			if (camera.x < 0)
			{
				camera.x = 0;
			}
		}
		
		if (Input::keyState(SDL_SCANCODE_RIGHT))
		{
			// Move camera right
			camera.x = camera.x + 10;

			if (camera.x > level.getLevelWidth())
			{
				camera.x = level.getLevelWidth();
			}
		}

		if (Input::keyState(SDL_SCANCODE_M)) {
			window.minimize();
		}

		if (Input::keyState(SDL_SCANCODE_N)) {
			window.maximize();
		}

		// window.clear();

		// hahmo.render(100, 100);
		SDL_Delay(50);

		// window.render(tekstuuri, 200, 200, &nelio);
		level.renderLevel(&camera);

		window.refresh();
	}

	// window.freeImage(tekstuuri);

	//Destroy window
	window.destroy();
	


	//Quit SDL subsystems
	SDL::exit();

	return 0;
}