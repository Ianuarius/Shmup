/*
 * Projectile.cpp
 *
 */

#include "Projectile.h"

SDL_Rect Projectile::hitbox = {1, 1, 2, 2};

Projectile::Projectile(Texture *texture, int speed, int x, int y, int radian) :
	MovingEntity(texture, hitbox),
	vx(0),
	vy(0),
	radian(radian)
{
	MovingEntity::speed(speed);
	setX(x);
	setY(y);
	MovingEntity::hitbox.x = x;
	MovingEntity::hitbox.y = y;
}

Projectile::~Projectile()
{}

void Projectile::update()
{
	int vx = getSpeed() * cos(radian);
	int vy = getSpeed() * sin(radian);

	//printf("velocity:\tx%d y%d\n", vx, vy);

	setX(getX() + vx);
	setY(getY() + vy);
	MovingEntity::hitbox.x = getX();
	MovingEntity::hitbox.y = getY();

	//printf("new point:\tx%d y%d\n", getX(), getY());

}

void Projectile::render()
{
	MovingEntity::render();
}