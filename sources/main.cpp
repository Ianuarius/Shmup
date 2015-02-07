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
#include "MovingEntity.h"
#include "DamageableEntity.h"
#include "Projectile.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();
	
	bool love = true;
	bool moveCamera = true;

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);
	SDL_Texture *background = window.loadImage("kaupunki_tausta.png");

	// SDL_Texture* tekstuuri = NULL;
	// tekstuuri = window.loadImage("testpic.png");
	Sprite sprite(&window, "pengsheet.png", 16, 16);
	Sprite alus(&window, "alus.png", 50, 50);
	Sprite ammus(&window, "ammus.png", 5, 5);
	
	SDL_Rect hitbox = {0, 0, 10, 10};
	SDL_Rect ammus_hb = {0, 0, 5, 5};
	MovingEntity pelaaja(&alus, hitbox);
	DamageableEntity vihollinen(&alus, hitbox, 100);
	Projectile proj(&ammus, ammus_hb, 2, 0);
	// Animation hahmo(&window, &sprite, 0, 48, 0);

	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	Level level(&window);
	level.loadLevel("level00.tmx");
	
	// Liikkumisnopeus
	int mSpeed = 3;

	while(love) {
		Input::update();

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			love = false;
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
			pelaaja.move(-mSpeed, 0);
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
			pelaaja.move(mSpeed, 0);
		}

		if (Input::keyState(SDL_SCANCODE_UP))
		{
			pelaaja.move(0, -mSpeed);
		}

		if (Input::keyState(SDL_SCANCODE_DOWN))
		{
			pelaaja.move(0, mSpeed);
		}

		window.clear();

		// hahmo.render(100, 100);

		// window.render(tekstuuri, 200, 200, &nelio);
		window.render(background, 0, 0);
		level.renderLevel(&camera);
		pelaaja.render();
		vihollinen.render();
		proj.render();

		if (pelaaja.collides(&level) == SDL_TRUE) {
			printf("BOOM!");
		}
		
		if (moveCamera == true)	{
			camera.x += 2;	
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