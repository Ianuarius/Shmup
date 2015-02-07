/*
 * Projectile.cpp
 *
 */

#include "Projectile.h"

Projectile::Projectile(Sprite *sprite, SDL_Rect hitbox, int speed, int angle):
	MovingEntity(sprite, hitbox),
	speed(speed),
	angle(angle)
{
	
}

Projectile::~Projectile()
{

}

void Projectile::render()
{
	move(x+speed, y);
}