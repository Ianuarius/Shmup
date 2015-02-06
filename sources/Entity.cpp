/*
 * Entity.cpp
 *
 */

#include "entity.h"

Entity::Entity(Sprite *sprite, SDL_Rect hitbox, int x, int y):
	sprite(sprite),
	x(x),
	y(y),
	hitbox(hitbox)
{

}

Entity::~Entity()
{

}

void Entity::render()
{
	sprite->render(0, x, y);
}


int Entity::getX()
{
	return x; 
}

int Entity::getY()
{
	return y;
}