/*
 * Projectile.cpp
 *
 */

#include "Projectile.h"

Projectile::Projectile(Window *window, int type, int x, int y, int radian)
{
	// Initial X and Yk
	entity.setX(x);
	entity.setY(y);
	entity.speed(20);
}

Projectile::~Projectile()
{}

void Projectile::update()
{
	int vx = entity.getSpeed() * cos(radian);
	int vy = entity.getSpeed() * sin(radian);

	entity.setX(x + vx);
	entity.setY(y + vy);
}

void Projectile::render()
{
	entity.render();
}