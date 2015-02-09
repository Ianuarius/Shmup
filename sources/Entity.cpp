/*
 * Entity.cpp
 *
 */

#include "entity.h"

Entity::Entity(Sprite *sprite, SDL_Rect hitbox, int x, int y):
	sprite(sprite),
	x(x),
	y(y),
	hitbox(hitbox),
	frame(0),
	anime(nullptr)
{

}

Entity::Entity(Animation *animation, SDL_Rect hitbox, int x, int y):
	x(x),
	y(y),
	hitbox(hitbox),
	anime(animation)
{
	sprite = animation->animated;
	frame = animation->getFrame();
}

Entity::~Entity()
{

}

void Entity::render()
{
	frame = anime->getFrame();
	sprite->render(frame, x, y);
}


int Entity::getX()
{
	return x; 
}

int Entity::getY()
{
	return y;
}