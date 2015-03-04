/*
	SDL Template

	This should compile.
*/

//Using SDL and standard IO
#include "SDL.h"
#include "Window.h"
#include "Level.h"
#include "Input.h"
#include "Texture.h"
#include "EntityCollection.h"
#include "EnemyFactory.h"
#include "Player.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);
	EntityCollection<Enemy> entity_bag;
	EnemyFactory factory(&window);

	Level level(&window, &entity_bag, &factory);
	level.load("level_city_vol_01.tmx");

	Player player(&window);
	
	while(!Input::keyState(SDL_SCANCODE_ESCAPE)) {
		// Refresh input
		Input::update();
		level.update();
		entity_bag.update();
		player.update();

		// Clear sceen
		window.clear();
		
		level.render();
		entity_bag.render();
		player.render();

		// Draw renderer contents and delay frame if needed
		window.refresh();

	}


	//Quit SDL subsystems
	SDL::exit();

	return 0;
}