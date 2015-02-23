/*
	SDL Template

	This should compile.
*/

//Using SDL and standard IO
#include <stdio.h>
#include "SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Sprite.h"
#include "Input.h"
#include "MovingEntity.h"
#include "Animation.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "AI.h"
#include "Projectile.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();

	bool love = true;
	SDL_Rect hb2 = {0, 0, 10, 10};

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);
	Animation valas(&window, "boss_alus.png", 175, 81, 0, 1, 2);

	Player pelaaja(&window); 
	Enemy vihulainen(&valas, hb2, 10);
	vihulainen.speed(1);

	AI aivot(&vihulainen);
	aivot.sinePattern();

	Texture background(&window, "kaupunki_tausta.png");
	Texture ammusimage(&window, "ammus.png");

	Level level(&window);
	level.loadLevel("level00.tmx");

	Projectile projectilebag(&window);

	while (love) {
		Input::update();
		pelaaja.update();
		aivot.update();
		projectilebag.update();

		if (Input::keyState(SDL_SCANCODE_ESCAPE)) {
			love = false;
		}

		if (Input::keyState(SDL_SCANCODE_SPACE)) {
			projectilebag.spawn(0, pelaaja.getX()+3, pelaaja.getY()+16, 90);
		}

		window.clear();

		// Level and other stuff
		level.renderLevel();

		// Render entities
		pelaaja.render();
		vihulainen.render();
		projectilebag.render();

		window.refresh();
	}

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}