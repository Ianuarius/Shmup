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
#include "Entity.h"

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
	Sprite alus(&window, "alus.png", 50, 50);
	
	SDL_Rect hitbox = {0, 0, 10, 10};
	Entity pelaaja(&alus, hitbox);
	Entity vihollinen(&alus, hitbox);
	// Animation hahmo(&window, &sprite, 0, 48, 0);

	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Level level(&window);
	level.loadLevel("level00.tmx");
	
	vihollinen.update(100, 100);
	
	// Liikkumisnopeus
	int mSpeed = 4;


	while(inGame) {
		Input::update();

		printf("%d\n", level.getTile(pelaaja.getX(),pelaaja.getY()));

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			inGame = false;
		}

		

		if (Input::keyState(SDL_SCANCODE_LEFT))
		{
			/*
			// Move camera left
			camera.x = camera.x - 2;

			if (camera.x < 0)
			{
				camera.x = 0;
			}
			*/
			pelaaja.update(-mSpeed, 0);
		}
		
		if (Input::keyState(SDL_SCANCODE_RIGHT))
		{
			/*
			// Move camera right
			camera.x = camera.x + 2;

			if (camera.x > level.getLevelWidth())
			{
				camera.x = level.getLevelWidth();
			}
			*/
			pelaaja.update(mSpeed, 0);
		}

		if (Input::keyState(SDL_SCANCODE_UP))
		{
			pelaaja.update(0, -mSpeed);
		}

		if (Input::keyState(SDL_SCANCODE_DOWN))
		{
			pelaaja.update(0, mSpeed);
		}

		window.clear();

		// hahmo.render(100, 100);

		// window.render(tekstuuri, 200, 200, &nelio);
		level.renderLevel(&camera);
		pelaaja.render();
		vihollinen.render();

		if (pelaaja.collides(&level) == SDL_TRUE) {
			printf("BOOM!");
		}

		window.refresh();
	}

	// window.freeImage(tekstuuri);

	//Destroy window
	window.destroy();

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}