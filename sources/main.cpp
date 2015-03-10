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
		// Refresh input
		Input::update();
		level.update();
		enemies.update();
		player.update();
		projectiles.update();

		if (level.collides(&(player))) {
			player.damage(10);
		}

		// Player collides to enemies?
		// TODO(jouni): Change fors to iterators
		for (int i = 0; i < enemies.length(); i++) {
			Enemy *tmp = enemies.get(i);
			if (player.collides(tmp)) {
				if (!player.isImmune() && !tmp->isDead()) {
					player.damage(1);
					player.immunity(1500);
				}
			}
		}

		// Player collides to projectiles
		// TODO(jouni): Change fors to iterators
		for (int i = 0; i < projectiles.length(); i++) {
			Projectile *tmp = projectiles.get(i);
			if (player.collides(tmp)) {
				if (!player.isImmune()) {
					player.damage(1);
					player.immunity(1500);
				}
			}
		}

		// Enemies collide to projectiles
		// TODO(jouni): Change fors to iterators
		for (int i = 0; i < projectiles.length(); i++) {
			Projectile *tmp = projectiles.get(i);
			for (int j = 0; j < enemies.length(); j++) {
				Enemy *enemy = enemies.get(j);

				if (enemy->collides(tmp) && !enemy->isDead()) {
					enemy->damage(1);
					projectiles.removeAt(i);
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