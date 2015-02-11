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
#include "Camera.h"
#include "HUD.h"

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

	// SDL_Texture* tekstuuri = NULL;
	// tekstuuri = window.loadImage("testpic.png");
	Sprite sprite(&window, "pengsheet.png", 16, 16);
	Sprite alus(&window, "player_spritesheet.png", 32, 32);
	Sprite ammus(&window, "ammus.png", 5, 5);
	
	SDL_Rect hitbox = {2, 2, 28, 28};
	SDL_Rect ammus_hb = {0, 0, 5, 5};

	int hfr = 2;
	Animation hahmo(&window, &alus, 0, 4, hfr);
	MovingEntity pelaaja(&hahmo, hitbox);

	DamageableEntity vihollinen(&alus, hitbox, 100);
	Projectile proj(&ammus, ammus_hb, 2, 0);

	HUD hud(&window);

	Level level(&window);
	level.loadLevel("level00.tmx");
	
	// Liikkumisnopeus
	int mSpeed = 3;

	while(love) {
		Input::update();

		if (pelaaja.collides(&level) == SDL_TRUE) {
			printf("BOOM!");
		}

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			love = false;
		}

		if (Input::keyState(SDL_SCANCODE_LEFT))
		{
			pelaaja.move(-mSpeed, 0);
		}
		
		if (Input::keyState(SDL_SCANCODE_RIGHT))
		{
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

		if (Input::keyState(SDL_SCANCODE_A))
		{
			hahmo.setFramerate(hfr++);
		}

		if (Input::keyState(SDL_SCANCODE_S))
		{
			if (hfr <= 0) hfr = 0;
			hahmo.setFramerate(hfr--);
		}

		window.clear();

		// hahmo.render(100, 100);

		// window.render(tekstuuri, 200, 200, &nelio);
		level.renderLevel();
		pelaaja.render();
		hud.render();

		window.refresh();
	}

	// window.freeImage(tekstuuri);

	//Destroy window
	window.destroy();

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}