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
#include "Projectile.h"
#include "HUD.h"

//Screen dimension constants
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

int main(int argc, char* args[])
{
	SDL::init();

	//The window we'll be rendering to
	Window window(1280, 720, "Escape From Earth", false);

	EntityCollection<Enemy> enemies;
	EntityCollection<Projectile> projectiles;
	EnemyFactory factory(&window, &projectiles);

	Level level(&window, &enemies, &factory);
	level.load("level_city_vol_01.tmx");

	HUD hud(&window);
	Player player(&window, &hud, &projectiles);

	while(!Input::keyState(SDL_SCANCODE_ESCAPE)) {
		if (player.isDead()) {

		}
		// Refresh input
		Input::update();
		level.update();
		enemies.update();
		player.update();
		projectiles.update();

		// Player collides to enemies?
		for (int i = 0; i < enemies.length(); i++)
		{
			Enemy *tmp = enemies.get(i);
			if (player.collides(tmp)) {
				if (!player.isImmune()) {
					player.damage(1);
					player.immunity(1500);
				}
			}
		}

		// Clear sceen
		window.clear();
		
		level.render();
		enemies.render();
		player.render();
		hud.render();
		projectiles.render();

		// Draw renderer contents and delay frame if needed
		window.refresh();
	}

	//Quit SDL subsystems
	SDL::exit();

	return 0;
}