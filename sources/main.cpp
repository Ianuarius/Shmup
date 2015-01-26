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
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL::init();
	
	bool inGame = true;

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);

	// SDL_Texture* tekstuuri = NULL;
	// tekstuuri = window.loadImage("testpic.png");
	Sprite sprite(&window, "zospritesheet.png", 34, 34);
	Animation hahmo(&window, &sprite, 0, 48, 5);

	Level level(&window);
	level.loadLevel("spaceTest.tmx");

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

		hahmo.render(100, 100);
		printf("FPS: %d\n", window.getFramerate());

		window.refresh();
	}

	//Destroy window
	window.destroy();

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}