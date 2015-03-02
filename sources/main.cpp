/*
	SDL Template

	This should compile.
*/

//Using SDL and standard IO
#include "SDL.h"
#include "Window.h"
#include "Input.h"
#include "Texture.h"
#include "Entity.h"
#include "MovingEntity.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);
	//Level level(&window);
	//level.loadLevel("level_city_vol_01.tmx");

	SDL_Rect hitbox = {0, 0, 10, 10};
	Texture tekstuuri(&window, "ammus.png");
	MovingEntity entitetti(&tekstuuri, hitbox);

	while(!Input::keyState(SDL_SCANCODE_ESCAPE)) {
		// Refresh input
		Input::update();

		// Clear sceen
		window.clear();

		// Render all the things
		entitetti.render();
		//level.renderLevel();

		// Draw renderer contents and delay frame if needed
		window.refresh();
	}


	//Quit SDL subsystems
	SDL::exit();

	return 0;
}