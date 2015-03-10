/**
 * EntityFactory.h
 * 
 */

#ifndef __ENEMYFACTORY_H_DEFINED__
#define __ENEMYFACTORY_H_DEFINED__

#include "Window.h"
#include "Animation.h"
#include "Enemy.h"
#include "EntityCollection.h"
#include "Projectile.h"

#define DRONE  1
#define JET    2

class EnemyFactory {

	public:
		// Spawns enemies
		EnemyFactory(Window *window, EntityCollection<Projectile> *projectiles);
		~EnemyFactory();
		Enemy spawn(int type, int spawnHeight);

	private:
		Window *window;
		EntityCollection<Projectile> *projectiles;

		struct enemy_definition {
			Animation *animation;
			Animation *dying;
			SDL_Rect   hitbox;
			int		   hitpoints;

			enemy_definition() {
				animation = nullptr;
				dying = nullptr;
				SDL_RectEmpty(&hitbox);
				hitpoints = 0;
			}

		} drone, jet;
};

#endif