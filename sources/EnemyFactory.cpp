#include "EnemyFactory.h"

EnemyFactory::EnemyFactory(Window *window):
	window(window)
{
	// Drone definition
	drone.animation = new Animation(window, "drone.png", 16, 9, 0, 1, 1);
	drone.hitbox.w  = 16;
	drone.hitbox.h  = 9;
	drone.hitpoints = 1;
	// Jet definition
	jet.animation = new Animation(window, "kaupunki_fighter_jet.png", 32, 14, 0, 3, 2);
	jet.hitbox.w = 32;
	jet.hitbox.h = 14;
	jet.hitpoints = 1;
}

EnemyFactory::~EnemyFactory() {}

Enemy EnemyFactory::spawn(int type, int spawnHeight) {
	switch (type)
	{
		case DRONE:
			return Enemy(drone.animation, drone.hitbox, drone.hitpoints);
			break;

		case JET:
			return Enemy(jet.animation, jet.hitbox, jet.hitpoints);
			break;

		default:
			break;
	}
}