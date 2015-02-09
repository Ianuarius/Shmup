/*
 * DamageableEntity.cpp
 *
 */

#include "DamageableEntity.h"

DamageableEntity::DamageableEntity(Sprite *sprite, SDL_Rect hitbox, int initialHitPoints):
	Entity(sprite, hitbox, 100, 100),
	alive(true),
	hitpoints(initialHitPoints)
{
}

DamageableEntity::DamageableEntity(Animation *animation, SDL_Rect hitbox, int initialHitPoints):
	Entity(sprite, hitbox, 100, 100),
	alive(true),
	hitpoints(initialHitPoints)
{
}

DamageableEntity::~DamageableEntity()
{
}

void DamageableEntity::heal(int amount)
{
	hitpoints += amount;
}

void DamageableEntity::damage(int amount)
{
	hitpoints -= amount;

	if (hitpoints <= 0)
	{
		hitpoints = 0;
		alive = false;
	}
}

bool DamageableEntity::isDead()
{
	if (alive == true)
	{
		return false;
	}

	return true;
}

int DamageableEntity::getHitpoints()
{
	return hitpoints;
}